/*
 * ProgramNode.cpp
 *
 *  Created on: 7 Nov 2016
 *      Author: 3philic
 */

#include "ProgramNode.h"
#include "Visitor.h"

ProgramNode::ProgramNode() {

}

ProgramNode::~ProgramNode() {
	// TODO Auto-generated destructor stub
}

bool ProgramNode::parse(Parser &parser) {
	cout << "Implement ProgramNode::parse(). Returning false." << endl;
	return false;
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