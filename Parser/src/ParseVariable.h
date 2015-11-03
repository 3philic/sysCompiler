/*
 * ParseVariable.h
 *
 *  Created on: 07.12.2014
 *      Author: jones
 */

#ifndef PARSEVARIABLE_H_
#define PARSEVARIABLE_H_

struct parseTreeObjectResponse {
	bool tokenConsumed;
	ParseTreeObject* nextResponder;	// sagt dem Parser das nächste ParseObjekt an
	bool error;
};

class ParseVariable: public ParseTreeObject {
public:
	ParseVariable();
	virtual ~ParseVariable();

	parseTreeObjectResponse insertToken();
private:
	ParseVariable* parent;
	LinkedList* childVariables;
};

#endif /* PARSEVARIABLE_H_ */
