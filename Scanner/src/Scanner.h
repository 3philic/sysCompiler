/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "../../Token.h"
#include "../../TType.h"
#include "../../String.h"
#include "../../Automat/src/Automat.h"
#include "../../Buffer/src/Buffer.h"
//#include "DummyBuffer.h"/
#include "../../Symboltable/src/Symboltable.h"

class Scanner {
public:
	Scanner(char* argv);
	virtual ~Scanner();
	Token* nextToken();

private:
	char charCache;
	int lineCache;
	int columnCache;
	TType returned_from_automat;
	String* stringCache;
	bool stop;

	Automat* automat;
	Buffer* buffer;
	Symboltable* symboltable;

	// setzt die Positionsmarker auf den aktuellen Wert (den der Buffer angibt)
	void updatePositionMarkers();
};

#endif /* SCANNER_H_ */
