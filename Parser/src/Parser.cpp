/*
 * Parser.cpp
 *
 *  Created on: 20.08.2014
 *      Author: jones
 */

#include "Parser.h"

Parser::Parser(char* fileLocation) {
	scanner = new Scanner(fileLocation);
	currentToken = scanner->nextToken();
	parseTree = new ProgramNode();
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

void Parser::parse() {
	// test parse
	parseTree->parse(*this);
}
