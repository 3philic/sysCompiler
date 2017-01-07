/*
 * LinkedList.h
 *
 *  Created on: Apr 6, 2014
 *      Author: 3philic
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "TokenNode.h"
#include "ILinkedList.h"

class Token;

class TokenLinkedList: public ILinkedList {
private:
	int size;
	TokenNode* first;
	TokenNode* last;
public:
	TokenLinkedList();
	virtual ~TokenLinkedList();

	bool add(Token* l, int index);
	bool addFirst(Token* l);
	bool addLast(Token* l);	//wichtig!
	Token* getToken(int index);	//wichtig!
	bool exists(Token* l);
	int getIndex(Token* l);	//falls nicht vorhanden: return(-1)
	int getSize();	//wichtig!
	bool removeAtIndex(int index);
	bool removeObj(Token* l);
	bool removeFirst();
	bool removeLast();
};

#endif /* LINKEDLIST_H_ */
