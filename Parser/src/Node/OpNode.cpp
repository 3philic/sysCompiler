//
// Created by Jones on 07.01.17.
//

#include "OpNode.h"
#include "Leaf.h"

using namespace std;

OpNode::OpNode() {
}

OpNode::~OpNode() {
    // TODO Auto-generated destructor stub
}

bool OpNode::parse(Parser &parser) {
    //+|-|*|:|<|>|=|=:=|&&
    rule = OPERATOR_RULE;
    //1 +
    Leaf *plusLeaf = new Leaf(plusToken);
    if (plusLeaf->parse(parser)) {
        childrenNodes->put(plusLeaf);
        return true;
    } else {
        delete plusLeaf;
    }

    deleteChildrenNodes();

    //2 -
    Leaf *minusLeaf = new Leaf(minusToken);
    if (minusLeaf->parse(parser)) {
        childrenNodes->put(minusLeaf);
        return true;
    } else {
        delete minusLeaf;
    }

    deleteChildrenNodes();

    //3 *
    Leaf *sternLeaf = new Leaf(stern);
    if (sternLeaf->parse(parser)) {
        childrenNodes->put(sternLeaf);
        return true;
    } else {
        delete sternLeaf;
    }

    deleteChildrenNodes();

    //4 :
    Leaf *doppelPunktLeaf = new Leaf(doppelpunkt);
    if (doppelPunktLeaf->parse(parser)) {
        childrenNodes->put(doppelPunktLeaf);
        return true;
    } else {
        delete doppelPunktLeaf;
    }

    deleteChildrenNodes();

    //5 <
    Leaf *kleinerLeaf = new Leaf(kleiner);
    if (kleinerLeaf->parse(parser)) {
        childrenNodes->put(kleinerLeaf);
        return true;
    } else {
        delete kleinerLeaf;
    }

    deleteChildrenNodes();

    //6 >
    Leaf *groesserLeaf = new Leaf(groesser);
    if (groesserLeaf->parse(parser)) {
        childrenNodes->put(groesserLeaf);
        return true;
    } else {
        delete groesserLeaf;
    }

    deleteChildrenNodes();

    //7 =
    Leaf *gleichLeaf = new Leaf(gleich);
    if (gleichLeaf->parse(parser)) {
        childrenNodes->put(gleichLeaf);
        return true;
    } else {
        delete gleichLeaf;
    }

    deleteChildrenNodes();

    //8 =:=
    Leaf *ungleichLeaf = new Leaf(ungleich);
    if (ungleichLeaf->parse(parser)) {
        childrenNodes->put(ungleichLeaf);
        return true;
    } else {
        delete ungleichLeaf;
    }

    deleteChildrenNodes();

    //9 undund
    Leaf *undUndLeaf = new Leaf(undund);
    if (undUndLeaf->parse(parser)) {
        childrenNodes->put(undUndLeaf);
        return true;
    } else {
        delete undUndLeaf;
    }

    return false;

}

void OpNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this ExpNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement ExpNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void OpNode::print() {
    cout << "Implement ExpNode::print()." << endl;
}