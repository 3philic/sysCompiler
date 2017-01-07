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
        // childrenNodes.add(eckigeKlammerAufLeaf);

        Leaf *integerLeaf = new Leaf(integer);
        if (integerLeaf->parse(parser)) {
            // childrenNodes.add(integerLeaf);

            Leaf *eckigeKlammerZuLeaf = new Leaf(eckigeKlammerZu);
            if (eckigeKlammerZuLeaf->parse(parser)) {
                // childrenNodes.add(eckigeKlammerZuLeaf);

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
        // childrenNodes.add(epsilonNode);
        return true;
    } else {
        delete epsilonNode;
    }

    return false;
}

void ArrayNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this ArrayNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement ArrayNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void ArrayNode::print() {
    cout << "Implement ArrayNode::print()." << endl;
}