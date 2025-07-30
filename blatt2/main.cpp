#include <iostream>


// TODO Aufgabe 3:
//  Inkludiert die Datei `euroCheck.h`.

#include "euroCheck.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;

// TODO Aufgabe 1:
//  Definiert die Funktion `inputNextSerialNumber()` so, dass sie eine Seriennummer als `string` auf der Konsole einliest und diese zurückgibt.
string inputNextSerialNumber(){
    string serienNummer;
    cout << "Geben Sie bitte ein Seriennummer" << endl;
    cin >> serienNummer;
    return serienNummer;
}

// TODO Aufgabe 3:
//  Implementiert die Funktion `checkSerialNumberAndPrintResult(serialNumber)`.
//  Sie soll mithilfe der Funktion `getEuroSerialNumberVersion(serialNumber)` ermitteln, um welche Version einer Euro-Banknote es sich handelt, und die entsprechende Jahreszahl in der Konsole ausgeben.
//  Anschliessend soll in einer Fallunterscheidung (switch) anhand der Jahreszahl die entsprechende Funktion `checkEuroSerialNumber2013/2002(serialNumber)` aufgerufen und das Ergebnis (Gueltig/Ungueltig) auf der Konsole ausgeben werden.
void checkSerialNumberAndPrintResult(string & serialNumber) {
    bool gueltig = false;
    int version = getEuroSerialNumberVersion(serialNumber);
    switch(version){
        case 2002:
            gueltig = checkEuroSerialNumber2002(serialNumber);
            break;
        case 2013:
            gueltig = checkEuroSerialNumber2013(serialNumber);
            break;
        default:
            break;
    }
    if(gueltig){
        cout << "die Seriennummer ist gueltig und hat die Version "<< version <<endl;
    } else {
        cout << "Ungueltig" << endl;
    }
}

int main() {
    // TODO Aufgabe 4:
    //  Nutzt eine Kontrollstruktur, sodass nacheinander beliebig viele Seriennummern geprüft werden können.
    while (true) {
        // TODO Aufgabe 1:
        //  Ruft `inputNextSerialNumber()` auf, um eine Seriennummer einzugebeninputNextSerialNumber();
        string serialNumber = inputNextSerialNumber();
        // TODO Aufgabe 4:
        //  Das Programm soll beendet werden, wenn statt einer Seriennummer "fertig" eingegeben wurde.
        if (serialNumber == "fertig") {
            break;
        }
        checkSerialNumberAndPrintResult(serialNumber);
    }
    return 0;
}


