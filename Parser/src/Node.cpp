/*
 * Node.cpp
 *
 *  Created on: 7 Nov 2016
 *      Author: 3philic
 */

#include "Node.h"
#include <assert.h>
//#include "Parser.h"

Node::Node() {
	alternatives = new LinkedList();
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

bool Node::parse(Parser &parser) {
	assert(false);	// overwrite in subclasses of Node!
}
