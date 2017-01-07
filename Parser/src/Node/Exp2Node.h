//
// Created by Jones on 07.01.17.
//

#ifndef SYSCOMPILER_EXP2NODE_H
#define SYSCOMPILER_EXP2NODE_H


#include "../Node.h"

class Exp2Node : public Node {
public:
    Exp2Node();

    virtual ~Exp2Node();

    bool parse(Parser &parser);

    void accept(class Visitor &visitor);

    void print();
};


#endif //SYSCOMPILER_EXP2NODE_H
