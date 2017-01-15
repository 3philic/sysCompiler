//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_DECLNODE_H
#define SYSCOMPILER_DECLNODE_H


#include "../Node.h"

class DeclNode: public Node {
public:
    DeclNode();
    virtual ~DeclNode();

    bool parse(Parser &parser);
    void accept(Visitor &visitor);
    void print();
};


#endif //SYSCOMPILER_DECLNODE_H
