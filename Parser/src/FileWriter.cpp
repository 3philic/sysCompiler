//
// Created by tim on 14.01.17.
//

#include "FileWriter.h"

using namespace std;

FileWriter::FileWriter(){
//    outfile->open("~/Desktop/output.txt");
}

FileWriter::~FileWriter() {

}

void FileWriter::write(char* s) {
//    *outfile << s;
    cout << s;
}

void FileWriter::write(String s) {
//    *outfile << s;
    cout << s;
}
