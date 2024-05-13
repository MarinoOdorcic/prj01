#include "series.h"

/* ----- Functions ------------------------------------------ */

template<typename T>
void printColumn(T val, int width) {
    if (std::is_same<T, double>::value){
        fmt::print("{}", fmt::format("{:<{}.3g}", val, width));
    } else {
        fmt::print("{}", fmt::format("{:<{}}", val, width));
    }
}

template<typename T>
void printColumn(const std::vector<T>& vec, int width) {
    if (std::is_same<T, double>::value){
        fmt::print("{}", fmt::format("{:<{}.3g}", fmt::join(vec, ""), width));
    } else {
        fmt::print("{}",fmt::format("{:<{}}", fmt::join(vec, ""), width));
    }
}

/* ----- Constructors --------------------------------------- */

Series::Series(std::vector<Element*> vec, std::basic_string<char> inputMethod, double Q){
    elements = vec;
    flow =  Q;
    input = inputMethod;
};

/* ----- Update --------------------------------------------- */

void Series::updateID(){
    for (size_t i = 0; i < elements.size(); ++i){
        if(i>0){
            elements[i]->setUpstreamID(elements[i-1]->getID()[1]);
        }
        if(i < elements.size()-1) {
            elements[i]->setDownstreamID(elements[i+1]->getID()[1]);
        }
        if(i>0 and i < elements.size()){
            elements[i]->calcCoords(elements[i-1],elements[i+1]);
        }
    }
}

/* ----- Pressure Calc -------------------------------------- */

double Series::totalPressureDrop() {
    double totalPressureDrop = 0.0;
    for (Element* element : elements) {
        double k = element->calculatePressureDrop();
        element->setCoefficient(k);
        totalPressureDrop += k;
    }
    return totalPressureDrop;
}

/* ----- Prints --------------------------------------------- */

void Series::printSeriesProperties() const {
    fmt::print("\n");
    std::vector<std::string> title1 = {"Upstream ID", "Element ID", "Downstream ID"};
    std::vector<std::string> title2 = {"Global X", "Global Z", "Coeff. k", "Length", "Pressure drop"};
    printColumn(title1, 20);
    printColumn(title2, 10);
    fmt::print("\n");
    for (Element *element: elements) {
        std::vector<std::string> content1 = element->getID();
        std::vector<double> content2 = {element->getX(),
                                        element->getZ(),
                                        element->getCoefficient()};
        printColumn(content1,20);
        printColumn(content2,10);
        if(dynamic_cast<Pipe*>(element)){
            printColumn(dynamic_cast<Pipe*>(element)->getLength(),10);
        }else{
            printColumn("",10);
        }
        fmt::print("\n");
    }
}

