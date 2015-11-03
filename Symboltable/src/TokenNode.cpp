/*
 * TokenNode.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: 3philic
 */

#include "TokenNode.h"

TokenNode::TokenNode(Token* data, TokenNode* next, TokenNode* previous) {
	this->data = data;
	this->next = next;
	this->previous = previous;
}

TokenNode::~TokenNode() {
	// TODO Auto-generated destructor stub
}

