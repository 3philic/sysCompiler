//
// Created by tim on 08.01.17.
//

#include "TypeCheckVisitor.h"


void TypeCheckVisitor::visit(Leaf &leaf){
    //do nothing: type is set by parent nodes of leafs
}

void TypeCheckVisitor::visit(ProgramNode &programNode){
    programNode.getChildrenNodes()->get(0)->accept(*this);  //declsNode
    programNode.getChildrenNodes()->get(1)->accept(*this);  //statementsNode
    programNode.setNodeType(noType); //nur zur Uebersicht. nodeType hat initial den Wert noType.
}

void TypeCheckVisitor::visit(DeclsNode &declsNode){

    if(declsNode.rule == DECLS_RULE){   // 1. Alternative (Decl;Decls)

        declsNode.getChildrenNodes()->get(0)->accept(*this);    //declNode
        declsNode.getChildrenNodes()->get(2)->accept(*this);    //declsNode
        declsNode.setNodeType(noType);

    }else if(declsNode.rule == EPSILON_RULE){   // 2. Alternative (Epsilon) ;"else if" nur zur Uebersicht der Rules

        declsNode.setNodeType(noType);
    }
}

void TypeCheckVisitor::visit(DeclNode &declNode) {

    Node* arrayNode = (Node*) declNode.getChildrenNodes()->get(1);
    Leaf* identifierLeaf = (Leaf*) declNode.getChildrenNodes()->get(2);

    arrayNode->accept(*this);

    // (int array identifier)
    if(identifierLeaf->getNodeType() != noType) {
        printError("Identifier already defined", identifierLeaf->token->lineNo, identifierLeaf->token->columnNo);
        declNode.setNodeType(errorType);
    }else if(arrayNode->getNodeType() == errorType) {
        declNode.setNodeType(errorType);
    }else{
        declNode.setNodeType(noType);
        if(arrayNode->getNodeType() == arrayType){
            identifierLeaf->setNodeType(intArrayType);
        }else{
            identifierLeaf->setNodeType(intType);
        }
    }
}

void TypeCheckVisitor::visit(ArrayNode &arrayNode) {

    if(arrayNode.rule == ARRAY_RULE){   // 1. Alternative [integer]

        Leaf* integerLeaf = (Leaf*) arrayNode.getChildrenNodes()->get(1);

        if(integerLeaf->token->value > 0){
            arrayNode.setNodeType(arrayType);
        }else{
            printError("No valid dimension", integerLeaf->token->lineNo, integerLeaf->token->columnNo);
            arrayNode.setNodeType(errorType);
        }

    }else if(arrayNode.rule == EPSILON_RULE){   // 2. Alternative (Epsilon)

        arrayNode.setNodeType(noType);
    }
}



void TypeCheckVisitor::visit(StatementsNode &statementsNode) {

    if(statementsNode.rule == STATEMENTS_RULE){     // 1. Alternative (Statement;Statements)

        statementsNode.getChildrenNodes()->get(0).accept(*this);    //statementNode
        statementsNode.getChildrenNodes()->get(2).accept(*this);    //statementsNode
        statementsNode.setNodeType(noType);

    }else if(statementsNode.rule == EPSILON_RULE){    // 2. Alternative (Epsilon)

        statementsNode.setNodeType(noType);

    }

}

void TypeCheckVisitor::visit(StatementNode &statementNode){


    if(statementNode.rule == ASSIGN_RULE) {  // 1. Alternative (identifier INDEX := EXP)


        Leaf *identifierLeaf = statementNode.getChildrenNodes()->get(0);
        IndexNode *indexNode = statementNode.getChildrenNodes().get(1);
        ExpNode *expNode = statementNode.getChildrenNodes()->get(3);

        expNode->accept(*this);
        indexNode->accept(*this);

        if (identifierLeaf->getNodeType() == noType) {
            printError("Identifier not defined", identifierLeaf->token->lineNo, identifierLeaf->token->columnNo);
            statementNode.setNodeType(errorType);
        } else if (expNode->getNodeType() == intType
                   && ((identifierLeaf->getNodeType() == intType && indexNode->getNodeType() == noType)
                       || (identifierLeaf->getNodeType() == intArrayType && indexNode->getNodeType() == arrayType))) {
            statementNode.setNodeType(noType);
        } else {
            printError("Incompatible types", identifierLeaf->token->lineNo, identifierLeaf->token->columnNo);
            statementNode.setNodeType(errorType);
        }


    }else if(statementNode.rule == WRITE_RULE) {    // 2. Alternative (write( EXP ))


        statementNode.getChildrenNodes()->get(2)->accept(*this);    //expNode
        statementNode.setNodeType(noType);


    }else if(statementNode.rule == READ_RULE) {      // 3. Alternative (read ( identifier INDEX))


        Leaf *identifierLeaf = statementNode.getChildrenNodes()->get(2);
        IndexNode *indexNode = statementNode.getChildrenNodes().get(3);

        indexNode->accept(*this);

        if (identifierLeaf->getNodeType() == noType) {
            printError("Identifier not defined", identifierLeaf->token->lineNo, identifierLeaf->token->columnNo);
            statementNode.setNodeType(errorType);
        } else if (((identifierLeaf->getNodeType() == intType)
                    && indexNode->getNodeType() == noType)
                   || ((identifierLeaf->getNodeType() == intArrayType)
                       && indexNode->getNodeType() == arrayType)) {
            statementNode.setNodeType(noType);
        } else {
            statementNode.setNodeType(errorType);
            printError("Incompatible types", identifierLeaf->token->lineNo, identifierLeaf->token->columnNo);
        }


    }else if(statementNode.rule == BLOCK_RULE) {        // 4. Alternative ({STATEMENTS})


        statementNode.childrenNodes->get(1)->accept(*this);     //statementsNode
        statementNode.setNodeType(noType);


    }else if(statementNode.rule == IF_RULE) {           // 5. Alternative (if ( EXP ) STATEMENT else STATEMENT)


        ExpNode *expNode = statementNode.getChildrenNodes()->get(2);
        expNode->accept(*this);
        statementNode.getChildrenNodes()->get(4)->accept(*this);    //statementNode1 (If)
        statementNode.getChildrenNodes()->get(6)->accept(*this);    //statementNod2 (Else)

        if (expNode->getNodeType() == errorType) {
            statementNode.setNodeType(errorType);
        } else {
            statementNode.setNodeType(noType);
        }


    }else if(statementNode.rule == WHILE_RULE){         // 6. Alternative (while ( EXP ) STATEMENT)


        ExpNode *expNode = statementNode.getChildrenNodes()->get(2);
        expNode->accept(*this);
        statementNode.getChildrenNodes()->get(4).accept(*this); //statementNode

        if(expNode->getNodeType() == errorType){
            statementNode.setNodeType(errorType);
        }else{
            statementNode.setNodeType(noType);
        }

    }
}

void TypeCheckVisitor::visit(EpsilonNode &epsilonNode) {
    epsilonNode.setNodeType(noType);
}

void TypeCheckVisitor::printError(char* messageOutput, int lineOutput, int columnOutput) {
    fprintf(stderr, "\nError Line: ");
    fprintf(stderr, "%d", lineOutput);
    fprintf(stderr, " Column: ");
    fprintf(stderr, "%d", columnOutput);
    fprintf(stderr, " ");
    fprintf(stderr, messageOutput);
    fprintf(stderr, "\n");
    exit(1);
}





