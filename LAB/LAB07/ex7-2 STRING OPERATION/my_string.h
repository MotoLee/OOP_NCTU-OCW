// my_string.h
#include <iostream>
#include <string.h>
using namespace std;

class myString {
	private:
		
	public:
		char *p;
		myString();
		myString(const char *s);
		myString(const myString &s);
		~myString() {
			if(p) {
				delete [] p;
				p = NULL;
			}
		}
		friend ostream& operator<< (ostream &out, const myString &s);
		friend myString operator+ (const myString &s, const char* t);
		friend myString operator+ (const char* t, const myString &s);
		friend myString operator+ (const myString &s, const myString &t);
		bool operator<= (const myString &s);

};
/*
 definition of class string.
*/

