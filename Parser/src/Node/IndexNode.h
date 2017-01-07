//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_INDEXNODE_H
#define SYSCOMPILER_INDEXNODE_H


#include "../Node.h"

class IndexNode: public Node {
public:
    IndexNode();
    virtual ~IndexNode();

    bool parse(Parser &parser);
    void accept(class Visitor &visitor);

    void print();
};


#endif //SYSCOMPILER_INDEXNODE_H
