/*
 * ProgramNode.h
 *
 *  Created on: 7 Nov 2016
 *      Author: 3philic
 */

#ifndef PARSER_SRC_PROGRAMNODE_H_
#define PARSER_SRC_PROGRAMNODE_H_

#include "Node.h"

class ProgramNode: public Node {
public:
	ProgramNode();
	virtual ~ProgramNode();

	bool parse(Parser &parser);
	void accept(class Visitor &visitor);

	void print();
};

#endif /* PARSER_SRC_PROGRAMNODE_H_ */
