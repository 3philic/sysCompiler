/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_

#include "../../TType.h"

class Automat {

private:

    int aktuellerZustand;

    int transformChar(char c);
    //bool errorbool;
public:
    Automat();

    virtual ~Automat();

    TType checkChar(char c);

    static const int eDigit;
    static const int eLexem;
    static const int ePlus;
    static const int eMinus;
    static const int eDoppelPunkt;
    static const int eStern;
    static const int eKleiner;
    static const int eGroesser;
    static const int eGleich;
    static const int eDoppelPunktGleich;
    static const int eUngleich;
    static const int eAusrufeZeichen;
    static const int eUndUnd;
    static const int eStrichPunkt;
    static const int eRundKlaAuf;
    static const int eRundKlaZU;
    static const int eGeschwKlaAuf;
    static const int eGeschwKlaZu;
    static const int eEckKlaAuf;
    static const int eEckKlaZu;
    static const int zDigit;
    static const int zLexem;
    static const int zPlus;
    static const int zMinus;
    static const int zDoppelPunkt;
    static const int zStern;
    static const int zKleiner;
    static const int zGroesser;
    static const int zGleich;
    static const int zDoppelPunktGleich;
    static const int zAusrufeZeichen;
    static const int zUndUnd;
    static const int zStrichPunkt;
    static const int zRundKlaAuf;
    static const int zRundKlaZU;
    static const int zGeschwKlaAuf;
    static const int zGeschwKlaZu;
    static const int zEckKlaAuf;
    static const int zEckKlaZu;
    static const int anfang;
    static const int zUngleichStart;
    static const int zUngleichFailed;
    static const int zUnd;
    static const int eError;
    static const int zUngleichSuccess;
    static const int zustandUebergangTabelle[20][27];
    static const int zKommentarAnfang;
    static const int zKommentarEnde;
    static const int eKommentar;
    static const int zKommentar;
};

#endif /* Automat_H_ */
