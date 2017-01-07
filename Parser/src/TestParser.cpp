#include "Parser.h"
#include "PrintingVisitor.h"
#include <iostream>
using namespace std;

int main (int argc, char* argv[]){
	Parser* parser = new Parser(argv[1]);

	// Parse
	parser->parse();

	// Test Visit
	PrintingVisitor *visitor = new PrintingVisitor();
	parser->accept(*visitor);
}
