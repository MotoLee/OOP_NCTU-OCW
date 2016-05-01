// ex1-1.cpp
#include "1-5.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
using namespace Complex;

int main(int argc, char *argv[]) {
	Cplex a, b; // use struct named Cplex under namespace Complex

	ReadTextFile(argv[1], a, b); // process text file
	Cplex results[4]; // store the results of diff.  operation

	results[0] = ComplexOperation(a, b, '+');
	results[1] = ComplexOperation(a, b, '-');
	results[2] = ComplexOperation(a, b, '*');
	results[3] = ComplexOperation(a, b, '/');

	PrintComplex(argv[2], results); // print the results on file.
	return 0;
}


void Complex::ReadTextFile (char * argv_1, Cplex & c1, Cplex & c2) {

	cout<<"argv[1] = "<<argv_1<<endl;

	// read file
	string line;
	ifstream myfile (argv_1);
	string input[2];

	if(myfile.is_open()) {		// successful
		//cout << "test...1..."<<endl;
		getline(myfile,input[0]);
		getline(myfile,input[1]);
		cout << "num1 = "<<input[0]<<endl;
		cout << "num2 = "<<input[1]<<endl;
		myfile.close();
	} else {
		cout<< "OPEN FILE ERROR!!"<< endl;
	}

	// Parsing two strings into doubles
	string num_1_r, num_1_i, num_2_r, num_2_i;
	int x, y;

	// find specific character
	string num_re[2], num_im[2];
	int operator_1, operator_2;

	for (int i=0; i<2; i++) {	// input[0], input[1]
		for(int j=1; j<input[i].length(); j++) {	// j start from 1 to avoid negative real part
			if ((input[i].at(j) == '+')||(input[i].at(j) == '-')) { 	// find + or -
				operator_1 = j;
			} else if (input[i].at(j) == 'i') {		// find i
				operator_2 = j;
			}
		}
		num_re[i] = input[i].substr(0,operator_1);
		if (input[i].at(operator_1) == '-') {
			num_im[i] = input[i].substr(operator_1, operator_2 - operator_1);
		} else if (input[i].at(operator_1) == '+') {
			num_im[i] = input[i].substr(operator_1+1, operator_2 - operator_1 - 1);
		}
		//cout << "test: " << num_re[i] << "," << num_im[i] << endl;
	}

	c1.real = stod(num_re[0]);
	c1.image = stod(num_im[0]);
	c2.real = stod(num_re[1]);
	c2.image = stod(num_im[1]);

	cout << "num1 = " << c1.real << ", " << c1.image << endl;
	cout << "num2 = " << c2.real << ", " << c2.image << endl;
}

Cplex Complex::ComplexOperation (Cplex &a, Cplex &b, char op) {
	Cplex r;
	if (op == '+') {
		r.real = a.real + b.real;
		r.image = a.image + b.image;
	} else if (op == '-') {
		r.real = a.real - b.real;
		r.image = a.image - b.image;
	} else if (op == '*') {
		r.real = (a.real * b.real) - (a.image * b.image);
		r.image = (a.image * b.real) + (a.real * b.image);
	} else if (op == '/') {
		r.real = ((a.real * b.real) + (a.image * b.image)) / ((b.real * b.real) + (b.image * b.image));
		r.image = ((a.image * b.real) - (a.real * b.image)) / ((b.real * b.real) + (b.image * b.image));
	} else {
		cout<<"error"<<endl;
	}
	return r;
}


void Complex::PrintComplex (char * argv_2, Cplex * results) {
	// write file
	ofstream myfile (argv_2);
	if (myfile.is_open()) {
		for (int i=0; i<4; i++) {
			if (results[i].image < 0) {
				myfile << setprecision(3) << results[i].real << "-" << results[i].image * (-1) << "i" << endl;
			} else {
				myfile << setprecision(3) << results[i].real << "+" << results[i].image << "i" << endl;
			}
		}
	} else {
		cout<< "WRITE FILE ERROR!!"<< endl;
	}

	cout << setprecision(3) << results[0].real << "," << results[0].image << endl;
	cout << setprecision(3) << results[1].real << "," << results[1].image << endl;
	cout << setprecision(3) << results[2].real << "," << results[2].image << endl;
	cout << setprecision(3) << results[3].real << "," << results[3].image << endl;
}

