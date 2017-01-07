//
// Created by Jones on 07.01.17.
//

#ifndef RULES_H_
#define RULES_H_

#include <iostream>

enum Rule {
    PROG_RULE,
    DECLS_RULE,
    STATEMENTS_RULE,
    STATEMENT_RULE,
    DECL_RULE,
    ARRAY_RULE,
    EXP_RULE,
    INDEX_RULE,
    ASSIGN_RULE,
    WRITE_RULE,
    READ_RULE,
    BLOCK_RULE,
    IF_RULE,
    WHILE_RULE,
    EXP2_EXP_RULE,
    EXP2_IDENTIFIER_RULE,
    EXP2_INTEGER_RULE,
    EXP2_MINUS_RULE,
    EXP2_NOT_RULE,
    EPSILON_RULE,
    OP_EXP_RULE,
    OPERATOR_RULE
};

inline std::ostream &operator<<(std::ostream &os, const Rule &dt) {

    switch (dt) {
        case PROG_RULE:
            os << "PROG";
            break;
        case DECLS_RULE:
            os << "DECLS";
            break;
        case STATEMENTS_RULE:
            os << "STATEMENTS";
            break;
        case STATEMENT_RULE:
            os << "STATEMENT";
            break;
        case DECL_RULE:
            os << "DECL";
            break;
        case ARRAY_RULE:
            os << "ARRAY";
            break;
        case EXP_RULE:
            os << "EXP";
            break;
        case INDEX_RULE:
            os << "INDEX";
            break;
        case ASSIGN_RULE:
            os << "ASSIGN";
            break;
        case WRITE_RULE:
            os << "WRITE";
            break;
        case READ_RULE:
            os << "READ";
            break;
        case BLOCK_RULE:
            os << "BLOCK";
            break;
        case IF_RULE:
            os << "IF";
            break;
        case WHILE_RULE:
            os << "WHILE";
            break;
        case EXP2_EXP_RULE:
            os << "EXP2_EXP";
            break;
        case EXP2_IDENTIFIER_RULE:
            os << "EXP2_IDENTIFIER";
            break;
        case EXP2_INTEGER_RULE:
            os << "EXP2_INTEGER";
            break;
        case EXP2_MINUS_RULE:
            os << "EXP2_MINUS";
            break;
        case EXP2_NOT_RULE:
            os << "EXP2_NOT";
            break;
        case EPSILON_RULE:
            os << "EPS";
            break;
        case OP_EXP_RULE:
            os << "OP_EXP";
            break;
        case OPERATOR_RULE:
            os << "OP";
            break;
    };

    return os;
}

#endif /* RULE_H_ */
