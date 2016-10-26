#include "Scanner.h"
#include <stdio.h>
#include <time.h>
using namespace std;


char* TTypeToString(TType a) {
    switch (a) {
        case null:
            return "0";
            break;
        case integer:
            return "integer";
            break;
        case identifier:
            return "identifier";
            break;
        case lexem:
            return "lexem";
            break;
        case IF:
            return "if";
            break;
        case WHILE:
            return "while";
            break;
        case kommentar:
            return "kommentar";
            break;
        case plusToken:
            return "plusToken";
            break;
        case minusToken:
            return "minus";
            break;
        case doppelpunkt:
            return "doppelpunkt";
            break;
        case stern:
            return "stern";
            break;
        case kleiner:
            return "kleiner";
            break;
        case groesser:
            return "groesser";
            break;
        case gleich:
            return "gleich";
            break;
//	case 14: cout<<"gleichGleich";break; // SS14
        case doppeltpunktGleich:
            return "doppelpunktGleich";
            break; // WS14
        case ungleich:
            return "ungleich";
            break;
        case ausrufezeichen:
            return "ausrufezeichen";
            break;
        case undund:
            return "undund";
            break;
        case semikolon:
            return "semikolon";
            break;
        case rundeKlammerAuf:
            return "rundeklammerauf";
            break;
        case rundeKlammerZu:
            return "rundeklammerzu";
            break;
        case geschweifteKlammerAuf:
            return "geschweifteklammerauf";
            break;
        case geschweifteKlammerZu:
            return "geschweifteklammerzu";
            break;
        case eckigeKlammerAuf:
            return "eckigeklammerauf";
            break;
        case eckigeKlammerZu:
            return "eckigeklammerzu";
            break;
        case error:
            return "error";
            break;
        case ELSE:
            return "else";
            break;
//	case 27: cout<<"print";break; // SS14
        case writeToken:
            return "write";
            break; // WS14
        case readToken:
            return "read";
            break;
        case intToken:
            return "int-Token";
            break;
        default:
            return "";
            break;

    }
}

int main(int argc, char **argv) {

    Scanner *scanner;
    scanner = new Scanner(argv[1]);

    time_t start,end;
    time (&start);

    ofstream outfile;
    outfile.open("output.txt");

    while (true) {
        Token token = scanner->nextToken();

        // Abbruchbedingung	(Lexem:# ist das Abbruchzeichen des Automaten)
        if (token.lexem.equals(*new String('#'))) {
            outfile << "EOF";
            break;
        }

        // print-out
        outfile << "Token " << TTypeToString(token.type);
        outfile << "\tLine: " << token.lineNo << " Column: " << token.columnNo;
        if (token.type == lexem) {
            outfile << "\tLexem: " << token.lexem;
        }
        if (token.type == integer) {
            outfile << "\tValue: " << *(token.value);
        }
        outfile << endl;
    }
    outfile.close();

    time(&end);
    double dif = difftime (end,start);
    printf ("Elapsed time is %.2lf seconds.", dif );


}

