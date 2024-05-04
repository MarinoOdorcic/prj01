#include "pipe.h"

Pipe::Pipe(double D, double L, double F)
{
    diameter = D;
    length = L;
    friction = F;
}
double Pipe::pressureDrop(double flow) const {
    return constant * length * friction * pow(flow, 2) / pow(diameter, 5);
}