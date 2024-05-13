#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
//#include <nlohmann/json.hpp>
//#include <fstream>

#include <iostream>
#include <cmath>
#include <vector>

#include "elementBaseClass/element.h"
#include "elementSubClass/inlet.h"
#include "elementSubClass/pipe.h"
#include "elementSubClass/local.h"
#include "seriesBaseClass/series.h"
#include "localSubClass/contraction.h"
#include "localSubClass/expansion.h"
#include "localSubClass/elbow.h"


int Element::counter = 1;
int Pipe::counter = 1;
int Local::counter = 1;
int Contraction::counter = 1;
int Expansion::counter = 1;
int Elbow::counter = 1;

int main()
{
    std::vector<Element*> vec;
    vec.push_back(new Inlet(0,0, "rounded edge"));
    vec.push_back(new Pipe(50,10,1,0.001));
    vec.push_back(new Pipe(20,20,1,0.001));
    vec.push_back(new Local(0.02));
    vec.push_back(new Pipe(40,-5,0.8,0.001));
    vec.push_back(new Expansion(90));
    vec.push_back(new Pipe(100,0,1,0.001));

    Series series(vec,"Local Cartesian",30);

    series.updateID();

    series.totalPressureDrop();
    series.printSeriesProperties();

    vec[3]->printProperties();


//    fmt::print("\n\nTotal pressure drop {}", series.totalPressureDrop());



    for (auto& obj : vec) {
        delete obj;
    }

    return 0;
}



