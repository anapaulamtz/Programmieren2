#include "euroCheck.h"
#include <iostream>


using std::string;

//bool istRichtigeFormat(string & serialNumber);
bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);
int rechnenQuersummeOfBuchstaben(int character);
int ersteBuchstabeToNumber;
int zweiteBuchstabeToNumber;
int pruefZiffer;
int quersumme;
int neunerRest;
int summe;
int substractedNummer;

// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
int getEuroSerialNumberVersion(string & serialNumber) {
    if(isLetter(serialNumber[0]) && isLetter(serialNumber[1])){
        return 2013;
    } else if(isNumber(serialNumber[1]) && isLetter(serialNumber[0])) {
        return 2002;
    } else {
        return 0;
    }
}
// TODO Aufgabe 7:
//  Implementiert die Funktion `istRichtigeFormat(serialNumber)`.
//  Check die Länge der Seriennummer, ob das erste Character eine Buchstabe, ob das zweite Buchstabe eine Buchstabe oder Nummer, ob andere Characters auch Nummer.
//bool istRichtigeFormat(string & serialNumber){
  //  bool isFormat = false;
    //int serialNumberVersion = getEuroSerialNumberVersion(serialNumber);
    //if((serialNumber.size() == 12) && (serialNumberVersion == 0)){
      //  for(int i = 2; i < serialNumber.size(); ++i){
        //    if(isNumber(serialNumber[i])){
          //     isFormat = true;
           // }  else {
             //   isFormat = false;
               // break;
            //}
//}
  //  }
    //return isFormat;
//}

// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format: L NNNNNNNNNN N
//  (Leerzeichen im Format werden vom Nutzer nicht mit eingegeben, sondern helfen hier nur beim Zählen)
//  Tipp: `x / 10` liefert die Zehnerstelle und `x % 10` die Einerstelle einer zweistelligen Zahl x.
bool checkEuroSerialNumber2002(string & serialNumber){
    ersteBuchstabeToNumber = toNumber(serialNumber[0]);
    summe = rechnenQuersummeOfBuchstaben(ersteBuchstabeToNumber);
    for(int i = 1; i < 11;++i){
        summe = summe + toNumber(serialNumber[i]);
    }
    neunerRest = summe % 9;
    substractedNummer = 8 - neunerRest;
    if(substractedNummer == 0){
        pruefZiffer = 9;
    } else {
        pruefZiffer = substractedNummer;
    }

    int pz= serialNumber[11]- '0';
    if(pruefZiffer == pz) {
        return true;
    }
    return false;
}

// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format: LL NNNNNNNNN N
bool checkEuroSerialNumber2013(string & serialNumber){
    ersteBuchstabeToNumber = toNumber(serialNumber[0]);
    zweiteBuchstabeToNumber = toNumber(serialNumber[1]);
    summe = rechnenQuersummeOfBuchstaben(ersteBuchstabeToNumber) + rechnenQuersummeOfBuchstaben(zweiteBuchstabeToNumber);
    for(int i = 2; i < 11;++i){
        summe = summe + toNumber(serialNumber[i]);
    }
    neunerRest = summe % 9;
    substractedNummer = 7 - neunerRest;
    switch(substractedNummer){
        case 0:
            pruefZiffer = 9;
            break;
        case -1:
            pruefZiffer = 8;
            break;
        default:
            pruefZiffer = substractedNummer;
            break;
    }
    if(pruefZiffer == toNumber(serialNumber[11])) {
        return true;
    }
    return false;
}

// L
bool isLetter(char c) {
    return 'A' <= c && c <= 'Z';
}
//
bool isNumber(char c) {
    return '0' <= c && c <= '9';
}
int toNumber(char c) {
    if (isNumber(c)) {
        return c - '0';
    }
    if (isLetter(c)) {
        return c - 'A' + 1;
    }
    std::cout << "Error: toNumber(char): " << c << std::endl;
    return 0;
}


int rechnenQuersummeOfBuchstaben(int character){
    return (character/10) + (character % 10);
}
