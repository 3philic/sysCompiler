/*
 * Token.h
 *
 *  Created on: Apr 6, 2014
 *      Author: 3philic
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include "TType.h"
#include "TokenInformation.h"
#include "String.h"

class Token {
public:
	Token(String lexem, TType type);
	Token(String lexem, TType type, int lineNo, int columnNo);
	Token(String lexem, TType type, int value, int lineNo, int columnNo);
	~Token();

	TType type;
	String lexem;
	int* value;	//wird nur gesetzt, falls Token einen Wert besitzen kann
	int lineNo;
	int columnNo;

	bool equals(String lexem);
	int hashCode();

	TokenInformation* getInformation();
	void setInformation(TokenInformation *information);

private:
	TokenInformation *tokenInformation;
};

#endif /* TOKEN_H_ */
