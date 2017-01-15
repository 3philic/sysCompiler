//
// Created by Jones on 07.01.17.
//

#include "OpExpNode.h"
#include "EpsilonNode.h"
#include "OpNode.h"
#include "ExpNode.h"

using namespace std;

OpExpNode::OpExpNode() {
}

OpExpNode::~OpExpNode() {
    // TODO Auto-generated destructor stub
}

bool OpExpNode::parse(Parser &parser) {
    // 1. Alternative (op ext)
    OpNode *opNode = new OpNode();
    if (opNode->parse(parser)) {
        childrenNodes->put(opNode);

        ExpNode *expNode = new ExpNode();
        if (expNode->parse(parser)) {
            childrenNodes->put(expNode);
            rule = OP_EXP_RULE;
            return true;
        } else {
            delete expNode;
        }
    } else {
        delete opNode;
    }

    deleteChildrenNodes();
    // 2. Alternative (Epsilon)
    EpsilonNode *epsilonNode = new EpsilonNode();
    if (epsilonNode->parse(parser)) {
        childrenNodes->put(epsilonNode);
        rule = EPSILON_RULE;
        return true;
    } else {
        delete epsilonNode;
    }
    return false;
}

void OpExpNode::accept(Visitor &visitor) {
    visitor.visit(*this);
}

void OpExpNode::print() {
    cout << "Implement ExpNode::print()." << endl;
}