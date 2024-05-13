#include "pipe.h"

/* ----- Functions ------------------------------------------ */

double theoremL(double X, double Z){
    return pow(pow(X,2) + pow(Z,2),0.5);
}
double theoremX(double L, double Z){
    return pow(pow(L,2) - pow(Z,2),0.5);
}

/* ----- Constructors --------------------------------------- */

Pipe::Pipe(double input1, double input2, double diameter, double lambda)
{
    type = elementType::PIPE;
    setElementID(counter++);
    setElementID("pipe");
    x1 = input1;
    z1 = input2;
    D = diameter;
    lam = lambda;
}

/* ----- Properties ----------------------------------------- */

void Pipe::setLength(double length) {
    L = length;
}
double Pipe::getLength() const {
    return L;
}
double Pipe::getDiameter() const {
    return D;
}

/* ----- Update --------------------------------------------- */

void Pipe::calcCoords(Element* upstream, Element* downstream) {
    double x0 = upstream->getX();
    double z0 = upstream->getZ();

    if (inputMethod == "Global Cartesian"){
        setCoords(x1, z1);
        setLength(theoremL(x0 - x1, z0 - z1));
    } else if (inputMethod == "Local Cartesian"){
        setCoords(x0 + x1, z0 + z1);
        setLength(theoremL(x1, z1));
    } else if (inputMethod == "Length and Global Z"){
        setCoords(x0 + theoremX(x1, z1 - z0), z1);
        setLength(x1);
    } else if (inputMethod == "Length and Local Z"){
        setCoords(x0 + theoremX(x1, z1), z0 + z1);
        setLength(x1);
    } else if (inputMethod == "Global Polar") {
        setCoords(x1 * cos(z1*M_PI/180), x1 * sin(z1*M_PI/180));
        setLength(theoremL(x1 * cos(z1*M_PI/180)-x0,x1 * sin(z1*M_PI/180)-z0));
    } else if (inputMethod == "Local Polar"){
        setCoords(x0 + x1 * cos(z1*M_PI/180), z0 + x1 * sin(z1*M_PI/180));
        setLength(x1);
    }
}

/* ----- Pressure Calc -------------------------------------- */

double Pipe::calculatePressureDrop() {
    return C * L * lam / pow(D, 5);
}

/* ----- Prints --------------------------------------------- */

void Pipe::printProperties(){
    fmt::print("\n");
    fmt::print("Input 1:  {:.4g}\n", x1);
    fmt::print("Input 2:  {:.4g}\n", z1);
    fmt::print("Length:   {:.4g}\n", L);
    fmt::print("Diameter: {:.4g}\n", D);
    fmt::print("Friction: {:.4g}\n", lam);
}
