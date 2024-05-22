#include <fmt/format.h>
#include <fmt/ranges.h>

#include <vector>
#include <memory>
#include <algorithm>
#include "element.h"
#include "json.h"

double getPressure(std::vector<std::unique_ptr<Element>> &vec) {
    auto it = std::find_if(vec.begin(), vec.end(), [](const std::unique_ptr<Element>& obj) {
        return obj->getID()[0] == "NONE";});
    return (*it)->getProperties()[0];
}

double getFlow(std::vector<std::unique_ptr<Element>> &vec) {
    auto it = std::find_if(vec.begin(), vec.end(), [](const std::unique_ptr<Element>& obj) {
        return obj->getID()[2] == "NONE";});
    return (*it)->getProperties()[0];
}

std::string start(std::vector<std::unique_ptr<Element>> &vec) {
    auto it = std::find_if(vec.begin(), vec.end(), [](const std::unique_ptr<Element>& obj) {
        return obj->getID()[0] == "NONE";});
    return (*it)->getID()[2];
}

std::unique_ptr<Element>& downstream(std::vector<std::unique_ptr<Element>> &vec, std::string id){
    auto it = std::find_if(vec.begin(), vec.end(), [&id](const std::unique_ptr<Element> &obj) {
        return obj->getID()[1] == id;});
    return vec[std::distance(vec.begin(), it)];
}

void solve(std::vector<std::unique_ptr<Element>>& vec) {
    double Q = getFlow(vec);
    double H = getPressure(vec);
    double dH = 0;
    std::string id = start(vec);

    for (int i = 1; i < vec.size()-1; ++i){
        std::unique_ptr<Element>& element = downstream(vec,id);
        if (element->getID()[2] == "NONE"){break;}
        if (i==1){
            H += element->getProperties()[1];
        }
        element->calcPressureDrop(Q);
        dH += element->getPressureDrop();
        if (element->getType()==PIPE){
            element->calcPiezometricHead(H, dH);
            dH = 0;
            H = element->getProperties()[5];
        }
        id = element->getID()[2];
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