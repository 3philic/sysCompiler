/*
 * Automat.cpp
 *
 */

#include "Automat.h"

const int Automat::zustandUebergangTabelle[21][28] = {
		{1,1,2,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{2,101,2,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{3,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{4,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{5,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,26,122,120},
		{6,101,102,103,104,24,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,25,25,122,120},
		{7,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{8,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,22,120,119,121,24,24,122,120},
		{9,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,19,118,21,120,119,121,24,24,122,120},
		{10,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{11,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{12,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{13,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{14,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{15,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{16,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{17,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{0,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{18,101,102,103,104,105,106,20,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{27,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120},
		{23,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,120,118,21,120,119,121,24,24,122,120}


	};


Automat::Automat() {
	this->aktuellerZustand = 0;
//	this->zustandUebergangTabelle[0][0] = 0;


}

Automat::~Automat() {
	// TODO Auto-generated destruct
}

int Automat::transformChar(char c){// automatenlogic Todo: ereignisse bei endzuständen erstellen
	int eingabe;// im folgenden wird der c einem int-wert zugewiesen um in der tabelle abzufragen

	if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')eingabe = 0;
	else if(c=='A'||c=='a'||c=='B'||c=='b'||c=='C'||c=='c'||c=='D'||c=='d'||c=='E'||c=='e'||c=='F'||c=='f'||
			c=='G'||c=='g'||c=='H'||c=='h'||c=='I'||c=='i'||c=='J'||c=='j'||c=='K'||c=='k'||c=='L'||c=='l'||
			c=='M'||c=='m'||c=='N'||c=='n'||c=='O'||c=='o'||c=='P'||c=='p'||
			c=='Q'||c=='q'||c=='R'||c=='r'||c=='S'||c=='s'||c=='T'||c=='t'||c=='U'||c=='u'||c=='V'||c=='v'||c=='W'||c=='w'||
			c=='X'||c=='x'||c=='Y'||c=='y'||c=='Z'||c=='z')eingabe = 1;
	else if (c=='+')eingabe=2;
	else if (c=='-')eingabe=3;
	else if (c=='/')eingabe=4;
	else if (c=='*')eingabe=5;
	else if (c=='<')eingabe=6;
	else if (c=='>')eingabe=7;
	else if (c=='=')eingabe=8;
	else if (c=='!')eingabe=20;
	else if (c=='&')eingabe=9;
	else if (c==';')eingabe=10;
	else if (c=='(')eingabe=11;
	else if (c==')')eingabe=12;
	else if (c=='{')eingabe=13;
	else if (c=='}')eingabe=14;
	else if (c=='[')eingabe=15;
	else if (c==']')eingabe=16;
	else if (c==' ')eingabe=17;
	else if (c==':')eingabe=18;
	else eingabe=19;

	return eingabe;

}

TType Automat::checkChar (char c){

	Automat::aktuellerZustand = zustandUebergangTabelle[Automat::transformChar(c)][aktuellerZustand];
	//if(errorbool=false)
		switch(Automat::aktuellerZustand){
			case (101): aktuellerZustand=0; return integer;
			case (102): aktuellerZustand=0; return lexem;
			case (103): aktuellerZustand=0; return plus;
			case (104): aktuellerZustand=0; return minus;
			case (105): aktuellerZustand=0; return slash;
			case (106): aktuellerZustand=0; return stern;
			case (107): aktuellerZustand=0; return kleiner;
			case (108): aktuellerZustand=0; return groesser;
			case (109): aktuellerZustand=0; return gleich;
			case (118): aktuellerZustand=0; return doppeltpunktGleich;
			case (119): aktuellerZustand=0; return ungleich;
			case (121): aktuellerZustand=0; return ausrufezeichen;
			case (110): aktuellerZustand=0; return und;
			case (111): aktuellerZustand=0; return semikolon;
			case (112): aktuellerZustand=0; return rundeKlammerAuf;
			case (113): aktuellerZustand=0; return rundeKlammerZu;
			case (114): aktuellerZustand=0; return geschweifteKlammerAuf;
			case (115): aktuellerZustand=0; return geschweifteKlammerZu;
			case (116): aktuellerZustand=0; return eckigeKlammerAuf;
			case (117): aktuellerZustand=0; return eckigeKlammerZu;
			case (21) : return kleiner;
			case (120): aktuellerZustand=0; return error;
			case (122): aktuellerZustand=0; return kommentar;
			default: return null;
		}
	//else return error;
}
