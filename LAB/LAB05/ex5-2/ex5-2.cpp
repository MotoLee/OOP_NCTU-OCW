// ex5-2.cpp
#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	int n;
	cout<<"Enter n for n x n matrix:"<<endl;
	cin>>n;
	Matrix A(n), B(n); // create two Matrix objects
	A.assignElements(); // assign elements in Matrix A randomly
	cout<<"A = ";
	A.printMatrix(); // output object A
	cout<<endl;
	B.assignElements(); // assign elements in Matrix B randomly
	cout<<"B = ";
	B.printMatrix(); // output object B
	cout<<endl;

	Matrix tA(A); // use copy constructor to build tA
	cout<<"tA=";
	tA.transposeMatrix(); // transpose Matrix tA
	tA.printMatrix(); // output object tA
	cout<<endl;
	Matrix tB(B); // use copy constructor to build tB
	cout<<"tB=";
	tB.transposeMatrix(); // transpose Matrix tB
	tB.printMatrix(); // output object tB
	cout<<endl;

	Matrix C;
	cout<<"A = ";
	A.printMatrix(); // output object A
	cout<<endl;
	cout<<"B = ";
	B.printMatrix(); // output object B
	cout<<endl;
	C.multiplyMatrix(A,B); // C = A * B
	cout<<"A*B = ";
	C.printMatrix(); // output object C
	cout<<endl;
	return 0;
}
