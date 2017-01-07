//
// Created by Kishor Rana on 07/01/2017.
//

#include "IndexNode.h"

using namespace std;

IndexNode::IndexNode() {
}

IndexNode::~IndexNode() {
    // TODO Auto-generated destructor stub
}

bool IndexNode::parse(Parser &parser) {
    cout << "Implement IndexNode::parse(). Return false." << endl;
    return false;
}

void IndexNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this IndexNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement IndexNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void IndexNode::print() {
    cout << "Implement IndexNode::print()." << endl;
}