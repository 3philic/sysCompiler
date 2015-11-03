#include "Buffer.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

	cout << "Test" << endl;

	Buffer* buffer;

	buffer = new Buffer(argv[1]);

	buffer->fillBuffer();

	for (int i = 0; i < 1024; i++) {

				cout << buffer->getChar();
			}

	cout << "Spalte: " << buffer->column << endl;
	cout << "Zeile: " << buffer->line << endl;
	cout << "aktiver Buffer: " << buffer->getBufferAktuell() << endl;
	cout << "Buffer 1 (durchgelesen): " << buffer->buffer1->finished << endl;
	cout << "Buffer 2 (durchgelesen): " << buffer->buffer2->finished << endl;

	cout << "Buffer 1 folgend:" << endl;
	cout << "Erster char: " << buffer->buffer1->buffer[0] << endl;
	cout << "Zweiter char: " << buffer->buffer1->buffer[1] << endl;
	cout << "Dritter char: " << buffer->buffer1->buffer[2] << endl;

	cout << "Vorvorletzter char: " << buffer->buffer1->buffer[1021] << endl;
	cout << "Vorletzter char: " << buffer->buffer1->buffer[1022] << endl;
	cout << "Letzter char: " << buffer->buffer1->buffer[1023] << endl;

	cout << "Buffer 2 folgend:" << endl;
	cout << "Erster char: " << buffer->buffer2->buffer[0] << endl;
	cout << "Zweiter char: " << buffer->buffer2->buffer[1] << endl;
	cout << "Dritter char: " << buffer->buffer2->buffer[2] << endl;

	cout << "Vorvorletzter char: " << buffer->buffer2->buffer[1021] << endl;
	cout << "Vorletzter char: " << buffer->buffer2->buffer[1022] << endl;
	cout << "Letzter char: " << buffer->buffer2->buffer[1023] << endl;

	cout << "Buffer 1 gelesene Zeichen: " << buffer->buffer1->bytesread << endl;
	cout << "Buffer 2 gelesene Zeichen: " << buffer->buffer2->bytesread << endl;

	/*
	 * Bufferhälfte 2
	 */

	for (int i = 0; i < 4049; i++) {

				cout << buffer->getChar();
			}

//	cout <<endl << "Spalte: " << buffer->column << endl;
//	cout << "Zeile: " << buffer->line << endl;
//	cout << "aktiver Buffer: " << buffer->test() << endl; //aktuellen Buffer ausgeben
//	cout << "Buffer 1 (durchgelesen): " << buffer->buffer1->finished << endl;
//	cout << "Buffer 2 (durchgelesen): " << buffer->buffer2->finished << endl;
//
//	cout << "Erster char: " << buffer->buffer1->buffer[0] << endl;
//
//	cout << "Buffer 1 folgend:" << endl;
//	cout << "Erster char: " << buffer->buffer1->buffer[0] << endl;
//	cout << "Zweiter char: " << buffer->buffer1->buffer[1] << endl;
//	cout << "Dritter char: " << buffer->buffer1->buffer[2] << endl;
//
//	cout << "Vorvorletzter char: " << buffer->buffer1->buffer[1021] << endl;
//	cout << "Vorletzter char: " << buffer->buffer1->buffer[1022] << endl;
//	cout << "Letzter char: " << buffer->buffer1->buffer[1023] << endl;
//
//	cout << "Buffer 2 folgend:" << endl;
//	cout << "Erster char: " << buffer->buffer2->buffer[0] << endl;
//	cout << "Zweiter char: " << buffer->buffer2->buffer[1] << endl;
//	cout << "Dritter char: " << buffer->buffer2->buffer[2] << endl;
//
//	cout << "Vorvorletzter char: " << buffer->buffer2->buffer[1021] << endl;
//	cout << "Vorletzter char: " << buffer->buffer2->buffer[1022] << endl;
//	cout << "Letzter char: " << buffer->buffer2->buffer[1023] << endl;
//
//	cout << "Buffer 1 gelesene Zeichen: " << buffer->buffer1->bytesread << endl;
//	cout << "Buffer 2 gelesene Zeichen: " << buffer->buffer2->bytesread << endl;


	/*
	 * Testausgabe des Buffers
	 */

//	for (int i = 0; i < 2047; i++) {
//
//		cout << buffer->getChar();
//	}

	cout << endl << "Buffer 1 gelesene Zeichen: " << buffer->buffer1->bytesread << endl;
	cout << "Buffer 2 gelesene Zeichen: " << buffer->buffer2->bytesread << endl;
}
