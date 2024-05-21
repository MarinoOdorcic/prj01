#include "pipe.h"

constexpr double g{9.810665};
constexpr double pi{3.14159};
constexpr double constant{8 / (g * pi*pi)};

/* ----- Functions ------------------------------------------ */
double theoremL(double X, double Z){
    return pow(pow(X,2) + pow(Z,2),0.5);
}

/* ----- Constructors --------------------------------------- */
Pipe::Pipe(const std::string& element,
           double xStart,
           double zStart,
           double xEnd,
           double zEnd,
           double D,
           double R,
           const std::string& up,
           const std::string& down)
{
    setType(elementType::PIPE);
    setElementID(element);
    setUpstreamID(up);
    setDownstreamID(down);
    upX = xStart;
    upZ = zStart;
    downX = xEnd;
    downZ = zEnd;
    length = theoremL(xEnd-xStart, zEnd-zStart);
    diameter = D;
    lambda = R;
}

/* ----- Calc ----------------------------------------------- */
std::vector<double> Pipe::getProperties(){
    return {upX, upZ, upH, downX, downZ, downH};
}

void Pipe::calcPressureDrop(double Q) {
    setPressureDrop(constant * length * lambda / pow(diameter, 5) * pow(Q, 2));
}
void Pipe::calcPiezometricHead(double H, double dH) {
    upH = H;
    downH = H - dH;
}

/* ----- Prints --------------------------------------------- */
void Pipe::printProperties(){
    fmt::print("\n");
    fmt::print("Length:   {:.4g}\n", length);
    fmt::print("Diameter: {:.4g}\n", diameter);
    fmt::print("Lambda:   {:.4g}\n", lambda);
}
