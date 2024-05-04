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

//void print(std::vector<Element> &series)
//{
//
//}

int main()
{
    Series series(30);

    Pipe pipe1(1,100,0.001);
    Pipe pipe2(1.2,200,0.001);
    fmt::print("{}: {}\n", "pipe1", pipe1.calculatePressureDrop(30));
    fmt::print("{}: {}\n", "pipe2", pipe2.calculatePressureDrop(30));

    series.addElement(&pipe1);


    fmt::print("{}: {}\n", "series", series.totalPressureDrop());

    Local local1(0.003);
    Local local2(0.002);
    fmt::print("{}: {}\n", "local1", local1.calculatePressureDrop(30));
    fmt::print("{}: {}\n", "local2", local2.calculatePressureDrop(30));


    series.addElement(&local1);
    series.addElement(&pipe2);
    series.addElement(&local2);

    fmt::print("{}: {}\n", "series", series.totalPressureDrop());

    series.printElementId();

    return 0;
}

