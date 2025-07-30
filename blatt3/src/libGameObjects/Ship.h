#ifndef BLATT3_SHIP_H
#define BLATT3_SHIP_H


#include "Object.h"
#include "Missile.h"


namespace GameObjects {

    class Ship : public Sea::Object {
    private:
        int numberOfHit;
    public:
        using Sea::Object::Object; // inherit constructors with identical parameters
        Ship(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation);
        bool isInsideSeaBounds() const;
        // TODO Aufgabe 4:
        //  Deklariert die Funktion `bool checkAndUpdateIncomingMissile(Missile & missile)`
        bool checkAndUpdateIncomingMissile(Missile & missile);
        bool isDestroyed() const;
    };

}
// TODO Aufgabe 4:
//  Entfernt die Kommentar-Zeichen (//), wenn Aufgabe 4 erledigt ist:
#define CLASS_SHIP_COMPLETE
#endif //BLATT3_SHIP_H
