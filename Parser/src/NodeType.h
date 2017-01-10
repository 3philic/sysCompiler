//
// Created by root on 08.01.17.
//

#ifndef SYSCOMPILER_NODETYPE_H
#define SYSCOMPILER_NODETYPE_H
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
#endif //SYSCOMPILER_NODETYPE_H
