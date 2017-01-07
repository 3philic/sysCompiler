/*
 * Token.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: 3philic
 */

#include "Token.h"

Token::Token(String lexem, TType type) {
	this->lexem = lexem;
	this->type = type;
	this->value = 0;
	this->lineNo = 0;
	this->columnNo = 0;
}

Token::Token(String lexem, TType type, int lineNo, int columnNo) {
	this->lexem = lexem;
	this->type = type;
	this->value = 0;
	this->lineNo = lineNo;
	this->columnNo = columnNo;
}

Token::Token(String lexem, TType type, int value, int lineNo, int columnNo) {
	this->lexem = lexem;
	this->type = type;

	this->value = new int;
	int* value_ptr = this->value;
	*value_ptr = value;

	this->lineNo = lineNo;
	this->columnNo = columnNo;
}

Token::~Token() {

}

bool Token::equals(String lexem) {

	if (this->lexem.equals(lexem)) {
		return true;
	}
	return false;
}

int Token::hashCode() {
	return this->lexem.hashCode();
}
