#include "PlayerSea.h"

#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include "Constants.h"


namespace GameObjects {

    string const spaceX = "          ";
    unsigned int const seaCellSizeX = 4;

    // TODO Aufgabe 1:
   /* void PlayerSea::print() const
    {
        cout << endl;
        printHeader(cout);
        for (unsigned int y = 0; y < Constants::seaSizeY; ++y) {
            printLine(cout, y);
        }
        printHorizontalBorder(cout);
        cout << endl;
    }*/

    void PlayerSea::printHeader(ostream & stream) const
    {
        stream << "     "
               << playerName
               << string(Constants::seaSizeX * seaCellSizeX - playerName.length(),' ')
               << spaceX
               << "Gegner" << endl
               << "  ";
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            stream << setw(seaCellSizeX) << x;
        }
        stream << spaceX;
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            stream << setw(seaCellSizeX) << x;
        }
        stream << endl;
        printHorizontalBorder(stream);
    }

    void PlayerSea::printLine(ostream & stream, unsigned int y) const
    {
        stream << setw(2) << y << " |";
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            stream << gridOwnSea(x, y).output;
        }
        stream << spaceX;
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            stream << gridOtherSea(x, y).output;
        }
        stream << " | " << y << endl;
    }

    void PlayerSea::printHorizontalBorder(ostream & stream)
    {
        stream << "    "
               << string(Constants::seaSizeX * seaCellSizeX * 2 + spaceX.length() + 1, '-')
               << endl;
    }

}
// TODO Aufgabe 1:
//  Implementiert hier `operator<<`.
ostream & operator<<(ostream & stream, GameObjects::PlayerSea const & playersea)
{
    stream << endl;
    playersea.printHeader(stream);
    for (unsigned int y = 0; y < GameObjects::Constants::seaSizeY; ++y) {
        playersea.printLine(stream, y);
    }
    playersea.printHorizontalBorder(stream);
    stream << endl;
    return stream;
}

