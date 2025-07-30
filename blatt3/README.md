# Bewertung Blatt 03

## Aufgabe 1 (4 Pkt.)

1. in `.../src/`
    - `add_subdirectory(..)` wird korrekt genutzt (1 / 1 Pkt.)
2. in `.../src/app/`
    - `add_executable(..)` und `target_link_libraries(..)` werden korrekt genutzt (1 / 1 Pkt.)
3. in `.../src/libGameObjects/`
    - `add_library(..)`, `target_include_directories(..)`, `target_link_libraries(..)` werden korrekt genutzt (1 / 1 Pkt.)
4. in `.../src/libSea/`
    - `add_library(..)`, `target_include_directories(..)` werden korrekt genutzt (1 / 1 Pkt.)

## Aufgabe 2 (6 Pkt.)

1. `Object::atCoordinates(..)`:
    - Orientierung des Objekts wird korrekt berücksichtigt (1 / 1 Pkt.)
    - Alle Positionen des Objekts werden geprüft (1 / 1 Pkt.)
    - Die Funktion `Coordinates::samePositionAs(..)` wird genutzt (1 / 1 Pkt.)
2. `Object::intersectsWith(..)`:
    - Orientierung der Objekte wird korrekt berücksichtigt (1 / 1 Pkt.)
    - Alle Positionen der Objekte werden geprüft (0 / 1 Pkt.)
    - Die Funktion `Object::atCoordinates(..)` wird genutzt (1 / 1 Pkt.)

## Aufgabe 3 (8 Pkt.)

1. Klasse Missile
    - `namespace GameObjects {` (1 / 1 Pkt.)
    - `class Missile : public Sea::Coordinates` (1 / 1 Pkt.)
2. Konstruktor `Missile::Missile(..)`
    - Korrekt deklariert (1 / 1 Pkt.)
    - In Definition den Super-Konstruktor `Coordinates(..)` korrekt aufgerufen (1 / 1 Pkt.)
3. Funktion `Missile::hitSomething()`
    - Korrekt deklariert und definiert (1 / 1 Pkt.)
    - funktioniert (1 / 1 Pkt.)
4. Funktion `Missile::hasHitSomething()`
    - Korrekt deklariert und definiert (1 / 1 Pkt.)
    - funktioniert (1 / 1 Pkt.)

## Aufgabe 4 (3 Pkt.)

1. `checkAndUpdateIncomingMissile(..)`
    - Korrekt deklariert und definiert und funktioniert (1 / 1 Pkt.)
    - Nutzt `Object::atCoordinates(..)` (1 / 1 Pkt.)
2. `isDestroyed()`
    - funktioniert (1 / 1 Pkt.)

## Aufgabe 5 (3 Pkt.)

- Variable als `static` definiert (1 / 1 Pkt.)
- `static`-Variable wird innerhalb der Funktion definiert. (1 / 1 Pkt.)
- wird korrekt hochgezählt und ausgegeben (1 / 1 Pkt.)

## Aufgabe 6 (5 Pkt.)

1. `enum class AddShipResult`
    - Korrekt deklariert und mit 3 sinnvollen Werten definiert (2 / 2 Pkt.)
2. `addShip(..)`
    - Rückgabetyp der Funktion korrekt geändert (1 / 1 Pkt.)
    - korrekter Wert wird je nach Fall zurückgegeben (1 / 1 Pkt.)
3. `initializeShip(..)`
    - Korrekte Terminal-Ausgabe je nach Fall (1 / 1 Pkt.)

## Aufgabe 7 (5 Pkt.)

1. Includes in `app/init.cpp`
    - Sortiert nach externen und eigenen Header-Dateien (0.5 / 0.5 Pkt.)
    - `using`-Anweisungen jeweils bei den zugehörigen `#include`-Anweisungen (0.5 / 0.5 Pkt.)
2. Erklärung als Kommentar in `libGameObjects/Ship.cpp`
    - Die in der Datei definierten Funktionen sind im selben Namensraum (`GameObjects`) definiert (1 / 1 Pkt.)
3. Includes in `app/game.cpp`
    - Sortiert nach externen und eigenen Header-Dateien (0.5 / 0.5 Pkt.)
    - `using`-Anweisungen jeweils bei den zugehörigen `#include`-Anweisungen (0.5 / 0.5 Pkt.)
4. `gameLoop(..)`
    - in min. 2 Funktionen zerlegt (1 / 1 Pkt.)
    - Die Funktionen haben max. 7 Zeilen (Klammern und Leerzeilen zählen nicht) (1 / 1 Pkt.)

## Aufgabe 8 (Bonus) (3 Pkt.)

- Richtige Anzahl Zeilen und Spalten ( / 1 Pkt.)
- Raketen an den richtigen Positionen ( / 1 Pkt.)
- Raketen-Symbole passend dazu, ob es Treffer waren oder nicht ( / 1 Pkt.)

## Anmerkungen
- TODOs entfernen nach Bearbeitung
- Compiler Warnings entfernen!
- this-> ist nicht nötig, ein Objekt enthält seine eigenen Funktionen (Object.cpp atCoordinates())
- die Loops in intersectsWith() funktionieren nicht (Object.cpp)
- in PlayerSea.h keine ÄÜÖ etc. als enums verwenden
- Letzte Warnung: .idea im Hauptordner löschen
- fix gitignore

## Zusammenfassung

| Aufgabe | erreichte Pkt. | erreichbare Pkt. |
|--------:|---------------:|-----------------:|
|       1 |              4 |                4 |
|       2 |              5 |                6 |
|       3 |              8 |                8 |
|       4 |              3 |                3 |
|       5 |              3 |                3 |
|       6 |              5 |                5 |
|       7 |              5 |                5 |
|       8 |              0 |                3 |
|   Summe |             33 |               34 |