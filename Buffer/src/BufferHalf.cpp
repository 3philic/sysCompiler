/*
 * BufferHalf.cpp
 *
 *  Created on: 17.05.2014
 *      Author: tim
 */

#include "BufferHalf.h"

BufferHalf::BufferHalf() {

	size = 1024;

	//wird anstatt new benutzt, reserviert 1024 Byte speicher für das char-Array
	//1 char aus der Datei entspricht einem Byte also ist es dann ein charArray
	//mit dem Index 0 bis 1023
	posix_memalign((void**) &buffer, 512, size);

	this->counter = 0;		//aktuelle Stelle in Bufferhälfte
	this->bytesread = 0;	//mit read-Funktion Anzahl eingelesener Bytes
	this->finished = 0;		//ist Bufferhälfte fertig gelesen?

}

BufferHalf::~BufferHalf() {
free(buffer);

}

