//
// Created by Kishor Rana on 07/01/2017.
//

#ifndef SYSCOMPILER_EPSILONNODE_H
#define SYSCOMPILER_EPSILONNODE_H


#include "../Node.h"

class EpsilonNode : public Node {
public:
    EpsilonNode();

    virtual ~EpsilonNode();

    bool parse(Parser &parser);


    void print();
};


#endif //SYSCOMPILER_EPSILONNODE_H
