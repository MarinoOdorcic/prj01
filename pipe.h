#ifndef PRJ01_PIPE_H
#define PRJ01_PIPE_H

#include "element.h"
#include "pipe.h"
#include <fmt/core.h>
#include <cmath>

class Pipe : public Element {
private:
    static int counter;


    double diameter;
    double friction;
    double constant = 8 / (9.81 * pow(M_PI,2));
public:
    double length;
    double value1;
    double value2;


    Pipe(double val1, double val2, double D, double lambda);
    double calculatePressureDrop(double flow) override;
    void printProperties();
    void setLength(double L);
};

#endif //PRJ01_PIPE_H


