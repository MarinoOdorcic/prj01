#ifndef PRJ01_INLET_H
#define PRJ01_INLET_H

#include "../elementBaseClass/element.h"

class Inlet : public Element {
public:
    /* ----- Constructors --------------------------------------- */
    Inlet(double xGlobal, double zGlobal, double k);
    Inlet(double xGlobal, double zGlobal, const std::string& inletType);

    /* ----- Pressure Calc -------------------------------------- */
    double calculatePressureDrop() override;
    void calcCoords(Element* upstream, Element* downstream) override;

    /* ----- Prints --------------------------------------------- */
    void printProperties() override;

private:
    std::string inlet;
    double coefficient;
};

#endif //PRJ01_INLET_H
