//
// Created by tim on 14.01.17.
//

#include "CodeGeneratorVisitor.h"

#include "Node.h"
#include "Node/ArrayNode.h"
#include "Node/ProgramNode.h"
#include "Node/DeclsNode.h"
#include "Node/DeclNode.h"
#include "Node/StatementsNode.h"
#include "Node/StatementNode.h"
#include "Node/Leaf.h"
#include "Node/EpsilonNode.h"
#include "Node/Exp2Node.h"
#include "Node/ExpNode.h"
#include "Node/IndexNode.h"
#include "Node/OpExpNode.h"
#include "Node/OpNode.h"

CodeGeneratorVisitor::CodeGeneratorVisitor(FileWriter *fileWriter) {
    this->fileWriter = fileWriter;
}

CodeGeneratorVisitor::~CodeGeneratorVisitor() {

}

void CodeGeneratorVisitor::visit(Leaf &leaf) {

}

void CodeGeneratorVisitor::visit(ProgramNode &programNode) {
    programNode.getChildrenNodes()->get(0)->accept(*this);  //declsNode
    programNode.getChildrenNodes()->get(1)->accept(*this);  //statementsNode

    fileWriter->write("\nSTP");
}

void CodeGeneratorVisitor::visit(DeclsNode &declsNode) {

    if (declsNode.rule == DECLS_RULE) {   // 1. Alternative (Decl;Decls)

        declsNode.getChildrenNodes()->get(0)->accept(*this);    //declNode
        declsNode.getChildrenNodes()->get(2)->accept(*this);    //declsNode

    } else if (declsNode.rule == EPSILON_RULE) {   // 2. Alternative (Epsilon) ;"else if" nur zur Uebersicht der Rules
        //do nothing
    }
}

void CodeGeneratorVisitor::visit(DeclNode &declNode) {
    fileWriter->write("\nDS $");
    Leaf *identifierLeaf = (Leaf *) declNode.getChildrenNodes()->get(2);
    fileWriter->write(identifierLeaf->token->lexem);
    declNode.childrenNodes->get(1)->accept(*this); //arrayNode
}

void CodeGeneratorVisitor::visit(ArrayNode &arrayNode) {

    if (arrayNode.rule == ARRAY_RULE) {   // 1. Alternative [integer]

        fileWriter->write(" ");
        Leaf *integerLeaf = (Leaf *) arrayNode.getChildrenNodes()->get(1);
        fileWriter->write(convertIntToString(*(integerLeaf->token->value)));

    } else if (arrayNode.rule == EPSILON_RULE) {   // 2. Alternative (Epsilon)

        fileWriter->write(" 1");
    }
}

void CodeGeneratorVisitor::visit(StatementsNode &statementsNode) {

    if (statementsNode.rule == STATEMENTS_RULE) {     // 1. Alternative (Statement;Statements)

        statementsNode.getChildrenNodes()->get(0)->accept(*this);    //statementNode
        statementsNode.getChildrenNodes()->get(2)->accept(*this);    //statementsNode

    } else if (statementsNode.rule == EPSILON_RULE) {    // 2. Alternative (Epsilon)

        fileWriter->write("\nNOP");
    }
}

void CodeGeneratorVisitor::visit(StatementNode &statementNode) {

    if (statementNode.rule == ASSIGN_RULE) {  // 1. Alternative (identifier INDEX := EXP)

        Leaf *identifierLeaf = (Leaf *) statementNode.getChildrenNodes()->get(0);

        statementNode.getChildrenNodes()->get(3)->accept(*this); //expNode
        fileWriter->write("\nLA $");
        fileWriter->write(identifierLeaf->token->lexem);
        statementNode.getChildrenNodes()->get(1)->accept(*this); //indexNode
        fileWriter->write("\nSTR");

    } else if (statementNode.rule == WRITE_RULE) {    // 2. Alternative (write( EXP ))

        statementNode.getChildrenNodes()->get(2)->accept(*this);    //expNode
        fileWriter->write("\nPRI");

    } else if (statementNode.rule == READ_RULE) {      // 3. Alternative (read ( identifier INDEX))

        fileWriter->write("\nREA");
        fileWriter->write("\nLA $");
        Leaf *identifierLeaf = (Leaf *) statementNode.getChildrenNodes()->get(2);
        fileWriter->write(identifierLeaf->token->lexem);
        statementNode.getChildrenNodes()->get(3)->accept(*this); //indexNode
        fileWriter->write("\nSTR");

    } else if (statementNode.rule == BLOCK_RULE) {        // 4. Alternative ({STATEMENTS})

        statementNode.childrenNodes->get(1)->accept(*this);     //statementsNode

    } else if (statementNode.rule == IF_RULE) {           // 5. Alternative (if ( EXP ) STATEMENT else STATEMENT)

        statementNode.getChildrenNodes()->get(2)->accept(*this);    //expNode
        char *labelIf = getNewLabel();
        fileWriter->write("\nJIN #label");
        fileWriter->write(labelIf);
        fileWriter->write("\n");
        statementNode.getChildrenNodes()->get(4)->accept(*this);    //statementNode1 (If)
        char *labelElse = getNewLabel();
        fileWriter->write("\nJMP #label");
        fileWriter->write(labelElse);
        fileWriter->write("\n#label");
        fileWriter->write(labelIf);
        fileWriter->write(" NOP\n");
        statementNode.getChildrenNodes()->get(6)->accept(*this);    //statementNod2 (Else)
        fileWriter->write("\n#label");
        fileWriter->write(labelElse);
        fileWriter->write(" NOP\n");

    } else if (statementNode.rule == WHILE_RULE) {         // 6. Alternative (while ( EXP ) STATEMENT)

        char *labelWhileFirst = getNewLabel();
        fileWriter->write("\n#label");
        fileWriter->write(labelWhileFirst);
        fileWriter->write(" NOP\n");
        statementNode.getChildrenNodes()->get(2)->accept(*this); //expNode
        char *labelWhileSecond = getNewLabel();
        fileWriter->write("\nJIN #label");
        fileWriter->write(labelWhileSecond);
        fileWriter->write("\n");
        statementNode.getChildrenNodes()->get(4)->accept(*this); //statementNode
        fileWriter->write("\nJMP #label");
        fileWriter->write(labelWhileFirst);
        fileWriter->write("\n#label");
        fileWriter->write(labelWhileSecond);
        fileWriter->write(" NOP\n");
    }
}

