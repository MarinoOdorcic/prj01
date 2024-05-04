#ifndef PRJ01_PIPE_H
#define PRJ01_PIPE_H

#include "element.h"
#include <cmath>

class Pipe : public Element {
private:
    double diameter;
    double length;
    double friction;
    double constant = 8 / (9.81 * pow(M_PI,2));
public:
    Pipe(double D, double L, double F);
    double calculatePressureDrop(double flow) override;
};

#endif //PRJ01_PIPE_H


