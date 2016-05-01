// lab7-2.cpp
#include <iostream>
class Point2D {
	private:
		int x;
		int y;
		double value;
	public:
		Point2D();
		Point2D(int n1, int n2);
		Point2D(int n1, int n2, double v);
		void assignPoint2D(int n1, int n2);
		void assignPoint2D(int n1, int n2, double v);
		void displayPoint2D() const;
};

Point2D::Point2D() {
	x = 0;
	y = 0;
	value = 0;
}
Point2D::Point2D(int n1, int n2) {
	assignPoint2D(n1,n2,0.0);
}
Point2D::Point2D(int n1, int n2, double v) {
	assignPoint2D(n1,n2,v);
}
void Point2D::assignPoint2D(int n1, int n2) {
	assignPoint2D(n1,n2,value);
}
void Point2D::assignPoint2D(int n1, int n2, double v) {
	x = n1;
	y = n2;
	value = v;
}
void Point2D::displayPoint2D() const {
	std::cout << "(" << x << "," << y << ") = ";
	std::cout << value << std::endl;
}
int main() {
	Point2D pt1(3,4,3.9);
	Point2D pt2;
	pt1.displayPoint2D();
	pt2.displayPoint2D();
	std::cout << "after assignment " << std::endl;
	pt1.assignPoint2D(1,3);
	pt2.assignPoint2D(2,3,1.1);
	pt1.displayPoint2D();
	pt2.displayPoint2D();
	return 0;
}
