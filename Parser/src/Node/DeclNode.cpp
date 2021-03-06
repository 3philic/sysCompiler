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
    Leaf *intLeaf = new Leaf(intToken);
    if (intLeaf->parse(parser)) {
        childrenNodes->put(intLeaf);

        ArrayNode *arrayNode = new ArrayNode();
        if (arrayNode->parse(parser)) {
            childrenNodes->put(arrayNode);

            Leaf *identifierNode = new Leaf(identifier);
            if (identifierNode->parse(parser)) {
                childrenNodes->put(identifierNode);
                rule = DECL_RULE;
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
    visitor.visit(*this);
}

void DeclNode::print() {
    cout << "Implement DeclNode::print()." << endl;
}