void CodeGeneratorVisitor::visit(IndexNode &indexNode) {

    if (indexNode.rule == INDEX_RULE) {

        indexNode.getChildrenNodes()->get(1)->accept(*this);    //expNode
        fileWriter->write("ADD");

    } else if (indexNode.rule == EPSILON_RULE) {
        //do nothing
    }
}

void CodeGeneratorVisitor::visit(ExpNode &expNode) {
    OpExpNode *opExpNode = (OpExpNode *) expNode.getChildrenNodes()->get(1);
    OpNode *opNode = (OpNode *) opExpNode->getChildrenNodes()->get(0);

    if (opNode->getNodeType() == noType) {
        expNode.getChildrenNodes()->get(0)->accept(*this);  //exp2Node
    } else if (opNode != NULL && opNode->getNodeType() == opGreater) {
        opExpNode->accept(*this);
        expNode.getChildrenNodes()->get(0)->accept(*this);  //exp2Node
        fileWriter->write("LES");
    } else if (opNode != NULL && opNode->getNodeType() == opUnEqual) {
        expNode.getChildrenNodes()->get(0)->accept(*this);  //exp2Node
        opExpNode->accept(*this);
        fileWriter->write("NOT");
    } else {
        expNode.getChildrenNodes()->get(0)->accept(*this);  //exp2Node
        opExpNode->accept(*this);
    }
}

void CodeGeneratorVisitor::visit(Exp2Node &exp2Node) {

    if (exp2Node.rule == EXP2_EXP_RULE) {                     // 1. Alternative ( EXP )

        exp2Node.getChildrenNodes()->get(1)->accept(*this); //expNode

    } else if (exp2Node.rule == EXP2_IDENTIFIER_RULE) {        // 2. Alternative (identifier INDEX)

        fileWriter->write("\nLA $");
        Leaf *identifierLeaf = (Leaf *) exp2Node.getChildrenNodes()->get(0);
        fileWriter->write(identifierLeaf->token->lexem);
        exp2Node.getChildrenNodes()->get(1)->accept(*this); //indexNode
        fileWriter->write("\nLV");

    } else if (exp2Node.rule == EXP2_INTEGER_RULE) {           // 3. Alternative (integer)

        fileWriter->write("\nLC ");
        Leaf *integerLeaf = (Leaf *) exp2Node.getChildrenNodes()->get(0);
        fileWriter->write(convertIntToString(*(integerLeaf->token->value)));

    } else if (exp2Node.rule == EXP2_MINUS_RULE) {             // 4. Alternative (- EXP2 )

        fileWriter->write("\nLC 0");
        exp2Node.getChildrenNodes()->get(1)->accept(*this); //exp2Node
        fileWriter->write("\nSUB");

    } else if (exp2Node.rule == EXP2_NOT_RULE) {              // 5. Alternative ( !EXP2 )

        exp2Node.getChildrenNodes()->get(1)->accept(*this); //exp2Node
        fileWriter->write("NOT");
    }
}

void CodeGeneratorVisitor::visit(OpExpNode &opExpNode) {

    if (opExpNode.rule == OP_EXP_RULE) {      // 1. Alternative (op ext)

        opExpNode.getChildrenNodes()->get(1)->accept(*this);    //expNode
        opExpNode.getChildrenNodes()->get(0)->accept(*this);    //opNode

    } else if (opExpNode.rule == EPSILON_RULE) {   //2. Alternative (Epsilon)

        //do Nothing
    }
}

void CodeGeneratorVisitor::visit(OpNode &opNode) {
    switch (opNode.getNodeType()) {
        case opDiv:
            fileWriter->write("\nDIV");
            break;
        case opEqual:
            fileWriter->write("\nEQU");
            break;
        case opGreater:
            fileWriter->write("");  //siehe EXP::==EXP2 OP_EXP
            break;
        case opLess:
            fileWriter->write("\nLES");
            break;
        case opMinus:
            fileWriter->write("\nSUB");
            break;
        case opMult:
            fileWriter->write("\nMUL");
            break;
        case opPlus:
            fileWriter->write("\nADD");
            break;
        case opUnEqual:
            fileWriter->write("\nEQU"); //siehe EXP::==EXP2 OP_EXP
            break;
        case opAnd:
            fileWriter->write("\nAND");
            break;
        default:
            break;
    };
}

void CodeGeneratorVisitor::visit(EpsilonNode &epsilonNode) {
    // no code generation
}

char *CodeGeneratorVisitor::convertIntToString(int i) {
    char *buffer = new char[10];
    snprintf(buffer, 10, "%d", i);

    return buffer;
}

char *CodeGeneratorVisitor::getNewLabel() {
    char *newLabel = convertIntToString(labelCounter);
    labelCounter++;
    return newLabel;
}




