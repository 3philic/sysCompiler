#include "Scanner.h"
#include <stdio.h>

void printTType(TType a){
	switch(a){
	case 0: cout<<"0";break;
	case 1: cout<<"integer";break;
	case 2: cout<<"identifier";break;
	case 3: cout<<"lexem";break;
	case 4: cout<<"if";break;
	case 5: cout<<"while";break;
	case 6: cout<<"kommentar";break;
	case 7: cout<<"plus";break;
	case 8: cout<<"minus";break;
	case 9: cout<<"slash";break;
	case 10: cout<<"stern";break;
	case 11: cout<<"kleiner";break;
	case 12: cout<<"groesser";break;
	case 13: cout<<"gleich";break;
//	case 14: cout<<"gleichGleich";break; // SS14
	case 14: cout<<"doppelpunktGleich";break; // WS14
	case 15: cout<<"ungleich";break;
	case 16: cout<<"ausrufezeichen";break;
	case 17: cout<<"und";break;
	case 18: cout<<"semikolon";break;
	case 19: cout<<"rundeklammerauf";break;
	case 20: cout<<"rundeklammerzu";break;
	case 21: cout<<"geschweifteklammerauf";break;
	case 22: cout<<"geschweifteklammerzu";break;
	case 23: cout<<"eckigeklammerauf";break;
	case 24: cout<<"eckigeklammerzu";break;
	case 25: cout<<"error";break;
	case 26: cout<<"else";break;
//	case 27: cout<<"print";break; // SS14
	case 27: cout<<"write";break; // WS14
	case 28: cout<<"read";break;
	case 29: cout<<"int-Token";break;
	default: cout<<"";break;

	}
}

int main(int argc, char **argv) {

	Scanner* scanner;

	scanner = new Scanner(argv[1]);

	while (true) {
		Token token = scanner->nextToken();

		// Abbruchbedingung	(Lexem:# ist das Abbruchzeichen des Automaten)
		if (token.lexem.equals (*new String ('#'))) {
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

