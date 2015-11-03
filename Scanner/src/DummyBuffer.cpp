/*
 * DummyBuffer.cpp
 *
 *  Created on: May 11, 2014
 *      Author: 3philic
 */

#include "DummyBuffer.h"

DummyBuffer::DummyBuffer() {
	columnNo = 1;
	lineNo = 1;
	charArray = "int 123 test";

}

DummyBuffer::~DummyBuffer() {
	// TODO Auto-generated destructor stub
}

char DummyBuffer::getChar() {
	if (*charArray == '\0') {
		columnNo = 0;
		lineNo = 0;
		return '#';
	} else {
		char temp = *charArray;

		if (*charArray == '\n') {
			columnNo = 1;
			lineNo++;
		}
		else {
			columnNo++;
		}

		charArray++;

		return temp;
	}
}

int DummyBuffer::getLineNo() {
	return lineNo;
}
int DummyBuffer::getColumnNo() {
	return columnNo;
}
