/*
 * Parser.h
 *
 *  Created on: 20.08.2014
 *      Author: jones
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "../../Scanner/src/Scanner.h"

#include "ParseVariable.h"

class Parser {
public:
	Parser(char* fileLocation);
	virtual ~Parser();

	void parse();
private:
	Scanner* scanner;

	// Datenstruktur
	ParseVariable* currentParseVariable;	// bestimmt sich durch die Antwort des
											// Methodenaufrufs (insertToken)

};


#endif /* PARSER_H_ */
