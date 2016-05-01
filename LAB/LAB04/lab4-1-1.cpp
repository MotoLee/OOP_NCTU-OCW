// lab4-1-1.cpp
#include <iostream>
using namespace std;

int main() {
	double a = 1.34;
	const double *pa = &a; // a pointer to a constant
	cout << "*pa = " << *pa << endl;
	double b = 6.5;
	pa = &b; // a pointer to a constant can change the pointer
	cout << "*pa = " << *pa << endl;
//	*pa = 7.6; // cannot modify a pointer to a constant
	cout << "*pa = " << *pa << endl;
	return 0;
}
