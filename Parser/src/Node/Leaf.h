//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_LEAF_H
#define SYSCOMPILER_LEAF_H


#include "../Node.h"
#include "../../../Token.h"
#include "../../../TType.h"

class Leaf: public Node {
public:
    Leaf(TType expectedTType);
    virtual ~Leaf();

    bool parse(Parser &parser);

    void print();

    Token *token;
    TType expectedTType;
};


#endif //SYSCOMPILER_LEAF_H
