#include "local.h"

Local::Local(double k){
    coefficient = k;
    type = elementType::LOCAL;
    setElementID(counter++);
    setElementID("-local");
}

double Local::calculatePressureDrop(double flow) {
    return coefficient * pow(flow, 2);
}