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
    visitor.visit(*this);
}

void EpsilonNode::print() {
    cout << "Implement EpsilonNode::print()." << endl;
}