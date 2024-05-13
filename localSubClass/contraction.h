#ifndef PRJ01_CONTRACTION_H
#define PRJ01_CONTRACTION_H

#include "../elementSubClass/local.h"
#include "../elementSubClass/pipe.h"

class Contraction : public Local {
public:
    /* ----- Constructors --------------------------------------- */
    Contraction();
    Contraction(double angle);

    /* ----- Update --------------------------------------------- */
    void calcCoords(Element* upstream, Element* downstream) override;

    /* ----- Pressure Calc -------------------------------------- */
    double calculatePressureDrop() override;

    /* ----- Prints --------------------------------------------- */
    void printProperties() override;

private:
    static int counter;
    double theta;
    double D;
    double d;
};

#endif //PRJ01_CONTRACTION_H
