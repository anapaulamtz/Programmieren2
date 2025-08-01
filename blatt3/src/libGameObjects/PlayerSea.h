#ifndef BLATT3_PLAYERSEA_H
#define BLATT3_PLAYERSEA_H


#include <string>

#include <vector>


#include "Ship.h"
#include "Missile.h"


namespace GameObjects {

    class PlayerSea {
    private:
        std::string playerName;
        std::vector<Ship> ships;
#ifdef CLASS_MISSILE_COMPLETE
        std::vector<Missile> missilesSent;

        bool receiveMissile(Missile & missile);
        std::vector<std::vector<std::string>> sea;

#endif

    public:
        PlayerSea(std::string const & newPlayerName);

        std::string const & getPlayerName() const;

        std::vector<std::vector<std::string>> & GetSea();

        void SetSea(Sea::Coordinates &missile, std::string zeichen);

        static std::string printSeaArea();

        bool overlapWithExistingShips(Ship const & otherShip) const;

        // TODO Aufgabe 6:
        //  Erweitert `addShip(..)` so, dass nicht nur ein `bool`, sondern ein Statuswert (`enum class`) zurückgegeben wird.
        //  Dieser soll nicht nur angeben ob, sondern auch warum ein Schiff nicht hinzugefügt werden konnte.
        enum class AddShipResult {
            EFOLGREICH_HINZUGEFÜGT,
            AUßERHALB_DES_SPIELFELDS,
            ÜBERSCHNEIDUNG_MIT_ANDEREM_SHIFF
        };

        AddShipResult addShip(Ship const & ship);

        bool sendMissileTo(PlayerSea & otherSea, Sea::Coordinates const & targetCoordinates);
        bool missileAlreadySentTo(Sea::Coordinates const & targetCoordinates) const;

        bool allShipsDestroyed() const;
    };

}


#endif //BLATT3_PLAYERSEA_H
