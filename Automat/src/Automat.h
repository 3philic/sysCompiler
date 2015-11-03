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

	static const int zustandUebergangTabelle[21][28];
	//static const int a[3][4];

	int aktuellerZustand;
	int transformChar(char c);
	//bool errorbool;
public:
	Automat();
	virtual ~Automat();
	TType checkChar(char c);

};

#endif /* Automat_H_ */
