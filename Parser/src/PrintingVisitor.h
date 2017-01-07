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

    void visit(class Node &node);
};


#endif //SYSCOMPILER_PRINTINGVISITOR_H
