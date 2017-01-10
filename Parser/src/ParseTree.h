//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_PARSETREE_H
#define SYSCOMPILER_PARSETREE_H

#include "Rule.h"
#include "Visitor.h"
#include "NodeType.h"
class Parser;

class ParseTree {
public:
    ParseTree();
    virtual ~ParseTree();

    Rule rule;

    virtual bool parse(Parser &parser) = 0;
    virtual void accept(Visitor &visitor) = 0;

    // Visitor methods
    virtual void print() = 0;

    void setNodeType(NodeType value);
    NodeType getNodeType();

private:
    NodeType nodeType;
};


#endif //SYSCOMPILER_PARSETREE_H
