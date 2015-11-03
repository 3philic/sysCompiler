#include <iostream>

#include "HashMap.h"
#include "../../Token.h"

using namespace std;

int main(int argc, char **argv) {

	Token* l = new Token("if", IF);

	HashMap* hashmap;

	hashmap = new HashMap(10);


	hashmap->insertToken(l);

	TType type = hashmap->getTokenType("if");
	cout <<type<<endl;

	cout << "Testausgabe des HashMap-Tests\n";
}
