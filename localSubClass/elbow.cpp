#include "elbow.h"

/* ----- Constructors --------------------------------------- */

Elbow::Elbow(){
    theta = 180;
    type = elementType::EXPANSION;
    setElementID(counter++);
    setElementID("expansion");
}

Elbow::Elbow(double angle){
    theta = angle;
    type = elementType::EXPANSION;
    setElementID(counter++);
    setElementID("expansion");
}

/* ----- Update --------------------------------------------- */

void Elbow::calcCoords(Element* upstream, Element* downstream) {
    setCoords(upstream->getX(),upstream->getZ());
    if (dynamic_cast<Pipe*>(upstream) and dynamic_cast<Pipe*>(downstream)){
        D = dynamic_cast<Pipe*>(downstream)->getDiameter();
        d = dynamic_cast<Pipe*>(upstream)->getDiameter();
        if(D<=d){
            fmt::print("expansion not valid");
        }
    } else {fmt::print("expansion not valid");}
}

/* ----- Pressure Calc -------------------------------------- */

double Elbow::calculatePressureDrop() {
    return (1 - pow(d,2) / pow(D,2)) * sin(theta/2 * M_PI/180);;
}

/* ----- Prints --------------------------------------------- */

void Elbow::printProperties(){
    fmt::print("\n");
    fmt::print("Expansion angle:      {:.4g}\n", theta);
    fmt::print("Upstream diameter:    {:.4g}\n", d);
    fmt::print("Downstream diameter:  {:.4g}\n", D);
}
