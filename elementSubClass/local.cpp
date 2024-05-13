#include "local.h"

/* ----- Constructors --------------------------------------- */

Local::Local() {
    type = elementType::LOCAL;
    setElementID(counter++);
    coefficient = 10000000000;
}
Local::Local(double k){
    coefficient = k;
    type = elementType::LOCAL;
    setElementID(counter++);
    setElementID("local");
}

/* ----- Properties ----------------------------------------- */
void Local::setCoefficient(double k){
    coefficient = k;
}

/* ----- Update --------------------------------------------- */

void Local::calcCoords(Element* upstream, Element* downstream) {
    setCoords(upstream->getX(),upstream->getZ());
}

/* ----- Pressure Calc -------------------------------------- */

double Local::calculatePressureDrop() {
    return coefficient;
}

/* ----- Prints --------------------------------------------- */

void Local::printProperties(){
    fmt::print("\n");
    fmt::print("Loss coefficient:  {:.4g}\n", coefficient);
}

