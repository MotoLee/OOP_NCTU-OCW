#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T, class U>
T tripleVal(U val) {
	T tmp = val*3;
	return tmp;
}

int main() {
	int a=4;
	double b=8.8;
	cout << tripleVal<int>(a) << "\n";
	cout << tripleVal<int>(b) << "\n";
	cout << tripleVal<int,double>(b) << "\n";
	cout << tripleVal<int, int>(b) << "\n";

	system("pause");
	return 0;
}
