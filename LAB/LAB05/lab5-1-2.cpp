// lab5-1-2.cpp
#include <iostream>

class Point2D {
	private:
		int x;
		int y;
		double value;
	public:
		Point2D(); // default constructor
		void assignPoint2D(int n1, int n2, double v);
		void displayPoint2D();
};

// constructor 1
Point2D::Point2D() {
	x = 0;
	y = 0;
	value = 0.0;
}
// constructor 2
//Point2D::Point2D() : x(0), y(0), value(0.0) {}

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
	for (int i=0; i<10; i++)
		ptArray[i].displayPoint2D();
	return 0;
}
