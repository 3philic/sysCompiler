//
// Created by tim on 14.01.17.
//

#ifndef SYSCOMPILER_FILEWRITER_H
#define SYSCOMPILER_FILEWRITER_H

#include "../../String.h"

class FileWriter{
public:
    FileWriter();
    ~FileWriter();

    void write(char* s);
    void write(String s);
};
#endif //SYSCOMPILER_FILEWRITER_H
