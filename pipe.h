#ifndef PRJ01_PIPE_H
#define PRJ01_PIPE_H

#include "element.h"
#include <cmath>

class Pipe : public Element {
private:
    double diameter;
    double length;
    double friction;
    double constant;
public:
    Pipe(double D, double L, double lambda);
    double calculatePressureDrop(double flow) override;
};

#endif //PRJ01_PIPE_H


