// lab3-1-2.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

int main() {
	int a[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		a[i] = rand()%20 + 10;
	int *pa = a;
	for (int i = 0; i < 10; i++)
		cout << *(pa++) << " ";
	cout << endl;
	return 0;
}
