#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
//#include <nlohmann/json.hpp>
//#include <fstream>

#include <vector>
#include <memory>
#include <algorithm>
#include "element.h"
#include "pipe.h"
#include "local.h"

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
        vec[i]->calcPressureDrop(vec[vec.size()-1]->getProperties()[0]);
    }
}

void solve(std::vector<std::unique_ptr<Element>>& vec){
    first(vec);
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
    std::vector<std::unique_ptr<Element>> vec;

    vec.emplace_back(std::move(std::make_unique<Pipe>(
            "p1",0,40,100,35,1,0.005,"in","l1")));
    vec.emplace_back(std::move(std::make_unique<Pipe>(
            "p2",100,35,200,30,1.5,0.01,"l1","l2")));
    vec.emplace_back(std::move(std::make_unique<Pipe>(
            "p3",200,30,350,30,0.8,0.002,"l2","fl")));

    vec.emplace_back(std::move(std::make_unique<Local>(
            "in", 120, "NONE", "p1")));
    vec.emplace_back(std::move(std::make_unique<Local>(
            "fl", 10, "p3", "NONE")));

    vec.emplace_back(std::move(std::make_unique<Local>(
            "l1", 0.05, "p1", "p2")));
    vec.emplace_back(std::move(std::make_unique<Local>(
            "l2", 0.1, "p2", "p3")));

    solve(vec);


    fmt::print("\n");
    fmt::print("{}",fmt::format("{:<{}}", fmt::join({"Upstream ID","Element ID","Downstream ID", "Pressure drop"}, ""), 15));
    for (const auto& el : vec){
        fmt::print("\n");
        fmt::print("{}",fmt::format("{:<{}}", fmt::join(el->getID(), ""), 15));
        fmt::print("{:.5g}", el->getPressureDrop());
    }

    fmt::print("\n\n");
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
    fmt::print("\n\nTotal pressure drop:\t{:.3f}\n", totalPressureDrop);

    return 0;
}




