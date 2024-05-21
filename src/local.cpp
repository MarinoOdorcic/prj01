#include "local.h"

/* ----- Constructors --------------------------------------- */
Local::Local(const std::string& element,
             double val,
             const std::string& up,
             const std::string& down)
{
    value = val;
    setType(elementType::LOCAL);
    setElementID(element);
    setUpstreamID(up);
    setDownstreamID(down);
}

/* ----- Calc ----------------------------------------------- */
std::vector<double> Local::getProperties(){
    return {value};
}
void Local::calcPressureDrop(double Q) {
    setPressureDrop(value * pow(Q, 2));
}
void Local::calcPiezometricHead(double H, double dH) {
}

/* ----- Prints --------------------------------------------- */
void Local::printProperties() {
    std::cout << std::endl << getType();
    fmt::print("\n");
    fmt::print("Loss coefficient:  {:.4g}\n", value);
}
