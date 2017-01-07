//
// Created by Kishor Rana on 07/01/2017.
//

#include "ArrayNode.h"
#include "EpsilonNode.h"
#include "Leaf.h"

using namespace std;

ArrayNode::ArrayNode() {

}

ArrayNode::~ArrayNode() {
    // TODO Auto-generated destructor stub
}

bool ArrayNode::parse(Parser &parser) {

    // 1. Alternative (Decl;Decls)
    Leaf *eckigeKlammerAufLeaf = new Leaf(eckigeKlammerAuf);
    if (eckigeKlammerAufLeaf->parse(parser)) {
        childrenNodes->put(eckigeKlammerAufLeaf);

        Leaf *integerLeaf = new Leaf(integer);
        if (integerLeaf->parse(parser)) {
            childrenNodes->put(integerLeaf);

            Leaf *eckigeKlammerZuLeaf = new Leaf(eckigeKlammerZu);
            if (eckigeKlammerZuLeaf->parse(parser)) {
                childrenNodes->put(eckigeKlammerZuLeaf);
                rule = ARRAY_RULE;
                return true;
            } else {
                delete eckigeKlammerZuLeaf;
            }
        } else {
            delete integerLeaf;
        }
    } else {
        delete eckigeKlammerAufLeaf;
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

void ArrayNode::print() {
    cout << "Implement ArrayNode::print()." << endl;
}