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
    this->token = parser.currentToken;

    if (token->type == expectedTType) {
        cout << "Leaf " << TTypeToString(token->type) << endl;
        parser.nextToken();
        return true;
    } else {
        return false;
    }
}

void Leaf::accept(Visitor &visitor) {
    visitor.visit(*this);
}

void Leaf::print() {
    cout << TTypeToString(token->type);
}

void Leaf::setNodeType(NodeType value) {
    token->getInformation()->nodeType = value;
}

NodeType Leaf::getNodeType() {
    return token->getInformation()->nodeType;
}
