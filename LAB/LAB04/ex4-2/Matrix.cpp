// Matrix.cpp
#include <iostream>
#include <ctime>
#include <cmath>
#include "Matrix.h"
using namespace std;

// Member-function definitions for class Matrix.
void Matrix::assignDimension(int n) {
	dim = n;
	element = new int*[dim];
	for(int i=0; i<dim; i++) {
		element[i] = new int[dim];
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
void Matrix::assignMatrix(Matrix m) {
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
void Matrix::transposeMatrix() {
	for(int i=0; i<dim; i++) {
		for(int j=i+1; j<dim; j++) {
			int tmp = element[i][j];
			element[i][j] = element[j][i];
			element[j][i] = tmp;
		}
	}
}
Matrix Matrix::addMatrix(Matrix m) {
	Matrix tmp;
	tmp.dim = dim;
	tmp.element = new int*[dim];
	for(int i=0; i<dim; i++) {
		tmp.element[i] = new int[dim];
		for(int j=0; j<dim; j++) {
			tmp.element[i][j] = element[i][j] + m.element[i][j];
		}
	}
	return tmp;
}
Matrix Matrix::subtractMatrix(Matrix m) {
	Matrix tmp;
	tmp.dim = dim;
	tmp.element = new int*[dim];
	for(int i=0; i<dim; i++) {
		tmp.element[i] = new int[dim];
		for(int j=0; j<dim; j++) {
			tmp.element[i][j] = element[i][j] - m.element[i][j];
		}
	}
	return tmp;
}
Matrix Matrix::multiplyMatrix(Matrix m) {
	Matrix tmp;
	tmp.dim = dim;
	tmp.element = new int*[dim];
	for(int i=0; i<dim; i++) {
		tmp.element[i] = new int[dim];
		for(int j=0; j<dim; j++) {
			for(int k=0; k<dim; k++) {
				tmp.element[i][j] += element[i][k] * m.element[k][j];
			}
		}
	}
	return tmp;
}
Matrix::~Matrix(){
	for(int i=0; i<dim; i++) delete []element[i];
	delete []element;
}
