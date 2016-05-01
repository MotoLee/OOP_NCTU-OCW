// complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

/* Write class definition for Complex */
class Complex{
	private:
		double real;
		double image;		
	public:
		Complex();
		Complex(double r, double i);
		Complex(const Complex &c);
		void assign(double, double);
		void assignReal(double);
		void assignImage(double);
		void printComplex();
		Complex add(Complex);
		Complex subtract(Complex);
		Complex multiply(Complex);
		Complex division(Complex);
};

#endif
