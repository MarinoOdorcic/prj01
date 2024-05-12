#ifndef PRJ01_SERIES_H
#define PRJ01_SERIES_H

#include "element.h"
#include "pipe.h"
#include <vector>
#include <string>


class Series {
private:
    double flow;
    std::basic_string<char> input;
    std::vector<Element*> elements;

public:
    Series(std::vector<Element*> vec,
           std::basic_string<char> in,
           double Q);

    double totalPressureDrop();

    void updateID();
    void updateCoords();

    void printElementId() const;

};

#endif //PRJ01_SERIES_H
