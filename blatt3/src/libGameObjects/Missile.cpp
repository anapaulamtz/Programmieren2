
// TODO Aufgabe 3:
//  Definiert die Funktionen der Klasse `Missile`.

#include "Missile.h"
namespace GameObjects {
    Missile::Missile(const Coordinates &newCoordinates)
    : Sea::Coordinates(newCoordinates), isTreffer(false){
    }

    void Missile::hitSomething()
    {
        this->isTreffer = true;
    }

    bool Missile::hasHitSomething() const
    {
        return this->isTreffer;
    }
}


