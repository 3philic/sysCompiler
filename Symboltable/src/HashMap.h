/*
 * HashMap.h
 *
 *  Created on: 07.04.2014
 *      Author: tim
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include "../../TType.h"
#include "../../Token.h"
#include "TokenLinkedList.h"


class HashMap {

private:
	TokenLinkedList* table;
	int size;

public:
	HashMap(int size);
	~HashMap();
	TType getTokenType(String lexem);
	bool insertToken(Token* t);


};

#endif /* HASHMAP_H_ */
