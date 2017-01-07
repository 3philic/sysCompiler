/*
 * ProgramNode.cpp
 *
 *  Created on: 7 Nov 2016
 *      Author: 3philic
 */

#include "ProgramNode.h"
#include "DeclsNode.h"
#include "StatementsNode.h"

using namespace std;

ProgramNode::ProgramNode() {
    // alternatives->add([Decls])
    // alternatives->add([Statements])
}

ProgramNode::~ProgramNode() {
	// TODO Auto-generated destructor stub
}

bool ProgramNode::parse(Parser &parser) {

    DeclsNode *declsNode = new DeclsNode();
    if (declsNode->parse(parser)) {
        childrenNodes->put(declsNode);

        StatementsNode *statementsNode = new StatementsNode();
        if (statementsNode->parse(parser)) {
            childrenNodes->put(statementsNode);
        } else {
            delete statementsNode;
            return false;
        }
    } else {
        delete declsNode;
        return false;
    }

	return true;
}

void ProgramNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this ProgramNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement ProgramNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void ProgramNode::print() {
    cout << "Implement ProgramNode::print()." << endl;
}