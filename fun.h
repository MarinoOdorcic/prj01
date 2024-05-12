#ifndef PRJ01_FUN_H
#define PRJ01_FUN_H

#include "element.h"
#include "pipe.h"
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>


void pipeCoords(std::basic_string<char> input, Element* upstream, Element* element){
    Pipe* pipe = dynamic_cast<Pipe*>(element);
    double x0 = upstream->getX();
    double z0 = upstream->getZ();
    double v1 = pipe->getVal1();
    double v2 = pipe->getVal2();

   if (input == "Length and Z"){
       double x1 = x0 + pow(pow(v1,2) - pow(v2 - z0,2),0.5);
       pipe->setLength(v1);
       fmt::print("{}\n" , v2);
       pipe->setCoords(x1, v2);
   }
   else if (input == "Length and H"){
       double x1 = x0 + pow(pow(v1,2) - pow(v2,2),0.5);
       pipe->setLength(x1);
       pipe->setCoords(x1, z0 + v2);
   }
   else if (input == "Local Cartesian"){
       double L = pow(pow(v1,2) + pow(v2,2),0.5);
       pipe->setLength(L);
       pipe->setCoords(x0 +v1, z0 + v2);
   }
   else if (input == "Global Cartesian"){
       double L = pow(pow(v1 - x0,2) + pow(v2 - z0,2),0.5);
       pipe->setLength(L);
       pipe->setCoords(v1, v2);
   }
   else if (input == "Local Polar"){
       double X = v1 * cos(v2*M_PI/180);
       double H = v1 * sin(v2*M_PI/180);
       pipe->setLength(v1);
       pipe->setCoords(x0 + X, z0 + H);
   }
   else if (input == "Global Polar"){
       double x1 = v1 * cos(v2*M_PI/180);
       double z1 = v1 * sin(v2*M_PI/180);
       double L = pow(pow(x1 - x0,2) + pow(z1 - z0,2),0.5);
       pipe->setLength(L);
       pipe->setCoords(x1, z1);
   }
}

void localCoords(Element* upstream, Element* element){
    Local* local = dynamic_cast<Local*>(element);
    double x0 = upstream->getX();
    double z0 = upstream->getZ();
    local->setCoords(x0,z0);
}

template<typename T>
void printVec(const std::vector<T>& vec, int width) {
    fmt::print("{}",fmt::format("{:<{}}", fmt::join(vec, ""), width));
}


#endif //PRJ01_FUN_H
