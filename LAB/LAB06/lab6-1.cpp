// lab6-1.cpp
#include <iostream>
class Point2D {
	private:
		int x;
		int y;
		static const double limit;
		static double value; // indicates that all object¡¦s value are the same
	public:
		Point2D();
		void assignPoint2D(int x, int y);
		void displayPoint2D();
		static void setValue(double v); // only static member function can access static member
};

Point2D::Point2D() {
	x = 0;
	y = 0;
}
void Point2D::assignPoint2D(int n1, int n2) {
	x = n1;
	y = n2;
}
void Point2D::displayPoint2D() {
	std::cout << "(" << x << "," << y << ") = ";
	std::cout << value << std::endl;
}
void Point2D::setValue(double v) {
	if (v < limit)
		value = v;
	else
		value = limit;
}
double Point2D::value = 0.0; // It needs to initialize static member
const double Point2D::limit = 10.0;

int main() {
	Point2D ptArray[10];
//	ptArray[0].setValue(1.1); // modify the static member by static member fuction
	ptArray[0].setValue(30.1); // modify the static member by static member fuction
	for (int i=0; i<10; i++) {
		ptArray[i].assignPoint2D(i,i+2);
		ptArray[i].displayPoint2D();
	}
	return 0;
}
