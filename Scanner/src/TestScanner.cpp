#include "Scanner.h"
#include <stdio.h>
#include <time.h>
using namespace std;

int main(int argc, char **argv) {

    Scanner *scanner;
    scanner = new Scanner(argv[1]);

    time_t start,end;
    time(&start);

    ofstream outfile;
    outfile.open("output.txt");

    while (true) {
        Token *token = scanner->nextToken();

        // Abbruchbedingung	(Lexem:"#" ist das Abbruchzeichen des Automaten)
        if (token->lexem.equals(*new String('#'))) {
            outfile << "EOF";
            break;
        }

        // print-out
        outfile << "Token " << TTypeToString(token->type);
        outfile << "\tLine: " << token->lineNo << " Column: " << token->columnNo;
        if (token->type == identifier) {
            outfile << "\tLexem: " << token->lexem;
        }
        if (token->type == integer) {
            outfile << "\tValue: " << *(token->value);
        }
        outfile << endl;
    }
    outfile.close();

    time(&end);
    double dif = difftime(end,start);
    printf("Elapsed time is %.2lf seconds.", dif);

}

