//
// Created by Kishor Rana on 07/01/2017.
//

#include "PrintingVisitor.h"
#include "Node/ProgramNode.h"
#include <iostream>
using namespace std;

PrintingVisitor::PrintingVisitor() {

}

PrintingVisitor::~PrintingVisitor() {
    // TODO Auto-generated destructor stub
}

void PrintingVisitor::visit(class Node &node) {
    if (typeid(node) == typeid(ProgramNode)) {
        cout << "ProgramNode";
    }
}