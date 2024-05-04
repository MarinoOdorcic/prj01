#ifndef PRJ01_ELEMENT_H
#define PRJ01_ELEMENT_H

enum elementType{
    PIPE,
    LOCAL
};

class Element {
public:
    Element();
    ~Element();
    int id = 0;
    elementType type=type;
    virtual double calculatePressureDrop(double flowRate) = 0;
    void printId() const;
    void printType() const;
    elementType getType() const { return type; }
};

#endif //PRJ01_ELEMENT_H
