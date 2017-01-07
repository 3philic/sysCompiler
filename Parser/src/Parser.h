/*
 * Parser.h
 *
 *  Created on: 20.08.2014
 *      Author: jones
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "../../Token.h"
#include "../../Scanner/src/Scanner.h"
#include "Node.h"
#include "Node/ProgramNode.h"

class Parser {

public:
	Parser(char* fileLocation);
	virtual ~Parser();

	Node* parseTree;	// rootNode
    Token* currentToken;

	void parse();
	void accept(class Visitor &visitor);

    void nextToken();

private:
	Scanner* scanner;

};


#endif /* PARSER_H_ */
