//
// Created by Kishor Rana on 07/01/2017.
//

#include "IndexNode.h"
#include "Leaf.h"
#include "EpsilonNode.h"
#include "ExpNode.h"

using namespace std;

IndexNode::IndexNode() {
}

IndexNode::~IndexNode() {
    // TODO Auto-generated destructor stub
}

bool IndexNode::parse(Parser &parser) {

    Leaf *eckigeKlammerAufLeaf = new Leaf(eckigeKlammerAuf);
    if (eckigeKlammerAufLeaf->parse(parser)) {
        childrenNodes->put(eckigeKlammerAufLeaf);

        ExpNode *expNode = new ExpNode();
        if (expNode->parse(parser)) {
            childrenNodes->put(expNode);

            Leaf *eckigeKlammerZuLeaf = new Leaf(eckigeKlammerZu);
            if (eckigeKlammerZuLeaf->parse(parser)) {
                childrenNodes->put(eckigeKlammerZuLeaf);
                rule = INDEX_RULE;
                return true;
            } else {
                delete eckigeKlammerZuLeaf;
            }
        } else {
            delete expNode;
        }
    } else {
        delete eckigeKlammerAufLeaf;
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

void IndexNode::print() {
    cout << "Implement IndexNode::print()." << endl;
}