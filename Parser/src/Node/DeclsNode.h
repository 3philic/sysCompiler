//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_DECLSNODE_H
#define SYSCOMPILER_DECLSNODE_H


#include "../Node.h"

class DeclsNode: public Node {
public:
    DeclsNode();
    virtual ~DeclsNode();

    bool parse(Parser &parser);

    void print();
};


#endif //SYSCOMPILER_DECLSNODE_H
