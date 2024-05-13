#ifndef PRJ01_PIPE_H
#define PRJ01_PIPE_H

#include "../elementBaseClass/element.h"
#include "fmt/core.h"
#include <cmath>

class Pipe : public Element {
public:
    /* ----- Constructors --------------------------------------- */
    Pipe(double input1, double input2, double diameter, double lambda);

    /* ----- Properties ----------------------------------------- */
    void setLength(double length);
    double getLength() const;
    double getDiameter() const;

    /* ----- Update --------------------------------------------- */
    void calcCoords(Element* upstream, Element* downstream) override;

    /* ----- Pressure Calc -------------------------------------- */
    double calculatePressureDrop() override;

    /* ----- Prints --------------------------------------------- */
    void printProperties() override;

private:
    static int counter;
    double L = 0;
    double x1;
    double z1;
    double D;
    double lam;
    double C = 8 / (9.81 * pow(M_PI,2));
    std::string inputMethod = "Local Cartesian";
};

#endif //PRJ01_PIPE_H

