//
// Created by Kishor Rana on 15/01/2017.
//

#ifndef SYSCOMPILER_TOKENINFORMATION_H
#define SYSCOMPILER_TOKENINFORMATION_H

#include "NodeType.h"

class TokenInformation {
public:
    TokenInformation();
    virtual ~TokenInformation();

    NodeType nodeType;
};


#endif //SYSCOMPILER_TOKENINFORMATION_H
