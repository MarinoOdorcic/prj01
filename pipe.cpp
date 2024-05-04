#include "pipe.h"

Pipe::Pipe(double D, double L, double F)
{
    diameter = D;
    length = L;
    friction = F;
    type = elementType::PIPE;
}

double Pipe::calculatePressureDrop(double flow) {
    return constant * length * friction * pow(flow, 2) / pow(diameter, 5);
}