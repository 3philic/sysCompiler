/*
 * LinkedList.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: 3philic
 */

#include "LinkedList.h"
#include <iostream>	//für debugging-Zwecke

LinkedList::LinkedList() {
	first = 0;	//Nullpointer
	last = 0;	//Nullpointer
	size = 0;

	//Testcode folgend
	//addLast(*(new Token(*new String ("int"), integer)));
}

LinkedList::~LinkedList() {
	delete first;
	delete last;
}

bool LinkedList::add(Token* l, int index) {
	//verschoben
}
bool LinkedList::addFirst(Token* l) {
	//verschoben
}
bool LinkedList::addLast(Token* l) {

	TokenNode* oldlast = last;
	last = new TokenNode(l, (TokenNode*) 0, oldlast);	//neues Last-Element wird erstellt

	//wenn Liste vor Aufruf der Methode größer als 0 war, war ein altes "last"-Element vorhanden.
	//Oldlast ist somit != Nullpointer und Oldlast's next Attribut muss somit umgebogen werden auf
	//unser neues "last"-Element
	if (oldlast != 0) {
		oldlast->next = last;
	} else {	//die LinkedList war leer vor Aufrud der Methode
		first = last;
	}
	size++;
}
Token* LinkedList::getToken(int index) {

	if(first == 0)
		return 0;

	TokenNode* runner = first;

	while (index>0) {
		runner = runner->next;
		index--;
	}

	return runner->data;
}
bool LinkedList::exists(Token* l) {

}
int LinkedList::getIndex(Token* l) {	//falls nicht vorhanden: return(-1)
	//verschoben
}
int LinkedList::getSize() {
	return size;
}
bool LinkedList::removeAtIndex(int index) {
	//verschoben
}
bool LinkedList::removeObj(Token* l) {
	//verschoben
}
bool LinkedList::removeFirst() {
	//verschoben
}
bool LinkedList::removeLast() {
	//verschoben
}
