// lab3-1-1.cpp
#include <iostream>
using namespace std;

int main() {
	double a = 1.34;
	double *pa = &a;
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
//	cout << "*a = " << *a << endl;
	cout << "pa = " << pa << endl;
	cout << "&pa = " << &pa << endl;
	cout << "*pa = " << *pa << endl;
	*pa = 6.5;
	cout << "a = " << a << endl;
	cout << "*pa = " << *pa << endl;
	return 0;
}
