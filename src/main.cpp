#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <nlohmann/json.hpp>
#include <fstream>

#include <vector>
#include <memory>
#include <algorithm>
#include "element.h"

#include "pipe.h"
#include "local.h"
#include "json.h"

double getPressure(std::vector<std::unique_ptr<Element>> &vec) {
    auto it = std::find_if(vec.begin(), vec.end(), [](const std::unique_ptr<Element>& obj) {
        return obj->getID()[0] == "NONE";});
    rotate(vec.begin(), it, it + 1);
//        fmt::print("\n{}", "rotate");
    return vec[std::distance(vec.begin(), it)]->getProperties()[0];
}

double getFlow(std::vector<std::unique_ptr<Element>> &vec) {
    auto it = std::find_if(vec.begin(), vec.end(), [](const std::unique_ptr<Element>& obj) {
        return obj->getID()[2] == "NONE";});
    rotate(it, it + 1, vec.end());
//        fmt::print("\n{}", "rotate");
    return vec[std::distance(vec.begin(), it)]->getProperties()[0];
}

Element& start(std::vector<std::unique_ptr<Element>> &vec){
    auto it = std::find_if(vec.begin(), vec.end(), [](const std::unique_ptr<Element>& obj) {
        return obj->getID()[0] == "NONE";});
    return **it;
}

void first(std::vector<std::unique_ptr<Element>>& vec){
    if (vec[0]->getID()[0] != "NONE"){
        auto it = std::find_if(vec.begin(), vec.end(), [](const std::unique_ptr<Element>& obj) {
            return obj->getID()[0] == "NONE";});
        rotate(vec.begin(), it, it + 1);
//        fmt::print("\n{}", "rotate");
    }
}

void last(std::vector<std::unique_ptr<Element>>& vec){
    if (vec[vec.size()-1]->getID()[2] != "NONE"){
        auto it = std::find_if(vec.begin(), vec.end(), [](const std::unique_ptr<Element>& obj) {
            return obj->getID()[2] == "NONE";});
        rotate(it, it + 1, vec.end());
//        fmt::print("\n{}", "rotate");
    }
}

Element& downstream(Element& el, std::vector<std::unique_ptr<Element>> &vec){
    auto it = std::find_if(vec.begin(), vec.end(), [&vec, &el](const std::unique_ptr<Element> &obj) {
        return el.getID()[2] == obj->getID()[1];});
    return **it;
}

void sort(std::vector<std::unique_ptr<Element>>& vec){
    for (size_t i = 0; i < vec.size()-1; ++i) {
        if (vec[i]->getID()[2] != vec[i + 1]->getID()[1]) {
            auto it = std::find_if(vec.begin() + i, vec.end(), [&vec, &i](const std::unique_ptr<Element> &obj) {
                return vec[i]->getID()[2] == obj->getID()[1];});
            rotate(vec.begin() + i + 1, it, it + 1);
//            fmt::print("\n{}", "rotate");
        }
    }
}

void calc(std::vector<std::unique_ptr<Element>>& vec){
    for (size_t i = 1; i < vec.size()-1; ++i){
        auto Q = getFlow(vec);
        vec[i]->calcPressureDrop(Q);
    }
}

//void solve(std::vector<std::unique_ptr<Element>>& vec){
//    sort(vec);
//    calc(vec);
//    auto H = getPressure(vec);
//    auto &first = start(vec);
//    auto &next = downstream(first,vec);
//    auto Z = first.getProperties()[0];
//    auto dH = downstream(first,vec).getPressureDrop();
//
//    next.calcPiezometricHead(Z + H, dH);
//
////    vec[1]->calcPiezometricHead(firstElement(vec).getProperties()[0]+ H,
////                                vec[1]->getPressureDrop());
//    for (size_t i = 2; i < vec.size() - 1; ++i){
////        if (i != 2){
////            double dZ = vec[el]->
////        } else {
////            double dZ = - getPressure(vec);
////        }
//        if (vec[i]->getType() == PIPE){
//            vec[i]->calcPiezometricHead(vec[i-2]->getProperties()[5]-vec[i-1]->getPressureDrop(),
//                                        vec[i]->getPressureDrop());
//        }
//    }
//}

void solve(std::vector<std::unique_ptr<Element>>& vec){
    sort(vec);
    calc(vec);
    vec[1]->calcPiezometricHead(vec[0]->getProperties()[0]+vec[1]->getProperties()[1],
                                vec[1]->getPressureDrop());
    for (size_t i = 2; i < vec.size() - 1; ++i){
        if (vec[i]->getType() == PIPE){
            vec[i]->calcPiezometricHead(vec[i-2]->getProperties()[5]-vec[i-1]->getPressureDrop(),
                                        vec[i]->getPressureDrop());
        }
    }
}

int main()
{
    jsonProject prj;
    prj.readJsonFile("prj01.json");

    std::vector<std::unique_ptr<Element>> vec;
    prj.loadJsonFile(vec);
    solve(vec);


    fmt::print("\n{}\n", std::string(70, '-'));
    fmt::print("{}",fmt::format("{:<{}}", fmt::join({"Upstream ID","Element ID","Downstream ID", "Pressure drop"}, ""), 15));
    for (const auto& el : vec){
        fmt::print("\n");
        fmt::print("{}",fmt::format("{:<{}}", fmt::join(el->getID(), ""), 15));
        fmt::print("{:.5g}", el->getPressureDrop());
    }

    fmt::print("\n{}\n", std::string(70, '-'));
    fmt::print("{}",fmt::format("{:<{}}", "ID", 10));
    fmt::print("{}",fmt::format("{:<{}}", fmt::join({"Upstream","Downstream"}, ""), 30));
    fmt::print("\n");
    fmt::print("{}",fmt::format("{:<{}}", fmt::join({"","X","Z","H","X","Z","H"}, ""), 10));
    for (const auto& el : vec){
        if (el->getType() == PIPE){
            fmt::print("\n");
            fmt::print("{}",fmt::format("{:<{}}", el->getID()[1], 10));
            fmt::print("{}",fmt::format("{:<{}.5g}", fmt::join(el->getProperties(), ""), 10));
        }
    }

    double totalPressureDrop = 0;
    for (const auto& el : vec){
        totalPressureDrop += el->getPressureDrop();
    }
    fmt::print("\n{}\n", std::string(70, '-'));
    fmt::print("Total pressure drop:\t{:.3f}", totalPressureDrop);
    fmt::print("\n{}\n", std::string(70, '-'));
    return 0;
}




