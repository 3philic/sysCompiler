/*
 * Node.h
 *
 *  Created on: 7 Nov 2016
 *      Author: 3philic
 */

#ifndef PARSER_SRC_NODE_H_
#define PARSER_SRC_NODE_H_

#include "Visitor.h"
#include "ParseTree.h"
#include "../../LinkedList.h"

class Node: public ParseTree {
public:
	Node();
	virtual ~Node();

    LinkedList<ParseTree *>* childrenNodes;	// <ParseTree>
	void deleteChildrenNodes();

	LinkedList<ParseTree *>* getChildrenNodes();

	/*// Override
	void accept(Visitor &visitor);*/



};

#endif /* PARSER_SRC_NODE_H_ */
