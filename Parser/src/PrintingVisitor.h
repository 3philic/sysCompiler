//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_PRINTINGVISITOR_H
#define SYSCOMPILER_PRINTINGVISITOR_H


#include "Visitor.h"

class PrintingVisitor : public Visitor {
public:
    PrintingVisitor();
    virtual ~PrintingVisitor();

    virtual void visit(Leaf &leaf);
    virtual void visit(ProgramNode &programNode);
    virtual void visit(DeclsNode &declsNode);
    virtual void visit(DeclNode &declNode);
    virtual void visit(StatementsNode &statementsNode);
    virtual void visit(StatementNode &statementNode);
    virtual void visit(ArrayNode &arrayNode);
    virtual void visit(EpsilonNode &epsilonNode);
    virtual void visit(Exp2Node &exp2Node);
    virtual void visit(ExpNode &expNode);
    virtual void visit(IndexNode &indexNode);
    virtual void visit(OpExpNode &opExpNode);
    virtual void visit(OpNode &opNode);
};


#endif //SYSCOMPILER_PRINTINGVISITOR_H
