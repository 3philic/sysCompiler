/*
 * DummyBuffer.h
 *
 *  Created on: May 11, 2014
 *      Author: 3philic
 */

#ifndef DUMMYBUFFER_H_
#define DUMMYBUFFER_H_

class DummyBuffer {
public:
	DummyBuffer();
	virtual ~DummyBuffer();

	int lineNo;
	int columnNo;
	char* charArray;

	char getChar();
	int getLineNo();	//aktuelle Position in der Datei
	int getColumnNo();	//aktuelle Position in der Datei
};

#endif /* DUMMYBUFFER_H_ */
