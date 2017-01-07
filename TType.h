/*
 * TType.h
 *
 *  Created on: Apr 6, 2014
 *      Author: 3philic
 */

#ifndef TTYPE_H_
#define TTYPE_H_

enum TType {
	null,
	integer,
	identifier,
	lexem,
	IF,
	WHILE,
	kommentar,
	plusToken,
	minusToken,
	//slash,
    doppelpunkt,
	stern,
	kleiner,
	groesser,
	gleich,
//	gleichGleich, // SS14
	doppeltpunktGleich, // WS14
	ungleich,
	ausrufezeichen,
	//und,
    undund,
	semikolon,
	rundeKlammerAuf,
	rundeKlammerZu,
	geschweifteKlammerAuf,
	geschweifteKlammerZu,
	eckigeKlammerAuf,
	eckigeKlammerZu,
	error,
	ELSE,
//	printToken,	// SS14
	writeToken, // WS14
	readToken,
	intToken,


};

static const char* TTypeToString(TType a) {
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

#endif /* TTYPE_H_ */
