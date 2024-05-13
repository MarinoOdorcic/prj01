#ifndef PRJ01_SERIES_H
#define PRJ01_SERIES_H


#include "../elementBaseClass/element.h"
#include "../elementSubClass/pipe.h"
#include <fmt/ranges.h>
#include <type_traits>
#include <vector>
#include <string>

class Series {
public:
    /* ----- Constructors --------------------------------------- */
    Series(std::vector<Element*> vec,
           std::basic_string<char> in,
           double Q);

    /* ----- Update --------------------------------------------- */
    void updateID();

    /* ----- Pressure Calc -------------------------------------- */
    double totalPressureDrop();

    /* ----- Prints --------------------------------------------- */
    void printSeriesProperties() const;

private:
    double flow;
    std::basic_string<char> input;
    std::vector<Element*> elements;
};

#endif //PRJ01_SERIES_H
