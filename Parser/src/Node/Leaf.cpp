//
// Created by Kishor Rana on 07/01/2017.
//

#include "Leaf.h"
#include "../Parser.h"

using namespace std;

Leaf::Leaf(TType expectedTType) {
    this->expectedTType = expectedTType;
}

Leaf::~Leaf() {
    // TODO Auto-generated destructor stub
}

bool Leaf::parse(Parser &parser) {

    if (parser.currentToken->type == expectedTType) {
        cout << "Leaf " << TTypeToString(parser.currentToken->type) << endl;
        parser.nextToken();
        return true;
    } else {
        return false;
    }
}

void Leaf::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this Leaf visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement Leaf::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void Leaf::print() {
    cout << "Implement Leaf::print()." << endl;
}