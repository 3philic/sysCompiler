//
// Created by tim on 08.01.17.
//

#ifndef SYSCOMPILER_TYPECHECKVISITOR_H
#define SYSCOMPILER_TYPECHECKVISITOR_H

#include "Visitor.h"
#include "Rule.h"


class TypeCheckVisitor : public Visitor{

public:
    TypeCheckVisitor();
    virtual ~TypeCheckVisitor();

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

private:
    void printError(char* messageOutput, int lineOutput, int columnOutput);

};

#endif //SYSCOMPILER_TYPECHECKVISITOR_H
