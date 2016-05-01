// lab7-1-1.cpp
#include <iostream>
using std::cout;
using std::endl;

int sum(int *array, int len) {
	int n = 0;
	for (int i=0; i<len; i++)
		n += array[i];
	return n;
}
double sum(double *array, int len) {
	double n = 0.0;
	for (int i=0; i<len; i++)
		n += array[i];
	return n;
}

int main() {
	int array1[5] = {1,2,3,4,5};
	cout << "sum(array1) = " << sum(array1,5) << endl;
	double array2[5] = {1.1,2.2,3.3,4.4,5.5};
	cout << "sum(array2) = " << sum(array2,5) << endl;
	return 0;
}
