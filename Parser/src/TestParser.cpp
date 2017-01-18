#include "Parser.h"
#include "TypeCheckVisitor.h"
#include "CodeGeneratorVisitor.h"
#include "FileWriter.h"
#include <iostream>

using namespace std;

int main (int argc, char* argv[]){
    char *argV2;
    if (argc >= 3) {
        argV2 = argv[2];
    } else  if (argc == 2) {
        argV2 = "output.code";
    } else {
        cout << "Usage: parser [Inputfile] [Outputfile, optional]" << endl;
        return 1;
    }

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
    FileWriter *fileWriter = new FileWriter(argV2);
    CodeGeneratorVisitor *codeGeneratorVisitor = new CodeGeneratorVisitor(fileWriter);
    parser->accept(*codeGeneratorVisitor);

    fileWriter->close();
}
