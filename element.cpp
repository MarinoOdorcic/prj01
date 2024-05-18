#include "element.h"

/* ----- Element IDs ---------------------------------------- */
void Element::setElementID(const std::string& ID){
    elementID = ID;
}
void Element::setUpstreamID(const std::string& ID){
    upstreamID = ID;
}
void Element::setDownstreamID(const std::string& ID){
    downstreamID = ID;
}
std::vector<std::string> Element::getID(){
    return {upstreamID, elementID, downstreamID};
}

/* ----- Properties ----------------------------------------- */
void Element::setType(elementType element) {
    type = element;
}
elementType Element::getType() const {
    return type;
}
void Element::setPressureDrop(double dp){
    pressureDrop = dp;
}
double Element::getPressureDrop() const {
    return pressureDrop;
}

/* ----- Prints --------------------------------------------- */
void Element::printType() const{
    std::cout << type << std::endl;
}
void Element::printID() const{
    fmt::print("Upstream ID:   {}\n", upstreamID);
    fmt::print("Element ID:    {}\n", elementID);
    fmt::print("Downstream ID: {}\n", downstreamID);
}




