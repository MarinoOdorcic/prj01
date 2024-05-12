#ifndef PRJ01_PIPE_H
#define PRJ01_PIPE_H

#include "element.h"
#include "pipe.h"
#include <fmt/core.h>
#include <cmath>

class Pipe : public Element {
private:
    static int counter;
    double length;
    double value1;
    double value2;
    double diameter;
    double friction;
    double constant = 8 / (9.81 * pow(M_PI,2));
public:
    ;


    Pipe(double val1, double val2, double D, double lambda);
    double calculatePressureDrop(double flow) override;
    void printProperties();
    void setLength(double L){length=L;};
    double getLength(){return length;}
    double getVal1(){return value1;}
    double getVal2(){return value2;}


};

#endif //PRJ01_PIPE_H

