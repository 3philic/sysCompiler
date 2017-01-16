#include "Parser.h"
#include "TypeCheckVisitor.h"
#include "CodeGeneratorVisitor.h"
#include "FileWriter.h"
#include <iostream>

using namespace std;

int main (int argc, char* argv[]){
	Parser* parser = new Parser(argv[1]);

	// Parse
    cout << "parsing…" << endl;
	parser->parse();

	// TypeCheck
    cout << "type checking…" << endl;
	TypeCheckVisitor *typeCheckVisitor = new TypeCheckVisitor();
	parser->accept(*typeCheckVisitor);

	// Code-Gen
    cout << "generate code…" << endl;
    FileWriter *fileWriter = new FileWriter();
    CodeGeneratorVisitor *codeGeneratorVisitor = new CodeGeneratorVisitor(fileWriter);
    parser->accept(*codeGeneratorVisitor);

    fileWriter->close();
}
