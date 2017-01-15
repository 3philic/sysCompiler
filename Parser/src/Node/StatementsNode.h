//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_STATEMENTSNODE_H
#define SYSCOMPILER_STATEMENTSNODE_H


#include "../Node.h"

class StatementsNode: public Node {
public:
    StatementsNode();
    virtual ~StatementsNode();

    bool parse(Parser &parser);
    void accept(Visitor &visitor);
    void print();
};


#endif //SYSCOMPILER_STATEMENTSNODE_H
