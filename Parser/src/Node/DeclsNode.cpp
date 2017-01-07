//
// Created by Kishor Rana on 07/01/2017.
//

#include "DeclsNode.h"
#include "DeclNode.h"
#include "EpsilonNode.h"
#include "Leaf.h"
#include "../Parser.h"

using namespace std;

DeclsNode::DeclsNode() {

}

DeclsNode::~DeclsNode() {
    // TODO Auto-generated destructor stub
}

bool DeclsNode::parse(Parser &parser) {

    // 1. Alternative (Decl;Decls)
    DeclNode *declNode = new DeclNode();
    if (declNode->parse(parser)) {
        // childrenNodes.add(declNode);

        Leaf *semikolonLeaf = new Leaf(semikolon);
        if (semikolonLeaf->parse(parser)) {
            // childrenNodes.add(semikolonLeaf);

            DeclsNode *declsNode = new DeclsNode();
            if (declsNode->parse(parser)) {
                // childrenNodes.add(declsNode);

                return true;
            } else {
                delete declNode;
            }
        } else {
            delete semikolonLeaf;
        }
    } else {
        delete declNode;
    }

    deleteChildrenNodes();
    // 2. Alternative (Epsilon)
    EpsilonNode *epsilonNode = new EpsilonNode();
    if (epsilonNode->parse(parser)) {
        // childrenNodes.add(epsilonNode);
        return true;
    } else {
        delete epsilonNode;
    }

    return false;
}

void DeclsNode::accept(Visitor &visitor) {
    // 1. call accept for alternatives
    // 2. mark this DeclsNode visited

    // 1.
    // IMPLEMENT!!!
    cout << "Implement DeclsNode::accept()'s calling accept on alternatives." << endl;

    // 2.
    visitor.visit(*this);
}

void DeclsNode::print() {
    cout << "Implement DeclsNode::print()." << endl;
}