#ifndef PRJ01_ELEMENT_H
#define PRJ01_ELEMENT_H

#include "fmt/core.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

enum elementType{
    PIPE,
    LOCAL
};

class Element {
private:
    elementType type;
    std::string elementID;
    std::string upstreamID = "NONE";
    std::string downstreamID = "NONE";
    double pressureDrop = 0;
public:
    /* ----- Constructors --------------------------------------- */
    Element(){};
    virtual ~Element() = default;

    /* ----- Element IDs ---------------------------------------- */
    void setElementID(const std::string& ID);
    void setUpstreamID(const std::string& ID);
    void setDownstreamID(const std::string& ID);
    std::vector<std::string> getID();

    /* ----- Properties ----------------------------------------- */
    void setType(elementType element);
    elementType getType() const;
    void setPressureDrop(double dp);
    double getPressureDrop() const;

    /* ----- Calc ----------------------------------------------- */
    virtual std::vector<double> getProperties() = 0;
    virtual void calcPressureDrop(double Q) = 0;
    virtual void calcPiezometricHead(double H, double dH) = 0;

    /* ----- Prints --------------------------------------------- */

    virtual void printProperties() = 0;
    void printType() const;
    void printID() const;


};

#endif //PRJ01_ELEMENT_H
