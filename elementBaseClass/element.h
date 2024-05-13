#ifndef PRJ01_ELEMENT_H
#define PRJ01_ELEMENT_H

#include "fmt/core.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

enum elementType{
    INLET,
    OUTLET,
    PIPE,
    LOCAL,
    CONTRACTION,
    EXPANSION,
    ELBOW,
    GRID,
    VALVE,
};

class Element {
public:
    /* ----- Constructors --------------------------------------- */
    Element();

    /* ----- Element IDs ---------------------------------------- */
    void setElementID(int ID);
    void setElementID(const std::string& ID);
    void setUpstreamID(std::basic_string<char> ID);
    void setDownstreamID(std::basic_string<char> ID);
    std::vector<std::string> getID();

    /* ----- Element Coords ------------------------------------- */
    void setCoords(double globalX, double globalZ);
    double getX() const {return xCoord;}
    double getZ() const {return zCoord;}

    virtual void calcCoords(Element* upstream, Element* downstream) = 0;

    /* ----- Pressure Calc -------------------------------------- */
    void setCoefficient(double k);
    virtual double calculatePressureDrop() = 0;
    double getCoefficient(){return pressureCoefficient;}

    /* ----- Prints --------------------------------------------- */

    virtual void printProperties() = 0;
    void printType() const;
    void printID() const;

    elementType type=type;
//    elementType getType() const {return type;}

private:
    static int counter;
    std::string elementID;
    std::string upstreamID = "n/a";
    std::string downstreamID = "n/a";
    double xCoord;
    double zCoord;
    double pressureCoefficient;
};

#endif //PRJ01_ELEMENT_H
