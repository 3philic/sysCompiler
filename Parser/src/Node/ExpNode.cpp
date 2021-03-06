//
// Created by Kishor Rana on 07/01/2017.
//

#include "ExpNode.h"
#include "Exp2Node.h"
#include "OpExpNode.h"

using namespace std;

ExpNode::ExpNode() {
}

ExpNode::~ExpNode() {
    // TODO Auto-generated destructor stub
}

bool ExpNode::parse(Parser &parser) {
    Exp2Node *exp2Node = new Exp2Node();
    if (exp2Node->parse(parser)) {
        childrenNodes->put(exp2Node);

        OpExpNode *opExpNode = new OpExpNode();
        if (opExpNode->parse(parser)) {
            childrenNodes->put(opExpNode);
            rule = EXP_RULE;
            return true;
        } else {
            delete (opExpNode);
        }

    } else {
        delete (exp2Node);
    }

    return false;
}

void ExpNode::accept(Visitor &visitor) {
    visitor.visit(*this);
}

void ExpNode::print() {
    cout << "Implement ExpNode::print()." << endl;
}