//
// Created by Kishor Rana on 07/01/2017.
//

#include "ExpNode.h"

using namespace std;

ExpNode::ExpNode() {
}

ExpNode::~ExpNode() {
    // TODO Auto-generated destructor stub
}

bool ExpNode::parse(Parser &parser) {
    cout << "Implement ExpNode::parse(). Return false." << endl;
    return false;
}

void ExpNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this ExpNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement ExpNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void ExpNode::print() {
    cout << "Implement ExpNode::print()." << endl;
}