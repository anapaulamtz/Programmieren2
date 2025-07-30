
// Hinweis: Da diese .inl-Datei in einer h-Datei inkludiert wird, dürfen hier (im Vergleich zu cpp-Dateien) darf/sollte hier kein `using ..` verwendet werden.
#include "PlayerSea.h";
#include <memory>;

// TODO Aufgabe 2:
//  Implementiert hier die Template-Funktion `sendMissile<MissileType>(..)`.
template <class T>
bool sendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea)
{
    Sea::Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea, T::getName());
    auto missile = std::make_shared<T>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}

