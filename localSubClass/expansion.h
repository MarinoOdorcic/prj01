#ifndef PRJ01_EXPANSION_H
#define PRJ01_EXPANSION_H

#include "../elementSubClass/local.h"
#include "../elementSubClass/pipe.h"

class Expansion : public Local {
public:
    /* ----- Constructors --------------------------------------- */
    Expansion();
    Expansion(double angle);

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

#endif //PRJ01_EXPANSION_H
