#include "series.h"
#include "element.h"
#include "local.h"
#include "pipe.h"
#include "fun.h"
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <iostream>

Series::Series(std::vector<Element*> vec, std::basic_string<char> inputMethod, double Q){
    elements = vec;
    flow =  Q;
    input = inputMethod;
};


void Series::updateID(){
    for (size_t i = 0; i < elements.size(); ++i){
        if(i>0){
            elements[i]->setUpstreamID(elements[i-1]->getID()[1]);
        }
        if (i < elements.size()-1) {
            elements[i]->setDownstreamID(elements[i+1]->getID()[1]);
        }
    }
};

void Series::updateCoords(){
    for (size_t i = 0; i < elements.size(); ++i) {
        if (elements[i]->getType()==PIPE) {
            pipeCoords(input, elements[i-1], elements[i]);
        }
        if (elements[i]->getType()==LOCAL) {
            localCoords(elements[i - 1], elements[i]);
        }
    }
}

double Series::totalPressureDrop() {
    double totalPressureDrop = 0.0;
    for (Element* element : elements) {
        totalPressureDrop += element->calculatePressureDrop(flow);
    }
    return totalPressureDrop;
}

void Series::printElementId() const {
    fmt::print("Upstream ID\tElement ID\tDownstream ID\tX Coord\tZ Coord\n");
    for (Element *element: elements) {
        fmt::print("{}\t",fmt::join(element->getID(), "\t"));
        fmt::print("{:.2f}\t{:.2f}\n",element->getX(), element->getZ());

    }
}