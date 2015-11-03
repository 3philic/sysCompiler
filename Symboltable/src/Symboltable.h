/*
 * Symboltable.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "HashMap.h"
#include "../../TType.h"

class Symboltable {
public:
	HashMap* hashmapPtr;

	Symboltable();
	virtual ~Symboltable();

	void initSymbols();

	TType getTokenType(String lexem);
	bool insertToken(Token* t);

};

#endif /* SYMBOLTABLE_H_ */
