#include "inlet.h"


Inlet::Inlet(double xGlobal, double zGlobal, double k) {
    setCoords(xGlobal, zGlobal);
    coefficient = k;
    type = elementType::INLET;
    setElementID(1);
    setElementID("-inlet");
}

double Inlet::calculatePressureDrop(double flow) {
    return coefficient * pow(flow, 2);
}