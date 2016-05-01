// lab4-1-3.cpp
#include <iostream>
using namespace std;

int main() {
	double a = 1.34;
	const double* const pa = &a; // a const pointer to a constant
	cout << "*pa = " << *pa << endl;
	double b = 6.5;
//	pa = &b; // a constant pointer to constant cannot be changed
	cout << "*pa = " << *pa << endl;
//	*pa = 7.6; // a constant pointer to constant cannot be modified
	cout << "*pa = " << *pa << endl;
	return 0;
}
