//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_STATEMENTNODE_H
#define SYSCOMPILER_STATEMENTNODE_H


#include "../Node.h"

class StatementNode: public Node {
public:
    StatementNode();
    virtual ~StatementNode();

    bool parse(Parser &parser);

    void print();
};


#endif //SYSCOMPILER_STATEMENTNODE_H
