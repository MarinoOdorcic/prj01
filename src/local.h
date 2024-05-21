#ifndef PRJ01_LOCAL_H
#define PRJ01_LOCAL_H

#include "element.h"

class Local : public Element {
private:
    double value;
public:
    /* ----- Constructors --------------------------------------- */
    Local(const std::string& element,
          double val,
          const std::string& up,
          const std::string& down);

    /* ----- Calc ----------------------------------------------- */
    std::vector<double> getProperties() override;
    void calcPressureDrop(double Q) override;
    void calcPiezometricHead(double H, double dH) override;

    /* ----- Prints --------------------------------------------- */
    void printProperties();
};

#endif //PRJ01_LOCAL_H
