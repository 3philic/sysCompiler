//
// Created by Kishor Rana on 07/01/2017.
//

#include "EpsilonNode.h"

using namespace std;

EpsilonNode::EpsilonNode() {

}

EpsilonNode::~EpsilonNode() {
    // TODO Auto-generated destructor stub
}

bool EpsilonNode::parse(Parser &parser) {
    rule = EPSILON_RULE;
    return true;
}

void EpsilonNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this EpsilonNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement EpsilonNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void EpsilonNode::print() {
    cout << "Implement EpsilonNode::print()." << endl;
}