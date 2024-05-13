#ifndef PRJ01_ELBOW_H
#define PRJ01_ELBOW_H

#include "../elementSubClass/local.h"
#include "../elementSubClass/pipe.h"

class Elbow : public Local {
public:
    /* ----- Constructors --------------------------------------- */
    Elbow();
    Elbow(double angle);

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


#endif //PRJ01_ELBOW_H
