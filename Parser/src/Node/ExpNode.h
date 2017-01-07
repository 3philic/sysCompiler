//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_EXPNODE_H
#define SYSCOMPILER_EXPNODE_H


#include "../Node.h"

class ExpNode: public Node {
public:
	ExpNode();
	virtual ~ExpNode();

	bool parse(Parser &parser);

	void print();
};


#endif //SYSCOMPILER_EXPNODE_H
