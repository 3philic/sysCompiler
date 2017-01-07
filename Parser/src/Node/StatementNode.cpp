//
// Created by Kishor Rana on 07/01/2017.
//

#include "StatementNode.h"
#include "Leaf.h"
#include "IndexNode.h"
#include "ExpNode.h"
#include "StatementsNode.h"

using namespace std;

StatementNode::StatementNode() {
}

StatementNode::~StatementNode() {
    // TODO Auto-generated destructor stub
}

bool StatementNode::parse(Parser &parser) {

    // 1. Alternative (identifier INDEX := EXP)
    Leaf *identifierLeaf = new Leaf(identifier);
    if (identifierLeaf->parse(parser)) {
        childrenNodes->put(identifierLeaf);

        IndexNode *indexNode = new IndexNode();
        if (indexNode->parse(parser)) {
            childrenNodes->put(indexNode);

            Leaf *doppelpunktGleichLeaf = new Leaf(doppeltpunktGleich);
            if (doppelpunktGleichLeaf->parse(parser)) {
                childrenNodes->put(doppelpunktGleichLeaf);

                ExpNode *expNode = new ExpNode();
                if (expNode->parse(parser)) {
                    childrenNodes->put(expNode);
                    rule = ASSIGN_RULE;
                    return true;
                } else {
                    delete expNode;
                }
            } else {
                delete doppelpunktGleichLeaf;
            }
        } else {
            delete indexNode;
        }
    } else {
        delete identifierLeaf;
    }

    deleteChildrenNodes();
    // 2. Alternative (write( EXP ))
    Leaf *writeLeaf = new Leaf(writeToken);
    if (writeLeaf->parse(parser)) {
        childrenNodes->put(writeLeaf);

        Leaf *rundeKlammerAufLeaf = new Leaf(rundeKlammerAuf);
        if (rundeKlammerAufLeaf->parse(parser)) {
            childrenNodes->put(rundeKlammerAufLeaf);

            ExpNode *expNode = new ExpNode();
            if (expNode->parse(parser)) {
                childrenNodes->put(expNode);

                Leaf *rundeKlammerZuLeaf = new Leaf(rundeKlammerZu);
                if (rundeKlammerZuLeaf->parse(parser)) {
                    childrenNodes->put(rundeKlammerZuLeaf);
                    rule = WRITE_RULE;
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
    } else {
        delete writeLeaf;
    }

    deleteChildrenNodes();
    // 3. Alternative (read ( identifier INDEX))
    Leaf *readLeaf = new Leaf(readToken);
    if (readLeaf->parse(parser)) {
        childrenNodes->put(readLeaf);

        Leaf *rundeKlammerAufLeaf = new Leaf(rundeKlammerAuf);
        if (rundeKlammerAufLeaf->parse(parser)) {
            childrenNodes->put(rundeKlammerAufLeaf);

            Leaf *identifierLeaf = new Leaf(identifier);
            if (identifierLeaf->parse(parser)) {
                childrenNodes->put(identifierLeaf);

                IndexNode *indexNode = new IndexNode();
                if (indexNode->parse(parser)) {
                    childrenNodes->put(indexNode);

                    Leaf *rundeKlammerZuLeaf = new Leaf(rundeKlammerZu);
                    if (rundeKlammerZuLeaf->parse(parser)) {
                        childrenNodes->put(rundeKlammerZuLeaf);
                        rule = READ_RULE;
                        return true;
                    } else {
                        delete rundeKlammerZuLeaf;
                    }
                } else {
                    delete indexNode;
                }
            } else {
                delete identifierLeaf;
            }
        } else {
            delete rundeKlammerAufLeaf;
        }
    } else {
        delete readLeaf;
    }

    deleteChildrenNodes();
    // 4. Alternative ({STATEMENTS})
    Leaf *geschweifteKlammerAufLeaf = new Leaf(geschweifteKlammerAuf);
    if (geschweifteKlammerAufLeaf->parse(parser)) {
        childrenNodes->put(geschweifteKlammerAufLeaf);

        StatementsNode *statementsNode = new StatementsNode();
        if (statementsNode->parse(parser)) {
            childrenNodes->put(statementsNode);

            Leaf *geschweifteKlammerZuLeaf = new Leaf(geschweifteKlammerZu);
            if (geschweifteKlammerZuLeaf->parse(parser)) {
                childrenNodes->put(geschweifteKlammerZuLeaf);
                rule = STATEMENT_RULE;
                return true;
            } else {
                delete geschweifteKlammerZuLeaf;
            }
        } else {
            delete statementsNode;
        }
    } else {
        delete geschweifteKlammerAufLeaf;
    }

    deleteChildrenNodes();
    // 5. Alternative (if ( EXP ) STATEMENT else STATEMENT)
    Leaf *ifLeaf = new Leaf(IF);
    if (ifLeaf->parse(parser)) {
        childrenNodes->put(ifLeaf);

        Leaf *rundeKlammerAufLeaf = new Leaf(rundeKlammerAuf);
        if (rundeKlammerAufLeaf->parse(parser)) {
            childrenNodes->put(rundeKlammerAufLeaf);

            ExpNode *expNode = new ExpNode();
            if (expNode->parse(parser)) {
                childrenNodes->put(expNode);

                Leaf *rundeKlammerZuLeaf = new Leaf(rundeKlammerZu);
                if (rundeKlammerZuLeaf->parse(parser)) {
                    childrenNodes->put(rundeKlammerZuLeaf);

                    StatementNode *statementNode = new StatementNode();
                    if (statementNode->parse(parser)) {
                        childrenNodes->put(statementNode);

                        Leaf *elseLeaf = new Leaf(ELSE);
                        if (elseLeaf->parse(parser)) {
                            childrenNodes->put(elseLeaf);

                            StatementNode *statementNode2 = new StatementNode();
                            if (statementNode2->parse(parser)) {
                                childrenNodes->put(statementNode2);
                                rule = IF_RULE;
                                return true;
                            } else {
                                delete statementNode2;
                            }
                        } else {
                            delete elseLeaf;
                        }
                    } else {
                        delete statementNode;
                    }
                } else {
                    delete rundeKlammerZuLeaf;
                }
            } else {
                delete expNode;
            }
        } else {
            delete rundeKlammerAufLeaf;
        }
    } else {
        delete ifLeaf;
    }

    deleteChildrenNodes();
    // 6. Alternative (while ( EXP ) STATEMENT)
    Leaf *whileLeaf = new Leaf(WHILE);
    if (whileLeaf->parse(parser)) {
        childrenNodes->put(whileLeaf);

        Leaf *rundeKlammerAufLeaf = new Leaf(rundeKlammerAuf);
        if (rundeKlammerAufLeaf->parse(parser)) {
            childrenNodes->put(rundeKlammerAufLeaf);

            ExpNode *expNode = new ExpNode();
            if (expNode->parse(parser)) {
                childrenNodes->put(expNode);

                Leaf *rundeKlammerZuLeaf = new Leaf(rundeKlammerZu);
                if (rundeKlammerZuLeaf->parse(parser)) {
                    childrenNodes->put(rundeKlammerZuLeaf);

                    StatementNode *statementNode = new StatementNode();
                    if (statementNode->parse(parser)) {
                        childrenNodes->put(statementNode);
                        rule = WHILE_RULE;
                        return true;
                    } else {
                        delete statementNode;
                    }
                } else {
                    delete rundeKlammerZuLeaf;
                }
            } else {
                delete expNode;
            }
        } else {
            delete rundeKlammerAufLeaf;
        }
    } else {
        delete whileLeaf;
    }

    return false;
}

void StatementNode::print() {
    cout << "Implement StatementNode::print()." << endl;
}