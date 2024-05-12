#ifndef PRJ01_CONTRACTION_H
#define PRJ01_CONTRACTION_H

#include "local.h"

class Contraction : public Local {
private:
    static int counter;
    double contractionAngle;
public:
    Contraction(double angle);
};


#endif //PRJ01_CONTRACTION_H
