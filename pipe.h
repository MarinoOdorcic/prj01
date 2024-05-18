#ifndef PRJ01_PIPE_H
#define PRJ01_PIPE_H

#include "element.h"
#include "fmt/core.h"
#include <cmath>

constexpr double g{9.810665};
constexpr double pi{3.14159};
constexpr double constant{8 / (g * pi*pi)};

class Pipe : public Element {
private:
    double length;
    double diameter;
    double lambda;
    double upX;
    double upZ;
    double upH;
    double downX;
    double downZ;
    double downH;
public:
    /* ----- Constructors --------------------------------------- */
    Pipe(const std::string& element,
         double xStart,
         double zStart,
         double xEnd,
         double zEnd,
         double D,
         double R,
         const std::string& up,
         const std::string& down);

    /* ----- Calc ----------------------------------------------- */
    std::vector<double> getProperties() override;
    void calcPressureDrop(double Q) override;
    void calcPiezometricHead(double H, double dH) override;

    /* ----- Prints --------------------------------------------- */
    void printProperties() override;
};

#endif //PRJ01_PIPE_H

