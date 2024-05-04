#include "local.h"

Local::Local(double k){
    coefficient = k;
    type = elementType::LOCAL;
}

double Local::calculatePressureDrop(double flow) {
    return coefficient * pow(flow, 2);
}