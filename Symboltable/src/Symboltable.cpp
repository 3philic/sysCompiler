/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Symboltable.h"

Symboltable::Symboltable() {
	this->hashmapPtr = new HashMap(1000);
	this->initSymbols();
}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
}

void Symboltable::initSymbols() {
	hashmapPtr->insertToken(new Token("int", intToken));

	hashmapPtr->insertToken(new Token("write", writeToken));
	hashmapPtr->insertToken(new Token("read", readToken));

	hashmapPtr->insertToken(new Token("else", ELSE));
	hashmapPtr->insertToken(new Token("ELSE", ELSE));

	hashmapPtr->insertToken(new Token("if", IF));
	hashmapPtr->insertToken(new Token("IF", IF));

	hashmapPtr->insertToken(new Token("while", WHILE));
	hashmapPtr->insertToken(new Token("WHILE", WHILE));
}

TType Symboltable::getTokenType(String lexem) {
	return this->hashmapPtr->getTokenType(lexem);
}

bool Symboltable::insertToken(Token* t) {
	return this->hashmapPtr->insertToken(t);
}

TokenInformation* Symboltable::getTokenInformation(String lexem) {
	return this->hashmapPtr->getTokenInformation(lexem);
}

