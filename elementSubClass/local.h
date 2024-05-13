#ifndef PRJ01_LOCAL_H
#define PRJ01_LOCAL_H

#include "../elementBaseClass/element.h"

class Local : public Element {
protected:
    Local();
public:
    /* ----- Constructors --------------------------------------- */

    Local(double k);

    /* ----- Properties ----------------------------------------- */
    void setCoefficient(double k);

    /* ----- Update --------------------------------------------- */
    void calcCoords(Element* upstream, Element* downstream);

    /* ----- Pressure Calc -------------------------------------- */
    double calculatePressureDrop();

    /* ----- Prints --------------------------------------------- */
    void printProperties();

private:
    static int counter;
    double coefficient;
};

#endif //PRJ01_LOCAL_H
