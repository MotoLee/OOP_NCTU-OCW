// lab12-1.cpp
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;
template <class T>
T* new1D(int n, T k) {
	T *vec = new T [n];
	for (int i=0; i<n; i++)
		vec[i] = k;
	return vec;
}
template <class T>
void delete1D(T *vec) {
	assert(vec != NULL);
	delete [] vec;
}
template <class T>
void display1D(T *vec, int n) {
	for (int i=0; i<n; i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main() {
	int *ivec = new1D<int>(10,1);
	display1D<int>(ivec,10);
	delete1D<int>(ivec);
	
	double *dvec = new1D<double>(10,3.2);
	display1D<double>(dvec,10);
	delete1D<double>(dvec);
	
	return 0;
}
