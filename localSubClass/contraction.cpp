#include "contraction.h"

/* ----- Constructors --------------------------------------- */

Contraction::Contraction(){
    theta = 180;
    type = elementType::CONTRACTION;
    setElementID(counter++);
    setElementID("contraction");
}

Contraction::Contraction(double angle){
    theta = angle;
    type = elementType::CONTRACTION;
    setElementID(counter++);
    setElementID("contraction");
}

/* ----- Update --------------------------------------------- */

void Contraction::calcCoords(Element* upstream, Element* downstream) {
    setCoords(upstream->getX(),upstream->getZ());
    if (dynamic_cast<Pipe*>(upstream) and dynamic_cast<Pipe*>(downstream)){
        D = dynamic_cast<Pipe*>(upstream)->getDiameter();
        d = dynamic_cast<Pipe*>(downstream)->getDiameter();
        if(D<=d){
            fmt::print("contraction not valid");
        }
    } else {fmt::print("contraction not valid");}
}

/* ----- Pressure Calc -------------------------------------- */

double Contraction::calculatePressureDrop() {
    return 0.5 * (1 - pow(d,2) / pow(D,2)) * sin(theta/2 * M_PI/180);;
}

/* ----- Prints --------------------------------------------- */

void Contraction::printProperties(){
    fmt::print("\n");
    fmt::print("Contraction angle:    {:.4g}\n", theta);
    fmt::print("Upstream diameter:    {:.4g}\n", D);
    fmt::print("Downstream diameter:  {:.4g}\n", d);
}

