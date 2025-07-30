# Bewertung Blatt 04

## Aufgabe 1 (8 Pkt.)

1. PlayerSea.h enthält korrekte Deklarationen von
    - missilesSent/missilesReceived (1 / 1 Pkt.)
    - `receiveMissile(..)` (1 / 1 Pkt.)
    - `sendMissileTo(..)` (1 / 1 Pkt.)
2. PlayerSea.cpp
    - `sendMissileTo(..)`
        - Definition (1 / 1 Pkt.)
        - Pointer-Nutzung von missile (1 / 1 Pkt.)
    - `receiveMissile(..)`
        - Definition (1 / 1 Pkt.)
        - Pointer-Nutzung von missile (1 / 1 Pkt.)
3. game.cpp
    - `sendRegularMissileTo(..)` (1 / 1 Pkt.)

## Aufgabe 2 (8 Pkt.)

1. Definition einer oder zweier eigener Exception-Klasse(n), abgeleitet von `std::exception` (1 / 1 Pkt.)
2. `enum class AddShipResult` wurde entfernt (ungenutzter Code) (1 / 1 Pkt.)
3. `addShip(..)`
    - wirft unterscheidbare Exceptions für die Fehlerfälle ... (2 / 2 Pkt.)
        - `outsideSeaBounds`
        - `overlapOtherShip`
    - Fügt das Schiff nur hinzu, wenn kein Fehler aufgetreten ist (1 / 1 Pkt.)
4. `initializeShip(..)`
    - Alle Exceptions aus `addShip(..)` werden aufgefangen (1 / 1 Pkt.)
    - Je nach Fehlerfall wird die korrekte Meldung ausgegeben (1 / 1 Pkt.)
    - Im Fehlerfall liefert die Funktion den Rückgabewert `false` (1 / 1 Pkt.)

## Aufgabe 3 (9 Pkt.)

1. `TumblingMissile.h` enthält korrekte override-Deklarationen von
    - `getX()` (0 / 1 Pkt.)
    - `getY()` (0 / 1 Pkt.)
    - `toString()` (0 / 1 Pkt.)
2. `TumblingMissile.cpp`
    - `getX()` und `getX()`
        - Liefern jeweils das korrekte Ergebnis. (2 / 2 Pkt.)
    - `toString()`
        - Gibt beide Positionen (ohne und mit Abweichung) korrekt aus. (0.5 / 1 Pkt.)
        - Nutzt die Funktion `Coordinates::toString()`, um Code nicht doppelt zu implementieren. (0 / 1 Pkt.)
3. `game.cpp`
    - `sendTumblingMissileTo(..)` erzeugt eine TumblingMissile und gibt sie an
      `PlayerSea::sendMissileTo(..)` (1 / 1 Pkt.)
    - `gameTurn(..)` ruft für ungerade Runden `sendRegularMissileTo(..)` auf und für gerade Runden
      `sendTumblingMissileTo(..)` oder umgekehrt (1 / 1 Pkt.)

## Aufgabe 4 (6 Pkt.)

1. `operator==(..)`
    - Deklaration (0 / 1 Pkt.)
    - Definition (0 / 1 Pkt.)
    - Nutzung in `checkHit(..)` in `Missile.cpp` und in `wasHitAt(..)` in `Ship.cpp` (0 / 1 Pkt.)
2. `operator<<(..)`
    - Deklaration (0 / 1 Pkt.)
    - Definition (0 / 1 Pkt.)
    - Nutzung im Konstruktor `Missile(Coordinates ..)` (0 / 1 Pkt.)

## Aufgabe 5 (Bonus) (3 Pkt.)

1. Weitere Raketenklasse erstellt, die von `Missile` erbt (0 / 1 Pkt.)
2. Verhalten unterscheidet sich von den beiden vorherigen Raketentypen (0 / 1 Pkt.)
3. Einbindung in `gameTurn(..)` (0 / 1 Pkt.)

## Anmerkungen
- TODOs entfernen!
- Löscht Änderungen, statt sie auszukommentieren
- A3: die Funktionen von missile() benötigen das Tag override, damit sie kompatibel sind.

## Zusammenfassung

| Aufgabe | erreichte Pkt. | erreichbare Pkt. |
|--------:|---------------:|-----------------:|
|       1 |              8 |                8 |
|       2 |              8 |                8 |
|       3 |            4.5 |                9 |
|       4 |              0 |                6 |
|       5 |              0 |                3 |
|   Summe |           20.5 |               31 |
