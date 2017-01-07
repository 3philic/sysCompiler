/*
 * Node.cpp
 *
 *  Created on: 7 Nov 2016
 *      Author: 3philic
 */

#include "Node.h"
#include <assert.h>
#include <iostream>
//#include "Parser.h"

using namespace std;

Node::Node() {
	childrenNodes = new LinkedList<Node *>();
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

void Node::deleteChildrenNodes() {
	cout << "Implement Node::deleteChildrenNodes()." << endl;
}