#include "Parser.h"
#include "TypeCheckVisitor.h"
#include <iostream>

using namespace std;

int main (int argc, char* argv[]){
	Parser* parser = new Parser(argv[1]);

	// Parse
	parser->parse();

	// Test Visit
	TypeCheckVisitor *visitor = new TypeCheckVisitor();
	parser->accept(*visitor);
}
