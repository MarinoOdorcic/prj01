#include "pipe.h"

Pipe::Pipe(double D, double L, double lambda)
{
    type = elementType::PIPE;
    diameter = D;
    length = L;
    friction = lambda;
    constant = 8 / (9.81 * pow(M_PI,2));
}

double Pipe::calculatePressureDrop(double flow) {
    return constant * length * friction * pow(flow, 2) / pow(diameter, 5);
}