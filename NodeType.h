//
// Created by tim on 08.01.17.
//

#ifndef SYSCOMPILER_NODETYPE_H
#define SYSCOMPILER_NODETYPE_H

#include <iostream>

enum NodeType {
    intType,
    intArrayType,
    arrayType,
    noType,
    errorType,
    opPlus,
    opMinus,
    opMult,
    opDiv,
    opLess,
    opGreater,
    opEqual,
    opUnEqual,
    opAnd
};

inline std::ostream &operator<<(std::ostream &os, const NodeType &dt) {

    switch (dt) {
        case intType:
            os << "intType";
            break;
        case intArrayType:
            os << "intArrayType";
            break;
        case arrayType:
            os << "arrayType";
            break;
        case noType:
            os << "noType";
            break;
        case errorType:
            os << "errorType";
            break;
        case opPlus:
            os << "opPlus";
            break;
        case opMinus:
            os << "opMinus";
            break;
        case opMult:
            os << "opMult";
            break;
        case opDiv:
            os << "opDiv";
            break;
        case opLess:
            os << "opLess";
            break;
        case opGreater:
            os << "opGreater";
            break;
        case opEqual:
            os << "opEqual";
            break;
        case opUnEqual:
            os << "opUnEqual";
            break;
        case opAnd:
            os << "opAnd";
            break;
        default:
            os << "UNDEFINED NodeType!";
    };

    return os;
}

#endif //SYSCOMPILER_NODETYPE_H
