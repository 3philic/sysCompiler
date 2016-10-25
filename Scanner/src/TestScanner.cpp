#include "Scanner.h"
#include <stdio.h>

void printTType(TType a) {
    switch (a) {
        case null:
            cout << "0";
            break;
        case integer:
            cout << "integer";
            break;
        case identifier:
            cout << "identifier";
            break;
        case lexem:
            cout << "lexem";
            break;
        case IF:
            cout << "if";
            break;
        case WHILE:
            cout << "while";
            break;
        case kommentar:
            cout << "kommentar";
            break;
        case plusToken:
            cout << "plusToken";
            break;
        case minusToken:
            cout << "minus";
            break;
        case doppelpunkt:
            cout << "doppelpunkt";
            break;
        case stern:
            cout << "stern";
            break;
        case kleiner:
            cout << "kleiner";
            break;
        case groesser:
            cout << "groesser";
            break;
        case gleich:
            cout << "gleich";
            break;
//	case 14: cout<<"gleichGleich";break; // SS14
        case doppeltpunktGleich:
            cout << "doppelpunktGleich";
            break; // WS14
        case ungleich:
            cout << "ungleich";
            break;
        case ausrufezeichen:
            cout << "ausrufezeichen";
            break;
        case undund:
            cout << "undund";
            break;
        case semikolon:
            cout << "semikolon";
            break;
        case rundeKlammerAuf:
            cout << "rundeklammerauf";
            break;
        case rundeKlammerZu:
            cout << "rundeklammerzu";
            break;
        case geschweifteKlammerAuf:
            cout << "geschweifteklammerauf";
            break;
        case geschweifteKlammerZu:
            cout << "geschweifteklammerzu";
            break;
        case eckigeKlammerAuf:
            cout << "eckigeklammerauf";
            break;
        case eckigeKlammerZu:
            cout << "eckigeklammerzu";
            break;
        case error:
            cout << "error";
            break;
        case ELSE:
            cout << "else";
            break;
//	case 27: cout<<"print";break; // SS14
        case writeToken:
            cout << "write";
            break; // WS14
        case readToken:
            cout << "read";
            break;
        case intToken:
            cout << "int-Token";
            break;
        default:
            cout << "";
            break;

    }
}

int main(int argc, char **argv) {

    Scanner *scanner;

    scanner = new Scanner(argv[1]);

    while (true) {
        Token token = scanner->nextToken();

        // Abbruchbedingung	(Lexem:# ist das Abbruchzeichen des Automaten)
        if (token.lexem.equals(*new String('#'))) {
            cout << "EOF";
            break;
        }

        // print-out
        // format: tokenType :: tokenLexem
        printTType(token.type);
        cout << " :: " << token.lexem;

        // check if there's a an (int)-value associated with the token and if so print it
        // format:  :: tokenValue
        if (token.value) {
            cout << " :: " << *(token.value);
        }

        // print out line/column
        // format: (line:#ln column:#clmn)
        cout << "\t" << "(line:" << token.lineNo << " column:" << token.columnNo << ")" << endl;
    }

}

