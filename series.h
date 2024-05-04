#ifndef PRJ01_SERIES_H
#define PRJ01_SERIES_H

#include <vector>
#include "Element.h"

class Series {
private:
    double flow;
    std::vector<Element*> elements;
//    std::vector<int> elementId;
public:
    Series(double Q);
    void addElement(Element* element);
    double totalPressureDrop();
    void printElementId() const;

};

#endif //PRJ01_SERIES_H
