//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_ARRAYNODE_H
#define SYSCOMPILER_ARRAYNODE_H


#include "../Node.h"

class ArrayNode: public Node {
public:
    ArrayNode();
    virtual ~ArrayNode();

    bool parse(Parser &parser);

    void print();
};


#endif //SYSCOMPILER_ARRAYNODE_H
