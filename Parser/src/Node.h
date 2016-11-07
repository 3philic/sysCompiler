/*
 * Node.h
 *
 *  Created on: 7 Nov 2016
 *      Author: 3philic
 */

#ifndef PARSER_SRC_NODE_H_
#define PARSER_SRC_NODE_H_

#include "../../Symboltable/src/LinkedList.h"

class Parser;

class Node {
public:
	Node();
	virtual ~Node();

	virtual bool parse(Parser &parser) = 0;

private:
	LinkedList* childrenNodes;	// <Node>
	LinkedList* alternatives;	// <LinkedList <Node>>

};

#endif /* PARSER_SRC_NODE_H_ */
