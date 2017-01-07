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
    LinkedList<Node *>::ListIterator<Node *> *iterator = childrenNodes->iterator();
    while (iterator->hasNext()) {
        Node *next = iterator->next();
        delete next;
    }
    delete iterator;
    delete childrenNodes;
    childrenNodes = new LinkedList<Node *>();
}
