#pragma once
#include "pipe.h"
#include <cmath>

class Pipe
{
private:
    double diameter;
    double length;
    double friction;
    double constant = 8 / (9.81 * pow(M_PI,2));
public:
    Pipe(double D, double L, double F);
    double pressureDrop(double flow) const;
};


