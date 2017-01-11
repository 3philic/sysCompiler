//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_VISITOR_H
#define SYSCOMPILER_VISITOR_H
#include "Node.h"
#include "Node/ArrayNode.h"
#include "Node/ProgramNode.h"
#include "Node/DeclsNode.h"
#include "Node/DeclNode.h"
#include "Node/StatementsNode.h"
#include "Node/StatementNode.h"
#include "Node/Leaf.h"
#include "Node/EpsilonNode.h"
#include "Node/Exp2Node.h"
#include "Node/ExpNode.h"
#include "Node/IndexNode.h"
#include "Node/OpExpNode.h"
#include "Node/OpNode.h"
#include "NodeType.h"


class Visitor {
public:
    virtual void visit(ParseTree &parseTree) = 0;
    virtual void visit(Leaf &leaf) = 0;
    virtual void visit(ProgramNode &programNode) = 0;
    virtual void visit(DeclsNode &declsNode) = 0;
    virtual void visit(DeclNode &declNode) = 0;
    virtual void visit(StatementsNode &statementsNode) = 0;
    virtual void visit(StatementNode &statementNode) = 0;
    virtual void visit(ArrayNode &arrayNode) = 0;
    virtual void visit(EpsilonNode &epsilonNode) = 0;
    virtual void visit(Exp2Node &exp2Node) = 0;
    virtual void visit(ExpNode &expNode) = 0;
    virtual void visit(IndexNode &indexNode) = 0;
    virtual void visit(OpExpNode &opExpNode) = 0;
    virtual void visit(OpNode &opNode) = 0;

};


#endif //SYSCOMPILER_VISITOR_H
