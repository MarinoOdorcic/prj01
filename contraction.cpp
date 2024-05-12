#include "contraction.h"

Contraction::Contraction(double angle){
    contractionAngle = angle;
    type = elementType::CONTRACTION;
    setElementID(counter++);
    setElementID("-contraction");
}

//double Local::calculatePressureDrop(double flow) {
//    return coefficient * pow(flow, 2);
//}