//
// Created by tim on 14.01.17.
//

#ifndef SYSCOMPILER_CODEGENERATORVISITOR_H
#define SYSCOMPILER_CODEGENERATORVISITOR_H

#include "Visitor.h"
#include "FileWriter.h"
#include "Rule.h"

class CodeGeneratorVisitor : public Visitor {

public:
    CodeGeneratorVisitor(FileWriter* fileWriter);
    virtual ~CodeGeneratorVisitor();

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
    FileWriter* fileWriter;
    int labelCounter;
    char* getNewLabel();
    char* convertIntToString(int i);

};
#endif //SYSCOMPILER_CODEGENERATORVISITOR_H
