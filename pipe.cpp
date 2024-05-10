#include "pipe.h"

Pipe::Pipe(double val1, double val2, double D, double lambda)
{
    type = elementType::PIPE;
    setElementID(counter++);
    setElementID("-pipe");
    value1 = val1;
    value2 = val2;
    diameter = D;
    friction = lambda;
}


double Pipe::calculatePressureDrop(double flow) {
    return constant * length * friction * pow(flow, 2) / pow(diameter, 5);
}
void Pipe::setLength(double L){
    length = L;
}

void Pipe::printProperties(){
    fmt::print("Value 1:  {}\n", value1);
    fmt::print("Value 2:  {}\n", value2);
    fmt::print("Diameter: {}\n", diameter);
    fmt::print("Friction: {}\n", friction);
}