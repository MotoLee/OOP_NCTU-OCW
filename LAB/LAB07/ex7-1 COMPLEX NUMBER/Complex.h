// complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

/* Write class definition for Complex */
class Complex {
	private:
		double real;
		double image;
	public:
		Complex();
		Complex(double r, double i);
//		Complex(const Complex &c);		// Copy constructor is generated automatically
		void assign(double, double);
		void assignReal(double);
		void assignImage(double);
		Complex add(Complex);
		Complex subtract(Complex);
		Complex multiply(Complex);
		Complex division(Complex);
		Complex setComplexNumber(double r, double i);
		// override operator		
		Complex operator+(Complex &b);
		Complex operator-(Complex &b);
		Complex operator-();
		Complex operator*(Complex &b);
		Complex operator/(Complex &b);

		friend void printComplex(const Complex &c);
		friend void printMeg(const Complex &a, const Complex &b, char op);
};

#endif
