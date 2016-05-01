// lab4-2-1.cpp
#include <iostream>

class Point2D {
	
		int x;
		int y;
		double value;
	public:
		void assignPoint2D(int n1, int n2, double v); // Declaration
		void displayPoint2D();	// Declaration
};

// Definition
void Point2D::assignPoint2D(int n1, int n2, double v) {
	x = n1;
	y = n2;
	value = v;
}
void Point2D::displayPoint2D() {
	std::cout << "(" << x << "," << y << ") = ";
	std::cout << value << std::endl;
}

int main() {
	Point2D ptArray[10];
	for (int i=0; i<10; i++) {
		ptArray[i].assignPoint2D(i,i+2,i*10);
		ptArray[i].displayPoint2D();
	}
	return 0;
}
