/*
 * TokenLinkedList.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: 3philic
 */

#include "TokenLinkedList.h"
#include <iostream>	//für debugging-Zwecke

TokenLinkedList::TokenLinkedList() {
	first = 0;	//Nullpointer
	last = 0;	//Nullpointer
	size = 0;

	//Testcode folgend
	//addLast(*(new Token(*new String ("int"), integer)));
}

TokenLinkedList::~TokenLinkedList() {
	delete first;
	delete last;
}

bool TokenLinkedList::add(Token* l, int index) {
	//verschoben
}
bool TokenLinkedList::addFirst(Token* l) {
	//verschoben
}
bool TokenLinkedList::addLast(Token* l) {

	TokenNode* oldlast = last;
	last = new TokenNode(l, (TokenNode*) 0, oldlast);	//neues Last-Element wird erstellt

	//wenn Liste vor Aufruf der Methode größer als 0 war, war ein altes "last"-Element vorhanden.
	//Oldlast ist somit != Nullpointer und Oldlast's next Attribut muss somit umgebogen werden auf
	//unser neues "last"-Element
	if (oldlast != 0) {
		oldlast->next = last;
	} else {	//die TokenLinkedList war leer vor Aufrud der Methode
		first = last;
	}
	size++;
}
Token* TokenLinkedList::getToken(int index) {

	if(first == 0)
		return 0;

	TokenNode* runner = first;

	while (index>0) {
		runner = runner->next;
		index--;
	}

	return runner->data;
}
bool TokenLinkedList::exists(Token* l) {

}
int TokenLinkedList::getIndex(Token* l) {	//falls nicht vorhanden: return(-1)
	//verschoben
}
int TokenLinkedList::getSize() {
	return size;
}
bool TokenLinkedList::removeAtIndex(int index) {
	//verschoben
}
bool TokenLinkedList::removeObj(Token* l) {
	//verschoben
}
bool TokenLinkedList::removeFirst() {
	//verschoben
}
bool TokenLinkedList::removeLast() {
	//verschoben
}
