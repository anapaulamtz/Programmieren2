#include "Ship.h"

#include "PlayerSea.h"


namespace GameObjects {

    bool Ship::isInsideSeaBounds() const
    {
        if (PlayerSea::isInsideSeaBounds(*this)) {
            auto orientationAsInt = static_cast<unsigned int>(orientation);
            Coordinates shipEnd(
                x + (1 - orientationAsInt) * (size - 1),
                y + orientationAsInt * (size - 1));
            return PlayerSea::isInsideSeaBounds(shipEnd);
        }
        return false;
    }

    void Ship::checkHits(Missile & missile)
    {
        for (unsigned int i = 0; i < size; ++i) {
            Coordinates shipHitPosition = (orientation == Sea::Orientation::X)
                    ? Coordinates(x + i, y)
                    : Coordinates(x, y + i);
            if (missile.checkHit(shipHitPosition)) {
                // TODO Aufgabe 2:
                missileHitPositions.insert(shipHitPosition);
            }
        }
    }

    bool Ship::isDestroyed() const
    {
        // TODO Aufgabe 2:
        //  Der Test, ob das Schiff versenkt wurde, ist nun mit einem einzelnen Vergleich möglich.
      /*  for (unsigned int i = 0; i < size; ++i) {
            Coordinates coordinates = (orientation == Sea::Orientation::X)
                    ? Coordinates(x + i, y)
                    : Coordinates(x, y + i);
            if (!wasHitAt(coordinates)) {
                return false;
            }
        }
        return true;*/
        return missileHitPositions.size() == size;
    }

    bool Ship::wasHitAt(Sea::Coordinates coordinates) const
    {
        for (auto const & missileHitPosition : missileHitPositions) {
            if (missileHitPosition == coordinates) {
                return true;
            }
        }
        return false;
    }

    void Ship::output(OutputGrid & grid) const
    {
        for (unsigned int i = 0; i < size; ++i) {
            auto & cell = (orientation == Sea::Orientation::X)
                    ? grid(x + i, y)
                    : grid(x, y + i);
            cell.ship = true;
            cell.output = " X  ";
        }
    }

}
