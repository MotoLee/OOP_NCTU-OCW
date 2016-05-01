// lab3-2-1.cpp
#include <iostream>
using namespace std;

int main() {
	int a = 1024;
	int &refa = a;
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
//	cout << "*a = " << *a << endl;
	cout << "refa = " << refa << endl;
	cout << "&refa = " << &refa << endl;
//	cout << "*refa = " << *refa << endl;
	return 0;
}
