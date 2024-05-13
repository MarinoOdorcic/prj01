#include "element.h"

#include <utility>

/* ----- Constructors --------------------------------------- */

Element::Element(){
    elementID = std::to_string(counter++);
}

/* ----- Element IDs ---------------------------------------- */

void Element::setElementID(int ID){
    elementID += "-" + std::to_string(ID);
}
void Element::setElementID(const std::string& ID){
    elementID += "-" + ID;
}
void Element::setUpstreamID(std::basic_string<char> ID){
    upstreamID = std::move(ID);
}
void Element::setDownstreamID(std::basic_string<char> ID){
    downstreamID = std::move(ID);
}
std::vector<std::string> Element::getID(){
    return {upstreamID, elementID, downstreamID};
}

/* ----- Element Coords ------------------------------------- */

void Element::setCoords(double globalX, double globalZ){
    xCoord = globalX;
    zCoord = globalZ;
}

/* ----- Pressure Calc -------------------------------------- */

void Element::setCoefficient(double k){
    pressureCoefficient = k;
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
