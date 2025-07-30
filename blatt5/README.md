# Bewertung Blatt 5

## Aufgabe 1 (6 Pkt.)

Der `operator<<`...
1. wurde korrekt deklariert (1 / 1 Pkt.)
2. wurde korrekt als `friend` von PlayerSea deklariert (1 / 1 Pkt.)
3. wurde korrekt definiert (1 / 1 Pkt.)
4. gibt den bisherigen Inhalt von `print()` in den übergebenen `stream` aus,
   statt nach `cout` (1 / 1 Pkt.)
5. wird in `game.cpp` korrekt verwendet (2 / 2 Pkt.)

## Aufgabe 2 (6 Pkt.)

1. Alte Funktionen `send__Missile(..)` sind gelöscht (1 / 1 Pkt.)
2. Korrekte Deklarationen der Funktion `sendMissile<T>(..)` (1 / 1 Pkt.)
3. Korrekte Definition der Funktion `sendMissile<T>(..)`:
    - Mit dem Template-Parameter wird jeweils der korrekte Raketenname übergeben (1 / 1 Pkt.)
    - Mit dem Template-Parameter wird jeweils der korrekte Raketentyp erzeugt (1 / 1 Pkt.)
    - Es werden keine zusätzlichen Code-Ausdrücke (z.B. extra `if` o.ä.) verwendet (1 / 1 Pkt.)
4. Korrekte Verwendung der Funktion in selectTypeAndSendMissile(..) (1 / 1 Pkt.)

## Aufgabe 3 (28 Pkt.)

1. Template-Klasse korrekt angelegt (1 / 1 Pkt.)
2. Member-Variable `grid` nutzt den Template-Parameter (1 / 1 Pkt.)
3. Konstruktor ...
    - sind korrekt deklariert und definiert (1 / 1 Pkt.)
    - wirft eine Exception, wenn `sizeX` < 1 oder `sizeY` < 1 (1 / 1 Pkt.)
4. `sizeX()` und `sizeY()` ...
    - sind korrekt deklariert (2 / 2 Pkt.)
    - sind korrekt definiert (2 / 2 Pkt.)
    - liefern jeweils korrekten Wert (2 / 2 Pkt.)
5. `operator[]` und `operator()` ...
    - sind korrekt deklariert (4 / 4 Pkt.)
    - sind korrekt definiert (3 / 4 Pkt.)
    - werfen für ungültige Koordinaten eine Exception (4 / 4 Pkt.)
6. Die Klasse wird korrekt in der Deklaration von `OutputGrid` genutzt (1 / 1 Pkt.)
7. Die Instanz `gridOwnSea` wird in `PlayerSea.h` korrekt initialisiert (1 / 1 Pkt.)
8. Die Operatoren werden im restlichen Code korrekt genutzt (4 / 4 Pkt.)

## Aufgabe 4 (Bonus) (2 Pkt.)

Richtige Antwort (0 / 2 Pkt.)

## Anmerkungen
- TODOs entfernen!
- Auskommentierter Code kann am Ende gelöscht werden
- Vermeidet Compiler Warnings
- A3: In Grid2D.inl bei der Operatorüberladung sind die x- und y-Koordinaten vertauscht
- A4: Ja, die Werte werden in Funktionen verändert, aber warum kann man die Operatoren ohne const woanders nicht aufrufen?

## Zusammenfassung

| Aufgabe | erreichte Pkt. | erreichbare Pkt. |
|--------:|---------------:|-----------------:|
|       1 |              6 |                6 |
|       2 |              6 |                6 |
|       3 |             27 |               28 |
|       4 |              0 |                2 |
|   Summe |             39 |               40 |

Ihr habt insgesamt 47,8 % der Studienleistung bis jetzt. Es kommen noch 4 weitere Hausaufgabenblätter

