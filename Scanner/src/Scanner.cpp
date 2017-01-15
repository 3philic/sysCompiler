/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Scanner.h"

Scanner::Scanner(char* argv) {
	charCache = 0;
	lineCache = 0;
	columnCache = 0;
	returned_from_automat = null;
	stringCache = new String();
	stop = false;

	automat = new Automat();
	buffer = new Buffer(argv);
	buffer->fillBuffer();
	symboltable = new Symboltable();
}

Scanner::~Scanner() {
	delete stringCache;
	delete automat;
	delete buffer;
	delete symboltable;
}

Token* Scanner::nextToken() {
	Token* tokenToReturn = 0;	//Token, das schließlich returned werden wird
	//cachen der neuen Positionsmarker
	updatePositionMarkers();
	// wenn noch ein (nichtleerer) Char im Char-Cache drin ist,
	// müssen wir den bei der Positions-Zählung mitbeachten (um einen zurücksetzen)
	if (!(charCache == '\n') && !(charCache == ' ') && !(charCache == 0)) {
		columnCache--;
	}

	while (stop == false) {
		/**
		 ** Phase 1 des Scanners: Normalbetrieb
		 **/

		/*
		 * 1. Cachen
		 */
		//holen des ersten Chars in den Char Zwischenspeicher
		if (returned_from_automat == null) {
			charCache = buffer->getChar();//Inhalt == '#', falls Buffer EOF erreicht hat

			if (charCache == '\n')
				charCache = ' ';

			if (charCache == '#') {
				stop = true;		//Stopzeichen '#':
				charCache = ' ';
			}	//falls Buffer EOF erreicht hatte im letzten Durchgang abbrechen
		}

		/*
		 * 2. prüfen ob der Automat etwas erkennt aus den bisher eingegebenen Chars
		 *
		 * wenn der Automat "null" zurückgibt, dann ist das Token noch nicht abgeschlossen
		 * und es müssen weitere Chars "gefüttert" werden
		 */
		TType returnedType;	//genutzt im Fall, dass der Automat ein Lexem erkannt hat:
							//Variable speichert return-Wert der Symboltabelle

		returned_from_automat = automat->checkChar(charCache);
		switch (returned_from_automat) {

		case null:
			if (charCache != ' ') {
				*stringCache += *new String(charCache);
			}
			else {
				// wir sind noch am Leerzeichen überspringen (der Anfang von einem Token wurde noch nicht gefunden
				// und daher aktualisieren wir beim überspringen stets die Positionsmarker
				updatePositionMarkers();
			}
			break;

		case integer:	//Zahl, also muss zusätzlich Wert gespeichert werden
			delete tokenToReturn;
			tokenToReturn = new Token(*stringCache, integer,
					stringCache->value(), lineCache, columnCache);
			delete stringCache;
			stringCache = new String();

			return tokenToReturn;
			break;

		case lexem: //Dieser Fall wird betreten, falls der Automat ein Lexem oder
			//sonstiges Zeichen erkannt hat. Im folgenden wird nach einem evtl bereits
			//bereits vorhandenem Token in der Symboltabelle gesucht
			//oder eins selbst erstellt
			returnedType = symboltable->getTokenType(*stringCache);

			//weiterhin zu beachten: der String-Cache beinhaltet nun das Lexem des zu erstellenden Tokens
			//es wird jetzt der TType und die vorhandene TokenInformation aufgelöst (in dem Fall, dass ein Token
			//mit dem Lexem bereits in der Symboltabelle stand)..
			if (returnedType != null) {
				delete tokenToReturn;
				tokenToReturn = new Token(*stringCache, returnedType, lineCache,
						columnCache);

				TokenInformation *tokenInformation = symboltable->getTokenInformation(*stringCache);
				tokenToReturn->setInformation(tokenInformation);

				delete stringCache;
				stringCache = new String();

				return tokenToReturn;
			}

			//bzw. ein Token vom Typ "identifier" mit neuer TokenInformation in der Symboltabelle angelegt
			//(in dem Fall, dass kein Eintrag in der Symboltabelle vorhanden war)
			else {
				delete tokenToReturn;
				tokenToReturn = new Token(*stringCache, identifier, lineCache,
						columnCache);
				tokenToReturn->setInformation(new TokenInformation());

				delete stringCache;
				stringCache = new String();

				symboltable->insertToken(tokenToReturn);

				return tokenToReturn;
			}
			break;

		case kommentar:	//Kommentar wird komplett verworfen und die Suche nach einem Token läuft unbehindert weiter
			delete stringCache;
			stringCache = new String();

			updatePositionMarkers();
			break;

		case error:	//unbekannte Tokens werden komplett verworfen und eine Fehlermeldung auf "stderr" ausgegeben
			*stringCache += *new String(charCache);
			cerr << "unknown Token Line: " << lineCache << " Column: "
					<< columnCache << " Symbol: " << *stringCache << endl;

			delete tokenToReturn;
			tokenToReturn = new Token(*stringCache, error, lineCache, columnCache);

			delete stringCache;
			stringCache = new String();

			returned_from_automat = automat->checkChar(' '); // Dem Automat wird Tokenabbruch signalisiert
			return tokenToReturn;
			break;

		default:
			delete tokenToReturn;
			tokenToReturn = new Token(*new String(), returned_from_automat,
					lineCache, columnCache);
			delete stringCache;
			stringCache = new String();

			return tokenToReturn;
			break;
		}
	}

	/*
	 * In der gerade durchlaufenen Schleife werden sämtliche reguläre Tokens abgehandelt
	 * Es folgt Code für den Fall, dass die Datei komplett ausgelesen ist und ein
	 * "Stop-Token" returned wird
	 */

	returned_from_automat = automat->checkChar(' ');
	return new Token("#", null);
}

// setzt die Positionsmarker auf den aktuellen Wert (den der Buffer angibt)
void Scanner::updatePositionMarkers() {
	lineCache = buffer->getLineNo();
	columnCache = buffer->getColumnNo();
}
