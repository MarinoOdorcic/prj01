#include "series.h"
#include <fmt/core.h>

#include <iostream>

Series::Series(double Q){
    flow =  Q;
};

void Series::addElement(Element* element) {
    elements.push_back(element);
}

double Series::totalPressureDrop() {
    double totalPressureDrop = 0.0;
    int id = 0;
    for (Element* element : elements) {
        element->id = id++;
        totalPressureDrop += element->calculatePressureDrop(flow);
    }
    return totalPressureDrop;
}

void Series::printElementId() const {
    for (const Element *element: elements) {
        element->printId();
        element->printType();
//        fmt::print("{}", element->getType());
//        std::cout << element->getType();
    }
}