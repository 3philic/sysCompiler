/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include "BufferHalf.h"
#include <stdlib.h>	//read()

class Buffer{

public:
	BufferHalf* bufferAktuell;	//aktuelle Bufferhälfte
	BufferHalf* buffer1;		//Bufferhälfte 1
	BufferHalf* buffer2;		//Bufferhälfte 2
	int file_descriptor;
	int column;
	int line;
	Buffer(char* path);
	virtual ~Buffer();
	char getChar();		//gibt Char an der aktuellen Stelle zurück
	int getLineNo();		//aktuelle Zeile in der Datei
	int getColumnNo();	//aktuelle Spalte in der Datei
	void changeBuffer();
	void fill();		//wechselt aktuellen Buffer und füllt ihn auf
	void fillBuffer();	//füllt Buffer auf
	char* getBufferAktuell();	//gibt aktuelle Bufferhälfte als String zurück
};

#endif /* BUFFER_H_ */
