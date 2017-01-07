//
// Created by Kishor Rana on 07/01/2017.
//

#include "DeclNode.h"
#include "Leaf.h"
#include "../Parser.h"
#include "DeclsNode.h"
#include "ArrayNode.h"

using namespace std;

DeclNode::DeclNode() {

}

DeclNode::~DeclNode() {
    // TODO Auto-generated destructor stub
}

bool DeclNode::parse(Parser &parser) {
    // (int array identifier)
    Leaf *intLeaf = new Leaf(integer);
    if (intLeaf->parse(parser)) {
        // childrenNodes.add(intLeaf);

        ArrayNode *arrayNode = new ArrayNode();
        if (arrayNode->parse(parser)) {
            // childrenNodes.add(arrayNode);

            Leaf *identifierNode = new Leaf(identifier);
            if (identifierNode->parse(parser)) {
                // childrenNodes.add(identifierNode);
                return true;
            } else {
                delete identifierNode;
            }
        } else {
            delete arrayNode;
        }
    } else {
        delete intLeaf;
    }

    return false;
}

void DeclNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this DeclNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement DeclNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void DeclNode::print() {
    cout << "Implement DeclNode::print()." << endl;
}