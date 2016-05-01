// lab5-1-3.cpp
#include <iostream>

class Point2D {
	private:
		int x;
		int y;
		double value;
	public:
		Point2D(); // default constructor
		Point2D(int n1, int n2);
		Point2D(int n1, int n2, double v);
		void assignPoint2D(int n1, int n2, double v);
		void displayPoint2D();
};

Point2D::Point2D() {
	x = 0;
	y = 0;
	value = 0.0;
}
Point2D::Point2D(int n1, int n2) {
	x = n1;
	y = n2;
	value = 0.0;
}
Point2D::Point2D(int n1, int n2, double v) {
	x = n1;
	y = n2;
	value = v;
}
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
	Point2D pt1;
	Point2D pt2(1,2);
	Point2D pt3(3,2,1.9);
	pt1.displayPoint2D();
	pt2.displayPoint2D();
	pt3.displayPoint2D();
	pt3.assignPoint2D(2,1,0.0);
	pt3.displayPoint2D();
	return 0;
}
