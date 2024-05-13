#include "inlet.h"

/* ----- Constructors --------------------------------------- */

Inlet::Inlet(double xGlobal, double zGlobal, double k) {
    type = elementType::INLET;
    setElementID(1);
    setElementID("inlet");
    setCoords(xGlobal, zGlobal);
    inlet = "defined by loss coefficient";
    coefficient = k;
}
Inlet::Inlet(double xGlobal, double zGlobal, const std::string& inletType) {
    type = elementType::INLET;
    setElementID(1);
    setElementID("inlet");
    setCoords(xGlobal, zGlobal);
    inlet = inletType;
}

/* ----- Update --------------------------------------------- */

void Inlet::calcCoords(Element* upstream, Element* downstream) {
}

/* ----- Pressure Calc -------------------------------------- */

double Inlet::calculatePressureDrop() {
    if (inlet == "reentrant"){
        coefficient = 0.8;
    } else if (inlet=="sharp edged"){
        coefficient = 0.5;
    } else if (inlet=="rounded edge"){
        coefficient = 0.1;
    } else {
        fmt::print("inlet type not valid");
    }
    return coefficient;
}

/* ----- Prints --------------------------------------------- */
void Inlet::printProperties(){
    fmt::print("\n");
    fmt::print("Inlet type:        {}\n", inlet);
    fmt::print("Loss coefficient:  {:.4g}\n", coefficient);
}

