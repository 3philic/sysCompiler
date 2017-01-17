//
// Created by Kishor Rana on 07/01/2017.
//

#include "PrintingVisitor.h"

#include <typeinfo>

#include "Node/ProgramNode.h"
#include "Node/ArrayNode.h"
#include "Node/DeclNode.h"
#include "Node/DeclsNode.h"
#include "Node/EpsilonNode.h"
#include "Node/Exp2Node.h"
#include "Node/ExpNode.h"
#include "Node/IndexNode.h"
#include "Node/Leaf.h"
#include "Node/OpExpNode.h"
#include "Node/OpNode.h"
#include "Node/StatementNode.h"
#include "Node/StatementsNode.h"

using namespace std;

#pragma mark - Forward Declaration of Private Methods

void visitParseTree(class ParseTree &parseTree);

#pragma mark -

PrintingVisitor::PrintingVisitor() {

}

PrintingVisitor::~PrintingVisitor() {
    // TODO Auto-generated destructor stub
}

void PrintingVisitor::visit(Leaf &leaf) {
    visitParseTree(leaf);
}

void PrintingVisitor::visit(ProgramNode &programNode) {
    visitParseTree(programNode);
}

void PrintingVisitor::visit(DeclsNode &declsNode) {
    visitParseTree(declsNode);
}

void PrintingVisitor::visit(DeclNode &declNode) {
    visitParseTree(declNode);
}

void PrintingVisitor::visit(StatementsNode &statementsNode) {
    visitParseTree(statementsNode);
}

void PrintingVisitor::visit(StatementNode &statementNode) {
    visitParseTree(statementNode);
}

void PrintingVisitor::visit(ArrayNode &arrayNode) {
    visitParseTree(arrayNode);
}

void PrintingVisitor::visit(EpsilonNode &epsilonNode) {
    visitParseTree(epsilonNode);
}

void PrintingVisitor::visit(Exp2Node &exp2Node) {
    visitParseTree(exp2Node);
}

void PrintingVisitor::visit(ExpNode &expNode) {
    visitParseTree(expNode);
}

void PrintingVisitor::visit(IndexNode &indexNode) {
    visitParseTree(indexNode);
}

void PrintingVisitor::visit(OpExpNode &opExpNode) {
    visitParseTree(opExpNode);
}

void PrintingVisitor::visit(OpNode &opNode) {
    visitParseTree(opNode);
}

// private, unexposed helper method
void visitParseTree(class ParseTree &parseTree) {
    if (typeid(parseTree) == typeid(Leaf)) {
        Leaf *leaf = dynamic_cast<Leaf*>(&parseTree);
        cout << "visited " << "Leaf (";
        leaf->print();
        cout << ")";
    } else {
        char *name = "";

        if (typeid(parseTree) == typeid(ArrayNode)) {
            name = "ArrayNode";
        } if (typeid(parseTree) == typeid(DeclNode)) {
            name = "DeclNode";
        } if (typeid(parseTree) == typeid(DeclsNode)) {
            name = "DeclsNode";
        } if (typeid(parseTree) == typeid(EpsilonNode)) {
            name = "EpsilonNode";
        } if (typeid(parseTree) == typeid(Exp2Node)) {
            name = "Exp2Node";
        } if (typeid(parseTree) == typeid(ExpNode)) {
            name = "ExpNode";
        } if (typeid(parseTree) == typeid(IndexNode)) {
            name = "IndexNode";
        } if (typeid(parseTree) == typeid(OpExpNode)) {
            name = "OpExpNode";
        } if (typeid(parseTree) == typeid(OpNode)) {
            name = "OpNode";
        } if (typeid(parseTree) == typeid(ProgramNode)) {
            name = "ProgramNode";
        } if (typeid(parseTree) == typeid(StatementNode)) {
            name = "StatementNode";
        } if (typeid(parseTree) == typeid(StatementsNode)) {
            name = "StatementsNode";
        }

        cout << "visited " << name;
    }

    cout << "\t\t\t" << parseTree.rule << endl;
}
