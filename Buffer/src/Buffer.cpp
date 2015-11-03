/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Buffer.h"
#include <iostream>

Buffer::Buffer(char* path) {
	buffer1 = new BufferHalf();
	buffer2 = new BufferHalf();

	//öffnet Textdatei, file_descriptor muss read-Funktion übergeben werden
#ifdef __APPLE__
	this->file_descriptor = open(path, O_RDONLY);
#else	//aka: #ifdef __linux__
	this->file_descriptor = open(path, O_DIRECT | O_RDONLY);
#endif

	this->bufferAktuell = buffer1;
	this->column = 1;
	this->line = 1;
}

Buffer::~Buffer() {
	delete (this->buffer1);
	delete (this->buffer2);
}

/*
 * wechselt die Bufferhälften
 */
void Buffer::changeBuffer() {

	if (this->bufferAktuell == buffer1) {
		this->bufferAktuell = buffer2;
	} else {
		this->bufferAktuell = buffer1;
	}
}


/*
 * liefert das aktuelle Zeichen zurück und zählt counter hoch
 * wechselt die Bufferhälften und füllt die nächste auf, falls man
 * am Ende der aktuellen Bufferhälfte angelangt ist
 * gibt # zurück, falls man am Ende der Datei ist
 */
char Buffer::getChar() {
	//Erkenntnisse:
	//1. die read-Funktion übernimmt \n als Nullterminator vom Dateiende ans Ende im Buffer
	//2. char-Array ist anfangs voll mit \0

	//# wird zurückgegeben wenn
	//(das aktuelle Zeichen im Buffer der Nullterminator ist)
	//ODER
	//(das aktuelle Zeichen im Buffer \n ist und das nächste der Nullterminator
	//und man nicht am Ende des Buffers ist)
	if ( bufferAktuell->buffer[bufferAktuell->counter] == '\0' ||(bufferAktuell->buffer[bufferAktuell->counter] == '\n'
			&& bufferAktuell->buffer[bufferAktuell->counter + 1] == '\0'
			&& bufferAktuell->counter < 1023)) {
		return '#';
	}

	//Spalte hochzählen und Zeile hochzählen falls aktuelles Zeichen \n ist (Zeilenumbruch)
	this->column++;
	if (bufferAktuell->buffer[bufferAktuell->counter] == '\n') {
		this->line++;
		this->column = 1;
	}

	char charBuffer = '#';
	if (this->bufferAktuell->counter == 1023) {	//wurde buffer schon vollständig gelesen mit getChar() ?
		bufferAktuell->finished = 1; //bufferhälfte "durchgelesen" setzen
		charBuffer = bufferAktuell->buffer[bufferAktuell->counter]; //letztes Zeichen der aktuellen Bufferhälfte zwischenspeichern bevor Bufferhälften gewechselt werden
		this->fill(); //Bufferhälften wechseln und auffüllen

	//# zurückgeben, falls letztes Zeichen der letzten Bufferhälfte Nullterminator aus
	//der Datei ist (\n) und erstes der nächsten Bufferhälfte \0 ist, also die Datei genau
	//in die vorherige Bufferhälfte gepasst hat
		if (bufferAktuell->buffer[0] == '\0' && charBuffer == '\n') {
			return '#';
		}
	}
	//falls charBuffer unberührt, also noch # ganz normal aktuelle Stelle ausgeben
	if (charBuffer == '#') {
		char temp = bufferAktuell->buffer[bufferAktuell->counter];
		bufferAktuell->counter++;
		return temp;
	//falls charBuffer verändert wurde, also letzten char der letzten Bufferhälfte enthält, diese ausgeben
	} else {
		return charBuffer;
	}
}

/*
 * wechselt Bufferhälften, falls aktuelle voll ist und durchgelesen, setzt
 * counter und finished der neuen aktuellen Bufferhälfte 0 und füllt sie auf
 */
void Buffer::fill() {
	if (this->bufferAktuell->bytesread == 1024
			&& bufferAktuell->finished == 1) {
		this->changeBuffer();
		this->bufferAktuell->counter = 0;
		this->bufferAktuell->finished = 0;
		this->fillBuffer();
	}
}

/*
 * füllt die aktuelle Bufferhälfte auf
 */
void Buffer::fillBuffer() {

	bufferAktuell = new BufferHalf ();

	//liest aus der Datei in das angegebene Array ab der zuletzt gelesenen Stelle 1024 Zeichen aus der Datei ein
	int bytes = read(file_descriptor, bufferAktuell->buffer, 1024);

	bufferAktuell->bytesread = bytes;

}

/**
 * gibt aktuelle Bufferhälfte aus
 */
char* Buffer::getBufferAktuell() {
	if (this->bufferAktuell == this->buffer1) {
		return "buffer1";
	} else {
		return "buffer2";
	}
}

int Buffer::getLineNo(){
	return this->line;
}

int Buffer::getColumnNo(){
	return this->column;
}
