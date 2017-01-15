//
// Created by Jones on 07.01.17.
//

#ifndef SYSCOMPILER_OPEXPNODE_H
#define SYSCOMPILER_OPEXPNODE_H


#include "../Node.h"

class OpExpNode : public Node {
public:
    OpExpNode();

    virtual ~OpExpNode();

    bool parse(Parser &parser);
    void accept(Visitor &visitor);
    void print();
};


#endif //SYSCOMPILER_OPEXPNODE_H
