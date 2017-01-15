//
// Created by tim on 14.01.17.
//

#include "FileWriter.h"

using namespace std;

static ofstream outfile;

FileWriter::FileWriter(){
    outfile.open("output.txt");
}

FileWriter::~FileWriter() {

}

void FileWriter::write(char* s) {
    outfile << s;
}

void FileWriter::write(String s) {
    outfile << s;
}

void FileWriter::close() {
    outfile.close();
}
