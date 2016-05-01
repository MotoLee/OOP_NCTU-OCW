// lab4-1-2.cpp
#include <iostream>
using namespace std;

int main() {
	double a = 1.34;
	double* const pa = &a; // a const pointer to a double
	cout << "*pa = " << *pa << endl;
	double b = 6.5;
//	pa = &b; // a constant pointer cannot be changed
	cout << "*pa = " << *pa << endl;
	*pa = 7.6; // a constant pointer can be modified
	cout << "*pa = " << *pa << endl;
	return 0;
}
