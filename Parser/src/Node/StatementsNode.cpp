//
// Created by Kishor Rana on 07/01/2017.
//

#include "StatementsNode.h"

using namespace std;

StatementsNode::StatementsNode() {

}

StatementsNode::~StatementsNode() {
    // TODO Auto-generated destructor stub
}

bool StatementsNode::parse(Parser &parser) {
    cout << "Implement StatementsNode::parse(). Returning false." << endl;
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