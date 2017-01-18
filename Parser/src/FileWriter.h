//
// Created by tim on 14.01.17.
//

#ifndef SYSCOMPILER_FILEWRITER_H
#define SYSCOMPILER_FILEWRITER_H

#include "../../String.h"
#include <fstream>

class FileWriter{
public:
    FileWriter(char *outputFileName);
    virtual ~FileWriter();

    void write(char* s);
    void write(String s);

    void close();

private:
};
#endif //SYSCOMPILER_FILEWRITER_H
