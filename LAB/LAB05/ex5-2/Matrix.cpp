// Matrix.cpp
#include <iostream>
#include <ctime>
#include <cmath>
#include "Matrix.h"
#include <cassert>
#include <stdlib.h>
using namespace std;

// Member-function definitions for class Matrix.
Matrix::Matrix(){
	dim = 3;
	element = new int*[dim];
	for(int i=0; i<dim; i++) {
		element[i] = new int[dim];
		for (int j=0; j<dim; j++) element[i][j] = 0;
	}
}
Matrix::Matrix(int n) {
	dim = n;
	element = new int*[dim];
	for(int i=0; i<dim; i++) {
		element[i] = new int[dim];
	}
}
Matrix::Matrix(const Matrix &m) {
	dim = m.dim;
	element = new int*[dim];
	for(int i=0; i<dim; i++) {
		element[i] = new int[dim];
	}
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			element[i][j] = m.element[i][j];
		}
	}
}
void Matrix::assignElements() {
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			element[i][j] = rand()%10+1;
		}
	}
}
void Matrix::printMatrix() {
	cout<<endl;
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			cout<<element[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Matrix::transposeMatrix() {
	for(int i=0; i<dim; i++) {
		for(int j=i+1; j<dim; j++) {
			int tmp = element[i][j];
			element[i][j] = element[j][i];
			element[j][i] = tmp;
		}
	}
}
void Matrix::multiplyMatrix(const Matrix &a, const Matrix &b) {
	assert(a.dim == b.dim);
	dim = a.dim;
	element = new int*[dim];
	for(int i=0; i<dim; i++) {
		element[i] = new int[dim];
		for(int j=0; j<dim; j++) {
            element[i][j] = 0;
			for(int k=0; k<dim; k++) {
				element[i][j] += a.element[i][k] * b.element[k][j];
			}
		}
	}
}
Matrix::~Matrix(){
	for(int i=0; i<dim; i++) delete []element[i];
	delete []element;
}
