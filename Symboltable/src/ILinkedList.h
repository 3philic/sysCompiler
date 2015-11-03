/*
 * ILinkedList.h
 *
 *  Created on: Apr 6, 2014
 *      Author: 3philic
 */

#ifndef ILINKEDLIST_H_
#define ILINKEDLIST_H_
#include "../../Token.h"

class ILinkedList {
public:
	virtual ~ILinkedList(){}

	//folgend: Methoden, die von einer späteren Implementierung geerbt werden müssen

	// nach Tutorial unter: http://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
	// pure virtual functions providing interface framework.
	   virtual bool add (Token* l, int index) = 0;
	   virtual bool addFirst (Token* l) = 0;
	   virtual bool addLast (Token* l) = 0;
	   virtual Token* getToken (int index) = 0;
	   virtual bool exists (Token* l) = 0;
	   virtual int getIndex (Token* l) = 0;	//falls nicht vorhanden: return(-1)
	   virtual int getSize () = 0;
	   virtual bool removeAtIndex (int index) = 0;
	   virtual bool removeObj (Token* l) = 0;
	   virtual bool removeFirst () = 0;
	   virtual bool removeLast () = 0;

};

#endif /* ILINKEDLIST_H_ */
