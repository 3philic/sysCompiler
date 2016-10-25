/*
 * Automat.cpp
 *
 */

#include "Automat.h"

const int Automat::zustandUebergangTabelle[21][29] = {
//       0   1    2     3    4    5    6    7    8    9   10   11    12   13   14   15   16   17   18   19  20   21   22   23  24  25   26  27   28
        {1,  1,   2,   103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {2,  101, 2,   103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {3,  101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {4,  101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {5,  101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 26, 122, 120, 110},
        {6,  101, 102, 103, 104, 24,  106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 25, 25, 122, 120, 110},
        {7,  101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {8,  101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 22, 120, 119, 121, 24, 24, 122, 120, 110},
        {9,  101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 19,  118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {10, 101, 102, 103, 104, 105, 106, 107, 108, 109, 28,  111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {11, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {12, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {13, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {14, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {15, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {16, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {17, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {0,  101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {18, 101, 102, 103, 104, 105, 106, 20,  108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {27, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110},
        {23, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 111, 112, 113, 114, 115, 116, 117, 120, 118, 21, 120, 119, 121, 24, 24, 122, 120, 110}
};

const int Automat::eDigit = 101;
const int Automat::eLexem = 102;
const int Automat::ePlus = 103;
const int Automat::eMinus = 104;
const int Automat::eDoppelPunkt = 105;
const int Automat::eStern = 106;
const int Automat::eKleiner = 107;
const int Automat::eGroesser = 108;
const int Automat::eGleich = 109;
const int Automat::eDoppelPunktGleich = 110;
const int Automat::eUngleich = 111;
const int Automat::eAusrufeZeichen = 112;
const int Automat::eUndUnd = 113;
const int Automat::eStrichPunkt = 114;
const int Automat::eRundKlaAuf = 115;
const int Automat::eRundKlaZU = 116;
const int Automat::eGeschwKlaAuf = 117;
const int Automat::eGeschwKlaZu = 118;
const int Automat::eEckKlaAuf = 119;
const int Automat::eEckKlaZu = 120;
const int Automat::eError = 121;

const int Automat::anfang = 0;
const int Automat::zDigit = 1;
const int Automat::zLexem = 2;
const int Automat::zPlus = 3;
const int Automat::zMinus = 4;
const int Automat::zDoppelPunkt = 5;
const int Automat::zStern = 6;
const int Automat::zKleiner = 7;
const int Automat::zGroesser = 8;
const int Automat::zGleich = 9;
const int Automat::zDoppelPunktGleich = 10;
const int Automat::zAusrufeZeichen = 11;
const int Automat::zStrichPunkt = 12;
const int Automat::zRundKlaAuf = 13;
const int Automat::zRundKlaZU = 14;
const int Automat::zGeschwKlaAuf = 15;
const int Automat::zGeschwKlaZu = 16;
const int Automat::zEckKlaAuf = 17;
const int Automat::zEckKlaZu = 18;
const int Automat::zUnd = 19;
const int Automat::zUndUnd = 20;
const int Automat::zUngleichStart = 21;
const int Automat::zUngleichFailed = 22;
const int Automat::zUngleichSuccess = 23;


const int Automat::zustandUebergangTabelle1[21][29] = {
//                   anfang           zDigit   zLexem  zPlus  zMinus zDoppelPunkt         zStern  zKleiner  zGrößer    zGleich        zDoppelpunktGleich  zAusrufezeihen   zStrichpunkt  zRundeklaAuf zRundKlaZU  zGeschwKlaAuf  zGeschwKlaZu   zEckKlaAuf zEckKlaZu zUnd     zUndUnd   zUngleichStart zUngleichFailed zUngleichSuccess  24  25   26  27   28
/* Zahlen */        {zDigit,          1,      2,      ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* Buchstaben */
                    {zLexem,          eDigit, 2,      ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* + */
                    {zPlus,           eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* - */
                    {zMinus,          eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* : */
                    {zDoppelPunkt,    eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, zUngleichStart, eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* * */
                    {zStern,          eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* < */
                    {zKleiner,        eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* > */
                    {zGroesser,       eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* = */
                    {zGleich,         eDigit, eLexem, ePlus, eMinus, zDoppelPunktGleich, eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichSuccess, zDoppelPunkt, eUngleich},
/* ! */
                    {zAusrufeZeichen, eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* & */
                    {zUnd,            eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, zUndUnd, eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* ; */
                    {zStrichPunkt,    eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* ( */
                    {zRundKlaAuf,     eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* ) */
                    {zRundKlaZU,      eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* { */
                    {zGeschwKlaAuf,   eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* } */
                    {zGeschwKlaZu,    eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* [ */
                    {zEckKlaAuf,      eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/* ] */
                    {zEckKlaZu,       eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich},
/*   */
                    {anfang,          eDigit, eLexem, ePlus, eMinus, eDoppelPunkt,       eStern, eKleiner, eGroesser, eGleich,        eDoppelPunktGleich, eAusrufeZeichen, eStrichPunkt, eRundKlaAuf, eRundKlaZU, eGeschwKlaAuf, eGeschwKlaZu, eEckKlaAuf, eEckKlaZu, eError,  eUndUnd, zUngleichFailed,  zDoppelPunkt, eUngleich}


};

Automat::Automat() {
    this->aktuellerZustand = 0;
//	this->zustandUebergangTabelle[0][0] = 0;


}

Automat::~Automat() {
    // TODO Auto-generated destruct
}

int Automat::transformChar(char c) {// automatenlogic Todo: ereignisse bei endzuständen erstellen
    int eingabe;// im folgenden wird der c einem int-wert zugewiesen um in der tabelle abzufragen

    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' ||
        c == '9')
        eingabe = 0;
    else if (c == 'A' || c == 'a' || c == 'B' || c == 'b' || c == 'C' || c == 'c' || c == 'D' || c == 'd' || c == 'E' ||
             c == 'e' || c == 'F' || c == 'f' ||
             c == 'G' || c == 'g' || c == 'H' || c == 'h' || c == 'I' || c == 'i' || c == 'J' || c == 'j' || c == 'K' ||
             c == 'k' || c == 'L' || c == 'l' ||
             c == 'M' || c == 'm' || c == 'N' || c == 'n' || c == 'O' || c == 'o' || c == 'P' || c == 'p' ||
             c == 'Q' || c == 'q' || c == 'R' || c == 'r' || c == 'S' || c == 's' || c == 'T' || c == 't' || c == 'U' ||
             c == 'u' || c == 'V' || c == 'v' || c == 'W' || c == 'w' ||
             c == 'X' || c == 'x' || c == 'Y' || c == 'y' || c == 'Z' || c == 'z')
        eingabe = 1;
    else if (c == '+')eingabe = 2;
    else if (c == '-')eingabe = 3;
    else if (c == ':')eingabe = 4;
    else if (c == '*')eingabe = 5;
    else if (c == '<')eingabe = 6;
    else if (c == '>')eingabe = 7;
    else if (c == '=')eingabe = 8;
    else if (c == '!')eingabe = 9;
    else if (c == '&')eingabe = 10;
    else if (c == ';')eingabe = 11;
    else if (c == '(')eingabe = 12;
    else if (c == ')')eingabe = 13;
    else if (c == '{')eingabe = 14;
    else if (c == '}')eingabe = 15;
    else if (c == '[')eingabe = 16;
    else if (c == ']')eingabe = 17;
    else if (c == ' ')eingabe = 18;
    else eingabe = 19;

    return eingabe;

}

TType Automat::checkChar(char c) {

    Automat::aktuellerZustand = zustandUebergangTabelle1[Automat::transformChar(c)][aktuellerZustand];
    //if(errorbool=false)
    switch (Automat::aktuellerZustand) {
        case (eDigit):
            aktuellerZustand = 0;
            return integer;
        case (eLexem):
            aktuellerZustand = 0;
            return lexem;
        case (ePlus):
            aktuellerZustand = 0;
            return plusToken;
        case (eMinus):
            aktuellerZustand = 0;
            return minusToken;
        case (eDoppelPunkt):
            aktuellerZustand = 0;
            return doppelpunkt;
        case (eStern):
            aktuellerZustand = 0;
            return stern;
        case (eKleiner):
            aktuellerZustand = 0;
            return kleiner;
        case (eGroesser):
            aktuellerZustand = 0;
            return groesser;
        case (eGleich):
            aktuellerZustand = 0;
            return gleich;
        case (eDoppelPunktGleich):
            aktuellerZustand = 0;
            return doppeltpunktGleich;
        case (eUngleich):
            aktuellerZustand = 0;
            return ungleich;
        case (eAusrufeZeichen):
            aktuellerZustand = 0;
            return ausrufezeichen;
        case (eUndUnd):
            aktuellerZustand = 0;
            return undund;
        case (eStrichPunkt):
            aktuellerZustand = 0;
            return semikolon;
        case (eRundKlaAuf):
            aktuellerZustand = 0;
            return rundeKlammerAuf;
        case (eRundKlaZU):
            aktuellerZustand = 0;
            return rundeKlammerZu;
        case (eGeschwKlaAuf):
            aktuellerZustand = 0;
            return geschweifteKlammerAuf;
        case (eGeschwKlaZu):
            aktuellerZustand = 0;
            return geschweifteKlammerZu;
        case (eEckKlaAuf):
            aktuellerZustand = 0;
            return eckigeKlammerAuf;
        case (eEckKlaZu):
            aktuellerZustand = 0;
            return eckigeKlammerZu;
        case (zUngleichFailed) :
            return gleich;
        case (eError):
            aktuellerZustand = 0;
            return error;
//        case (122):
//            aktuellerZustand = 0;
//            return kommentar;
        default:
            return null;
    }
    //else return error;
}
