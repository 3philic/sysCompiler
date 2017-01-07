//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_VISITOR_H
#define SYSCOMPILER_VISITOR_H

class Visitor {
public:
    virtual void visit(class Node &node) = 0;

};


#endif //SYSCOMPILER_VISITOR_H
