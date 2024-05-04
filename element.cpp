#include "element.h"
#include <fmt/core.h>
#include <iostream>
#include <fmt/ostream.h>

Element::Element()
{
//    fmt::print("Element ctor\n");
}

Element::~Element()
{
//    fmt::print("Element dtor\n");
}

void Element::printId() const
{
    fmt::print("{} - ", id);
}

void Element::printType() const
{
    std::cout << type << std::endl;
}
