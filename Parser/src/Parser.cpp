/*
 * Parser.cpp
 *
 *  Created on: 20.08.2014
 *      Author: jones
 */

#include "Parser.h"

Parser::Parser(char* fileLocation) {
	scanner = new Scanner (fileLocation);
	token = scanner->nextToken();
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

void Parser::parse(){
	// TODO stub
}
