#ifndef STRING_H_
#define STRING_H_

#include <iostream>
#include <cstdlib>	/* strtol */
using namespace std;

class String {
private:
	// 'String' is represented internally as a plain C-style string.
	int size;
	char* str;
public:
	String();
	String(char c);
	String(const char *);
	String(const String&);
	~String();

	char& operator[](int index);
	String& operator=(String&);
	String& operator+=(String&);

	// make friend, so we can access private members
	friend ostream& operator<<(ostream &out, String &s);

	bool equals(String s);
	int hashCode();
	long value();

};

#endif /* STRING_H_ */
