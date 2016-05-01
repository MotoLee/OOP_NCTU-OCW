// lab1-1.cpp

//#include <iostream>
//#include "lab1-1.h"

namespace Complex {
	void showComplex(const Cplex &m) {
		std::cout << m.real;
		if (m.image < 0)
			std::cout << m.image << "i" << std::endl;
		else
			std::cout << "+" << m.image << "i" << std::endl;
	}
}
