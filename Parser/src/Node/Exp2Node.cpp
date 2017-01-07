//
// Created by Jones on 07.01.17.
//

#include "Exp2Node.h"
#include "Leaf.h"
#include "ExpNode.h"
#include "IndexNode.h"


using namespace std;

Exp2Node::Exp2Node() {
}

Exp2Node::~Exp2Node() {
    // TODO Auto-generated destructor stub
}

bool Exp2Node::parse(Parser &parser) {

    // 1. Alternative ( EXP )
    Leaf *rundeKlammerAufLeaf = new Leaf(rundeKlammerAuf);
    if (rundeKlammerAufLeaf->parse(parser)) {
        childrenNodes->put(rundeKlammerAufLeaf);

        ExpNode *expNode = new ExpNode();
        if (expNode->parse(parser)) {
            childrenNodes->put(expNode);

            Leaf *rundeKlammerZuLeaf = new Leaf(rundeKlammerZu);
            if (rundeKlammerZuLeaf->parse(parser)) {
                childrenNodes->put(rundeKlammerZuLeaf);
                rule = EXP2_EXP_RULE;
                return true;
            } else {
                delete rundeKlammerZuLeaf;
            }
        } else {
            delete expNode;
        }
    } else {
        delete rundeKlammerAufLeaf;
    }

    deleteChildrenNodes();
    // 2. Alternative (identifier INDEX)
    Leaf *identifierLeaf = new Leaf(identifier);
    if (identifierLeaf->parse(parser)) {
        childrenNodes->put(identifierLeaf);

        IndexNode *indexNode = new IndexNode();
        if (indexNode->parse(parser)) {
            childrenNodes->put(indexNode);
            rule = EXP2_IDENTIFIER_RULE;
            return true;
        } else {
            delete indexNode;
        }
    } else {
        delete identifierLeaf;
    }

    deleteChildrenNodes();
    // 3. Alternative (integer)
    Leaf *integerLeaf = new Leaf(integer);
    if (integerLeaf->parse(parser)) {
        childrenNodes->put(integerLeaf);
        rule = EXP2_INTEGER_RULE;
        return true;
    } else {
        delete integerLeaf;
    }

    deleteChildrenNodes();
    // 4. Alternative (- EXP2 )
    Leaf *minusLeaf = new Leaf(minusToken);
    if (minusLeaf->parse(parser)) {
        childrenNodes->put(minusLeaf);

        Exp2Node *exp2Node = new Exp2Node();
        if (exp2Node->parse(parser)) {
            childrenNodes->put(exp2Node);
            rule = EXP2_MINUS_RULE;
            return true;
        } else {
            delete exp2Node;
        }
    } else {
        delete minusLeaf;
    }


    deleteChildrenNodes();

    // 5. Alternative ( !EXP2 )
    Leaf *ausrufeZeichenLeaf = new Leaf(ausrufezeichen);
    if (ausrufeZeichenLeaf->parse(parser)) {
        childrenNodes->put(ausrufeZeichenLeaf);

        Exp2Node *exp2Node = new Exp2Node();
        if (exp2Node->parse(parser)) {
            childrenNodes->put(exp2Node);
            rule = EXP2_NOT_RULE;
            return true;
        } else {
            delete exp2Node;
        }
    } else {
        delete ausrufeZeichenLeaf;
    }

    return false;
}

void Exp2Node::print() {
    cout << "Implement ExpNode::print()." << endl;
}