//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_PARSETREE_H
#define SYSCOMPILER_PARSETREE_H

#include "Rule.h"
class Parser;

class ParseTree {
public:
    ParseTree();
    virtual ~ParseTree();

    Rule rule;

    virtual bool parse(Parser &parser) = 0;
    virtual void accept(class Visitor &visitor);

    // Visitor methods
    virtual void print() = 0;
};


#endif //SYSCOMPILER_PARSETREE_H
