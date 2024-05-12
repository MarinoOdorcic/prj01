#ifndef PRJ01_ELEMENT_H
#define PRJ01_ELEMENT_H

#include <string>
#include <vector>
#include <cmath>

enum elementType{
    INLET,
    PIPE,
    LOCAL,
    CONTRACTION,
};

class Element {
private:
    static int counter;
    std::string elementID;
    std::string upstreamID = "n/a";
    std::string downstreamID = "n/a";
    double xCoord;
    double zCoord;


public:
    Element();
    ~Element();
    elementType type=type;


//    void updateID(int ID);
    virtual double calculatePressureDrop(double flowRate) = 0;

    elementType getType() const {return type;}

    void setCoords(double val1, double val2);
    double getX() const {return xCoord;}
    double getZ() const {return zCoord;}
    std::vector<double> getXZ(){return {xCoord,zCoord};}

    void setElementID(int ID);
    void setElementID(const std::string& ID);
    void setUpstreamID(std::basic_string<char> ID);
    void setDownstreamID(std::basic_string<char> ID);

    std::vector<std::string> getID();

    void printType() const;
    void printID() const;
};

#endif //PRJ01_ELEMENT_H
