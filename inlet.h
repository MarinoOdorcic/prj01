#ifndef PRJ01_INLET_H
#define PRJ01_INLET_H

#include "element.h"


class Inlet : public Element {
private:
    double coefficient;
public:

    Inlet(double xGlobal, double zGlobal, double k);
    double calculatePressureDrop(double flow) override;
};


#endif //PRJ01_INLET_H
