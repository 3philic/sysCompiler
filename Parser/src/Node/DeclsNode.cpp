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
        childrenNodes->put(declNode);

        Leaf *semikolonLeaf = new Leaf(semikolon);
        if (semikolonLeaf->parse(parser)) {
            childrenNodes->put(semikolonLeaf);

            DeclsNode *declsNode = new DeclsNode();
            if (declsNode->parse(parser)) {
                childrenNodes->put(declsNode);

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
        childrenNodes->put(epsilonNode);
        return true;
    } else {
        delete epsilonNode;
    }

    return false;
}

void DeclsNode::print() {
    cout << "Implement DeclsNode::print()." << endl;
}