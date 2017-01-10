//
// Created by root on 08.01.17.
//

#include "TypeCheckVisitor.h"


void TypeCheckVisitor::visit(Leaf &leaf){
    //do nothing: type is set by parent nodes of leafs
}

void TypeCheckVisitor::visit(ProgramNode &programNode){
    programNode.accept(*this);
    programNode.setNodeType(noType); //nur zur Uebersicht. nodeType hat initial den Wert noType.
}

void TypeCheckVisitor::visit(DeclsNode &declsNode){

    if(declsNode.rule == DECLS_RULE){

        declsNode.accept(*this);
        declsNode.setNodeType(noType);

    }else if(declsNode.rule == EPSILON_RULE){   //"else if" nur zur Uebersicht der Rules

        declsNode.setNodeType(noType);
    }
}

void TypeCheckVisitor::visit(DeclNode &declNode) {
    declNode.accept(*this);

    Node* arrayNode = (Node*) declNode.getChildrenNodes()->get(1);
    Leaf* identifierLeaf = (Leaf*) declNode.getChildrenNodes()->get(2);

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

    if(arrayNode.rule == ARRAY_RULE){

        Leaf* integerLeaf = (Leaf*) arrayNode.getChildrenNodes()->get(1);

        if(integerLeaf->token->value > 0){
            arrayNode.setNodeType(arrayType);
        }else{
            printError("No valid dimension", integerLeaf->token->lineNo, integerLeaf->token->columnNo);
            arrayNode.setNodeType(errorType);
        }

    }else if(arrayNode.rule == EPSILON_RULE){

        arrayNode.setNodeType(noType);
    }
}

void TypeCheckVisitor::visit(EpsilonNode &epsilonNode) {
    epsilonNode.setNodeType(noType);
}

void TypeCheckVisitor::visit(StatementsNode &statementsNode) {

    if(statementsNode.rule == STATEMENTS_RULE){

        statementsNode.accept(*this);
        statementsNode.setNodeType(noType);

    }else if(statementsNode.rule == EPSILON_RULE){

        statementsNode.setNodeType(noType);

    }

}

void TypeCheckVisitor::visit(StatementNode &statementNode){

    if(statementNode)
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





