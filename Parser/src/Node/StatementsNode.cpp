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
                rule = STATEMENT_RULE;
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
        rule = EPSILON_RULE;
        return true;
    } else {
        delete epsilonNode;
    }

    return false;
}

void StatementsNode::print() {
    cout << "Implement StatementsNode::print()." << endl;
}