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
	parseTree->parse(*this);
}

void Parser::accept(class Visitor &visitor) {
    parseTree->accept(visitor);
}

void Parser::nextToken() {
    scanner->nextToken();
}