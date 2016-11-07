#include "Parser.h"
#include <iostream>
using namespace std;

int main (int argc, char* argv[]){
	Parser* parser = new Parser(argv[1]);
	parser->parse();
}
