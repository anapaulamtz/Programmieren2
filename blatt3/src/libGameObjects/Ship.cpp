#include "Ship.h"

#include "Constants.h"
// TODO Aufgabe 7:
//  Warum ist die folgende using-Anweisung hier unnötig?
// weil alle Code schon im Scope namespace GameObjects liegen.

using GameObjects::Constants;

namespace GameObjects {

    Ship::Ship(const Coordinates &newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Sea::Object(newCoordinates, newSize, newOrientation), numberOfHit(0){}

    bool Ship::isInsideSeaBounds() const
    {
        if (x < Constants::seaSizeX && y < Constants::seaSizeY) {
            auto orientationAsInt = static_cast<unsigned int>(orientation);
            unsigned int
                shipEndX = x + (1 - orientationAsInt) * (size - 1),
                shipEndY = y + orientationAsInt * (size - 1);
            return  shipEndX < Constants::seaSizeX &&
                    shipEndY < Constants::seaSizeY;
        }
        return false;
    }

    // TODO Aufgabe 4:
    //  Definiert die Funktion `checkAndUpdateIncomingMissile(..)`.
    //  Nutzt die Funktionen von `Sea::Object`, um zu prüfen, ob die übergebene Rakete (`missile`) dieses Schiff trifft.
    //  Bei einem Treffer, markiert `missile` entsprechend.
    bool Ship::checkAndUpdateIncomingMissile(Missile &missile) {
        if(this->atCoordinates(missile)){
            ++this->numberOfHit;
            missile.hitSomething();
        }
        return missile.hasHitSomething();
    }
    // TODO Aufgabe 4:
    //  Prüft, ob alle Felder des Schiffs einmal getroffen wurden.
    //  (Tipp: Es können nie mehrere Raketen auf die gleichen Koordinaten geschossen werden.)
    bool Ship::isDestroyed() const
    {
        return this->numberOfHit == this->size;
    }
}
