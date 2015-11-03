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
	plus,
	minus,
	slash,
	stern,
	kleiner,
	groesser,
	gleich,
//	gleichGleich, // SS14
	doppeltpunktGleich, // WS14
	ungleich,
	ausrufezeichen,
	und,
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


#endif /* TTYPE_H_ */
