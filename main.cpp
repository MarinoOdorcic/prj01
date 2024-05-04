#include <fmt/core.h>
//#include <nlohmann/json.hpp>
//#include <fstream>

#include <iostream>
#include <cmath>
#include <vector>

#include "element.h"
#include "pipe.h"
#include "local.h"
#include "series.h"



//class Local{
//private:
//    double coefficient;
//public:
//    Local(double K){
//        coefficient = K;
//    }
//    double pressureDrop(double flow) {
//        double drop = coefficient * pow(flow, 2);
//        return drop;
//    }
//};


int main()
{
    Series series(30);

    Pipe pipe1(1,100,0.001);
    Pipe pipe2(1.2,200,0.001);
    fmt::print("{}: {}\n", "pipe1", pipe1.calculatePressureDrop(30));
    fmt::print("{}: {}\n", "pipe2", pipe2.calculatePressureDrop(30));

    series.addElement(&pipe1);
    series.addElement(&pipe2);

    fmt::print("{}: {}\n", "system", series.totalPressureDrop());

    Local local1(0.003);
    Local local2(0.002);
    fmt::print("{}: {}\n", "local1", local1.calculatePressureDrop(30));
    fmt::print("{}: {}\n", "local2", local2.calculatePressureDrop(30));


    series.addElement(&local1);
    series.addElement(&local2);

    fmt::print("{}: {}\n", "system", series.totalPressureDrop());

    return 0;
}

//using json = nlohmann::json;

//int main()
//{
//    std::ifstream file("input.json");
//    nlohmann::json data = nlohmann::json::parse(file);
//    std::cout << data<< std::endl;

//    fmt::print("{}: {}\n", "odgovor", 42);
//    return 0;
//}

