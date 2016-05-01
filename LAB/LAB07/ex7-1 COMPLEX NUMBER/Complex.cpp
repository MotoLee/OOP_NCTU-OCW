// complex.cpp
#include <iostream>
#include <iomanip>
#include "Complex.h"
using namespace std;

// Member-function definitions for class Complex.
Complex::Complex() {
	real = 0;
	image = 0;
}
Complex::Complex(double r, double i) {
	real = r;
	image = i;
}
//Complex::Complex(const Complex &c) {
//	real = c.real;
//	image = c.image;
//}

void Complex::assign(double r, double i) {
	real = r;
	image = i;
}
void Complex::assignReal(double r) {
	real = r;
}
void Complex::assignImage(double i) {
	image = i;
}
Complex Complex::add(Complex c) {
	Complex tmp;
	tmp.real = real + c.real;
	tmp.image = image + c.image;
	return tmp;
}
Complex Complex::subtract(Complex c) {
	Complex tmp;
	tmp.real = real - c.real;
	tmp.image = image - c.image;
	return tmp;
}
Complex Complex::multiply(Complex c) {
	Complex tmp;
	tmp.real = real * c.real - image * c.image;
	tmp.image = image * c.real + real * c.image;
	return tmp;
}
Complex Complex::division(Complex c) {
	Complex tmp;
	tmp.real = ( real * c.real + image * c.image ) / (c.real * c.real + c.image * c.image);
	tmp.image = ( image * c.real - real * c.image ) / (c.real * c.real + c.image * c.image);
	return tmp;
}
Complex Complex::operator+(Complex &b) {
	return Complex(real + b.real, image + b.image);
}
Complex Complex::operator-(Complex &b) {
	return Complex(real - b.real, image - b.image);
}
Complex Complex::operator-() {
	return Complex(-real, -image);
}
Complex Complex::operator*(Complex &b) {
	return Complex((real * b.real - image * b.image), (image * b.real + real * b.image));
}
Complex Complex::operator/(Complex &b) {
	return Complex(( real * b.real + image * b.image ) / (b.real * b.real + b.image * b.image), 
	( image * b.real - real * b.image ) / (b.real * b.real + b.image * b.image));
}
Complex Complex::setComplexNumber(double r, double i){
	real = r;
	image = i;
}

void printComplex(const Complex &c) {
	cout<<std::setprecision(2)<<"("<<c.real<<", "<<c.image<<")";
}
void printMeg(const Complex &a, const Complex &b, char op) {
	printComplex(a);
	cout<<" "<<op<<" ";
	printComplex(b);
	cout<<" = ";
}


