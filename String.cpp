#include <iostream>
#include <stdlib.h>
using namespace std;

#include "String.h"

String::String() {
	size = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(char c) {
	size = 1;
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
}

String::String(const char *s) {
	size = 0;
	const char* runner = s;

	//zählen der Anzahl der Characters im übergebenen String (ohne '\0')
	while (*runner != '\0') {
		runner++;
		size++;
	}
	str = new char[size + 1];

	runner = s; //zurücksetzen des Runners auf s
	//kopieren aller einzelnen Characters in Zielstring an Startposition str
	for (int i = 0; i < size; i++) {
		str[i] = *runner;
		runner++;
	}
	str[size] = '\0';
}

String::String(const String& s) {
	size = s.size;
	str = new char[size + 1];

	const char* runner = s.str;
	runner = s.str; //setzen des Runners auf s.str
	//kopieren aller einzelnen Characters in Zielstring an Startposition str
	for (int i = 0; i < size; i++) {
		str[i] = *runner;
		runner++;
	}
	str[size] = '\0';
}

String::~String() {
	delete[] str;
}

char& String::operator[](int index) {
	return this->str[index];
}

String& String::operator=(String& s) {
	if (&s == this) {
		return *this;
	}

	this->size = s.size;
	delete[] str;
	this->str = new char[size + 1];

	const char* runner = s.str;
	runner = s.str; //setzen des Runners auf s.str
	//kopieren aller einzelnen Characters in Zielstring an Startposition str
	for (int i = 0; i < size; i++) {
		str[i] = *runner;
		runner++;
	}
	str[size] = '\0';

	return *this;
}

String& String::operator+=(String& s) {
	int oldsize = this->size;
	this->size += s.size;
	const char* oldstr = this->str;
	this->str = new char[this->size + 1];

	//kopieren des ersten Strings in neu erstellten zurückzugebenden String
	const char* runner = oldstr;    //setzen des Runners auf den alten String
	//kopieren aller einzelnen Characters in Zielstring an Startposition str
	for (int i = 0; i < oldsize; i++) {
		str[i] = *runner;
		runner++;
	}
	delete[] oldstr;   //alter String wird nicht mehr benötigt

	//kopieren des zweiten Strings in neu erstellten zurückzugebenden String
	runner = s.str;    //setzen des Runners auf den neuen String
	//kopieren aller einzelnen Characters in Zielstring an Startposition str
	for (int i = oldsize; i < s.size + oldsize; i++) {
		str[i] = *runner;
		runner++;
	}

	str[size] = '\0';
	return *this;
}

bool String::equals(String s) {
	if (this == &s)
		return true;

	if (size == s.size) {
		for (int i = 0; i < size; i++) {
			if (str[i] != s.str[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

int String::hashCode() {
	int hashWert = 0;
	for (int i = 0; i < size; i++) {
		hashWert += str[i] * (i + 1);
	}
	return hashWert;
}

// Zeigt Error auf der Konsole an, wenn Konversion mittels strtol fehlschlägt!
long String::value() {
	errno = 0;

	//long mit Basis 10 wird vom internen c-Style String geparst
	long val = std::strtol(this->str, 0, 10);
	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
	                   || (errno != 0 && val == 0)) {
	               cerr << "strtol: read out value out of range of representable values by a long, or no valid conversion possible" << endl;
	           }

	return val;
}

ostream& operator<<(ostream &out, String &s) {
	for (int i = 0; i < s.size; i++) {
		out << s.str[i];
	}

	return out;
}
