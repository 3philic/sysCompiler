//
// Created by Kishor Rana on 07/01/2017.
//

#include "PrintingVisitor.h"
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

PrintingVisitor::PrintingVisitor() {

}

PrintingVisitor::~PrintingVisitor() {
    // TODO Auto-generated destructor stub
}

void PrintingVisitor::visit(class ParseTree &parseTree) {
    if (typeid(parseTree) == typeid(Leaf)) {
        Leaf* leaf = dynamic_cast<Leaf*>(&parseTree);
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