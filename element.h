#ifndef PRJ01_ELEMENT_H
#define PRJ01_ELEMENT_H


class Element {
public:
    Element();
    ~Element();
    virtual double calculatePressureDrop(double flowRate) = 0;
};


#endif //PRJ01_ELEMENT_H
