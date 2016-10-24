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
	 //37(sonderfall) & >100 sind endzustände 101=intiger, 102=lexem, 103=if, 104=while, 105-122=signs, 123=kommentar

	static const int zustandUebergangTabelle[21][29];
	//static const int a[3][4];

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
    static const int zUngleich1;
    static const int zUngleich2;
    static const int zUnd;
    static const int eError;
};

#endif /* Automat_H_ */
