// lab1-1-main.cpp

#include <iostream>
//#include "lab1-1.h"

namespace Complex {
	typedef struct {
		double real;
		double image;
	} Cplex;
	
	const double pi = 3.1416;
	void showComplex(const Cplex &m);
	
	void showComplex(const Cplex &m) {
		std::cout << m.real;
		if (m.image < 0)
			std::cout << m.image << "i" << std::endl;
		else
			std::cout << "+" << m.image << "i" << std::endl;
	}
}

using namespace Complex;

int main() {
	Cplex n;
	n.real = 1 * pi;
	n.image = -0.5;
	showComplex(n);
	return 0;
}
