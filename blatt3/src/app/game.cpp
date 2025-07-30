#include "game.h"

// TODO Aufgabe 7:
//  Bringe die `include`- und `using`-Anweisungen in eine sinnvolle Ordnung.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "Coordinates.h"
using Sea::Coordinates;

#include "init.h"

#include "Constants.h"
using GameObjects::Constants;


void fireMissile(PlayerSea &currentPlayerSea, PlayerSea &otherPlayerSea);

bool isGameFinished(const PlayerSea &currentPlayerSea, const PlayerSea &otherPlayerSea);

void printRakete(vector<vector<string>> &seaOfAttackedPlayer, PlayerSea &attackedPlayer);

// TODO Aufgabe 7:
//  Zerlege die Funktion `gameLoop(..)` in sinnvolle, kürzere Teilfunktionen.
void gameLoop(vector<PlayerSea> & playerSeas)
{
    cout << endl << "Los geht's!" << endl;
    for (unsigned int round = 0;; ++round) {
        PlayerSea & currentPlayerSea = playerSeas[round % 2];
        PlayerSea & otherPlayerSea = playerSeas[(round + 1) % 2];
        fireMissile(currentPlayerSea, otherPlayerSea);

        if (isGameFinished(currentPlayerSea, otherPlayerSea)) {
            break;
        }
    }
}

bool isGameFinished(const PlayerSea &currentPlayerSea, const PlayerSea &otherPlayerSea) {
    bool gameFinished = false;
    if (otherPlayerSea.allShipsDestroyed()) {
        cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
             << currentPlayerSea.getPlayerName() << " hat gewonnen." << endl;
        gameFinished = true;
    }
    return gameFinished;
}

void fireMissile(PlayerSea &currentPlayerSea, PlayerSea &otherPlayerSea) {
    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea);
    bool hit = currentPlayerSea.sendMissileTo(otherPlayerSea, targetCoordinates);
    if (hit) {
        cout << "Treffer!" << endl;
        otherPlayerSea.SetSea(targetCoordinates, "X");
        printRakete(otherPlayerSea.GetSea(), otherPlayerSea);
    }
    else {
        cout << "Daneben!" << endl;
        otherPlayerSea.SetSea(targetCoordinates, "O");
        printRakete(otherPlayerSea.GetSea(), otherPlayerSea);
    }
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea)
{
    while (true) {
        cout << endl << currentPlayerSea.getPlayerName() << " zielt auf" << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (currentPlayerSea.missileAlreadySentTo(targetCoordinates)) {
            cout << "Diese Koordinaten hast du schon probiert." << endl;
            continue;
        }
        return targetCoordinates;
    }
}

void printRakete(vector<vector<string>> &seaOfAttackedPlayer, PlayerSea &attackedPlayer){
    cout << "Sea of " << attackedPlayer.getPlayerName() << ":" << endl;
    for(vector<string> i : seaOfAttackedPlayer){
        for(string j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
