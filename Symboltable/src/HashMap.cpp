/*
 * HashMap.cpp
 *
 *  Created on: 07.04.2014
 *      Author: tim
 */

#include "HashMap.h"
#include <iostream>
using namespace std;

/*
 * HashMap besteht aus Listen die aus Objekten vom Typ Token bestehen.
 */

HashMap::HashMap(int size) {
	this->size = size;
	this->table = new LinkedList[size];


}



/*
 * getTokenType nimmt als Argument einen String und durchsucht die HashMap
 * nach einem Objekt vom Typ Token, bei dem dieser String übereinstimmt
 * und gibt den zugehörigen TType zurück
 * String lexem ist hier im Prinzip der Key und der TType der Value
 */
TType HashMap::getTokenType(String lexem) {
	//Zeile in der HashMap durch hashCode des Strings berechnen
	int index = lexem.hashCode() % this->size;

	//falls Zeile leer: null
	if (this->table[index].getSize() == 0) {
		return null;
	} else {
	//falls Zeile nicht leer, sequenziell LinkedList nach gesuchtem String durchsuchen
	//und TType des zugehörigen Tokens zurückgeben
		for (int i = 0; i < table[index].getSize(); i++) {

			Token* current = table[index].getToken(i);

			if (current->lexem.equals(lexem)) {
				return current->type;
			}
		}
	}
	return null;
}


/*
 * insertToken setzt ein Token in die HashMap
 */
bool HashMap::insertToken(Token* t){

	//hashCode des Strings von Token bestimmt die Zeile in der HashMap
	 int index = t->lexem.hashCode() % this->size;

	 this->table[index].addLast(t);
	 return true;

}


