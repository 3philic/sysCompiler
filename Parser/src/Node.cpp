/*
 * Node.cpp
 *
 *  Created on: 7 Nov 2016
 *      Author: 3philic
 */

#include "Node.h"
#include <assert.h>
#include <iostream>
#include "Visitor.h"

using namespace std;

Node::Node() {
    childrenNodes = new LinkedList<ParseTree *>();
}

Node::~Node() {
    // TODO Auto-generated destructor stub
}

// Override
void Node::accept(Visitor &visitor) {
    LinkedList<ParseTree *>::ListIterator<ParseTree *> *iterator = childrenNodes->iterator();
    while (iterator->hasNext()) {
        ParseTree *next = iterator->next();
        next->accept(visitor);
    }
    visitor.visit(*this);
    delete iterator;
}

void Node::deleteChildrenNodes() {
    LinkedList<ParseTree *>::ListIterator<ParseTree *> *iterator = childrenNodes->iterator();
    while (iterator->hasNext()) {
        ParseTree *next = iterator->next();
        delete next;
    }
    delete iterator;
    delete childrenNodes;
    childrenNodes = new LinkedList<ParseTree *>();
}

LinkedList<ParseTree *>* Node::getChildrenNodes() {
    return childrenNodes;
}
