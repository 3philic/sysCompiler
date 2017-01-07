#include "Scanner.h"
#include <stdio.h>
#include <time.h>
using namespace std;


const char* TTypeToString(TType a) {
    switch (a) {
        case null:
            return "0";
        case integer:
            return "integer";
        case identifier:
            return "identifier";
        case lexem:
            return "lexem";
        case IF:
            return "if";
        case WHILE:
            return "while";
        case kommentar:
            return "kommentar";
        case plusToken:
            return "plusToken";
        case minusToken:
            return "minus";
        case doppelpunkt:
            return "doppelpunkt";
        case stern:
            return "stern";
        case kleiner:
            return "kleiner";
        case groesser:
            return "groesser";
        case gleich:
            return "gleich";
//	case 14: cout<<"gleichGleich";break; // SS14
        case doppeltpunktGleich:
            return "doppelpunktGleich"; // WS14
        case ungleich:
            return "ungleich";
        case ausrufezeichen:
            return "ausrufezeichen";
        case undund:
            return "undund";
        case semikolon:
            return "semikolon";
        case rundeKlammerAuf:
            return "rundeklammerauf";
        case rundeKlammerZu:
            return "rundeklammerzu";
        case geschweifteKlammerAuf:
            return "geschweifteklammerauf";
        case geschweifteKlammerZu:
            return "geschweifteklammerzu";
        case eckigeKlammerAuf:
            return "eckigeklammerauf";
        case eckigeKlammerZu:
            return "eckigeklammerzu";
        case error:
            return "error";
        case ELSE:
            return "else";
//	case 27: cout<<"print";break; // SS14
        case writeToken:
            return "write"; // WS14
        case readToken:
            return "read";
        case intToken:
            return "int-Token";
        default:
            return "";
    }
}

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

