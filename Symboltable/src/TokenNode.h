/*
 * TokenNode.h
 *
 *  Created on: Apr 16, 2014
 *      Author: 3philic
 */

#ifndef TokenNODE_H_
#define TokenNODE_H_

#include "../../Token.h"

class TokenNode {
public:
	Token* data;
	TokenNode* next;
	TokenNode* previous;

	TokenNode(Token* data, TokenNode* next, TokenNode* previous);
	virtual ~TokenNode();
};

#endif /* TokenNODE_H_ */
