#ifndef PRJ01_LOCAL_H
#define PRJ01_LOCAL_H

#include "element.h"
#include <cmath>

class Local : public Element {
private:
    double coefficient;
public:
    Local(double k);
    double calculatePressureDrop(double flow) override;
};

#endif //PRJ01_LOCAL_H
