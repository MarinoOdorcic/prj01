#include "series.h"
#include "local.h"
#include "pipe.h"
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <iostream>

Series::Series(std::vector<Element*> vec, std::basic_string<char> in, double Q){
    elements = vec;
    flow =  Q;
    inputMethod = in;
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
    for (size_t i = 0; i < elements.size(); ++i) { // <-----------------------------------i=0
        if (inputMethod == "Length/Z" && elements[i]->getType()==PIPE) {
            auto temp = dynamic_cast<Pipe*>(elements[i]);
            temp->setLength(temp->value1);

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
    fmt::print("Upstream ID\tElement ID\tDownstream ID\n");
    for (Element *element: elements) {
        fmt::print("{}\n",fmt::join(element->getID(), "\t"));
    }
}