//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_VISITOR_H
#define SYSCOMPILER_VISITOR_H

class ParseTree; class Leaf; class ProgramNode; class DeclsNode; class DeclNode;
class StatementsNode; class StatementNode; class ArrayNode; class EpsilonNode;
class Exp2Node; class ExpNode; class IndexNode; class OpExpNode; class OpNode;

class Visitor {
public:
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
