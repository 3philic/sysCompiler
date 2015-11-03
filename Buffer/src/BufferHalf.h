/*
 * BufferHalf.h
 *
 *  Created on: 17.05.2014
 *      Author: tim
 */

#ifndef BUFFERHALF_H_
#define BUFFERHALF_H_

#include <unistd.h>	//posix_memalign()
#include <stdlib.h>	//read()
#include <iostream>
#include <fstream>
#include <fcntl.h>	//open()
#include <cstdlib>

class BufferHalf {
public:
	BufferHalf();
	virtual ~BufferHalf();
	char* buffer;
	int counter;
	int bytesread;
	int size;
	int finished;
};



#endif /* BUFFERHALF_H_ */
