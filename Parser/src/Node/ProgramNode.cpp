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
            rule = PROG_RULE;
            return true;
        } else {
            delete statementsNode;
        }
    } else {
        delete declsNode;
    }

    return false;
}

void ProgramNode::accept(Visitor &visitor) {
    visitor.visit(*this);
}

void ProgramNode::print() {
    cout << "Implement ProgramNode::print()." << endl;
}