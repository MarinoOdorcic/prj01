#include "element.h"
#include <fmt/core.h>
#include <iostream>
#include <fmt/ostream.h>

Element::Element()
{
    elementID = std::to_string(counter++)+"-";
}

Element::~Element()
{
//    fmt::print("Element dtor\n");
}

//----------------------------------------------------------------
void Element::setElementID(int ID){
    elementID += std::to_string(ID);
}
void Element::setElementID(const std::string& ID){
    elementID += ID;
}
void Element::setUpstreamID(std::basic_string<char> ID){
    upstreamID = ID;
}
void Element::setDownstreamID(std::basic_string<char> ID){
    downstreamID = ID;
}
//----------------------------------------------------------------
void Element::setCoords(double val1, double val2){
    xCoord = val1;
    zCoord = val2;
}
//----------------------------------------------------------------
std::vector<std::string> Element::getID()
{   return {upstreamID, elementID, downstreamID};
}
//----------------------------------------------------------------
void Element::printType() const{
    std::cout << type << std::endl;
}
//----------------------------------------------------------------
void Element::printID() const{
    fmt::print("Upstream ID:   {}\n", upstreamID);
    fmt::print("Element ID:    {}\n", elementID);
    fmt::print("Downstream ID: {}\n", downstreamID);
}
