//
// Created by Jones on 07.01.17.
//

#ifndef SYSCOMPILER_OPNODE_H
#define SYSCOMPILER_OPNODE_H


#include "../Node.h"

class OpNode : public Node {
public:
    OpNode();

    virtual ~OpNode();

    bool parse(Parser &parser);


    void print();
};


#endif //SYSCOMPILER_OPNODE_H
