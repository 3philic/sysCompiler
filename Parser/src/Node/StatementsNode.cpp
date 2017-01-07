//
// Created by Kishor Rana on 07/01/2017.
//

#include "StatementsNode.h"
#include "StatementNode.h"
#include "Leaf.h"
#include "EpsilonNode.h"

using namespace std;

StatementsNode::StatementsNode() {

}

StatementsNode::~StatementsNode() {
    // TODO Auto-generated destructor stub
}

bool StatementsNode::parse(Parser &parser) {
    // 1. Alternative (Statement;Statements)
    StatementNode *statementNode = new StatementNode();
    if (statementNode->parse(parser)) {
        childrenNodes->put(statementNode);

        Leaf *semikolonLeaf = new Leaf(semikolon);
        if (semikolonLeaf->parse(parser)) {
            childrenNodes->put(semikolonLeaf);

            StatementsNode *statementsNode = new StatementsNode();
            if (statementsNode->parse(parser)) {
                childrenNodes->put(statementsNode);

                return true;
            } else {
                delete statementsNode;
            }
        } else {
            delete semikolonLeaf;
        }
    } else {
        delete statementNode;
    }

    deleteChildrenNodes();
    // 2. Alternative (Epsilon)
    EpsilonNode *epsilonNode = new EpsilonNode();
    if (epsilonNode->parse(parser)) {
        childrenNodes->put(epsilonNode);
        return true;
    } else {
        delete epsilonNode;
    }

    return false;
}

void StatementsNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this StatementsNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement StatementsNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void StatementsNode::print() {
    cout << "Implement StatementsNode::print()." << endl;
}