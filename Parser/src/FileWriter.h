//
// Created by tim on 14.01.17.
//

#ifndef SYSCOMPILER_FILEWRITER_H
#define SYSCOMPILER_FILEWRITER_H

#include "../../String.h"
#include <iostream>

class FileWriter{
public:
    FileWriter();
    virtual ~FileWriter();

    void write(char* s);
    void write(String s);

private:
    std::ofstream* outfile;
};
#endif //SYSCOMPILER_FILEWRITER_H
