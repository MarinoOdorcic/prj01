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


int Element::counter = 1;
int Pipe::counter = 1;
int Local::counter = 1;

int main()
{

    std::vector<Element*> vec;
    vec.push_back(new Pipe(100,0,1,0.001));
//    vec.push_back(new Pipe(100,0,1,0.001));
//    vec.push_back(new Local(0.003));
//    vec.push_back(new Pipe(100,0,1,0.001));

    Series series(vec,"Length/Z",30);



    series.updateID();
    series.updateCoords();
//    series.printElementId();

    fmt::print("\n\nTotal pressure drop {}", series.totalPressureDrop());

    fmt::print("\n{}", dynamic_cast<Pipe*>(vec[0])->length);


    for (auto& obj : vec) {
        delete obj;
    }

    return 0;
}

