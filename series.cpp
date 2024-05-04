#include "series.h"

Series::Series(double Q){
    flow =  Q;
};

void Series::addElement(Element* element) {
    elements.push_back(element);
}

double Series::totalPressureDrop() {
    double totalPressureDrop = 0.0;
    for (Element* element : elements) {
        totalPressureDrop += element->calculatePressureDrop(flow);
    }
    return totalPressureDrop;
}