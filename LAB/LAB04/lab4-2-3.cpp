// lab4-2-3.cpp
#include <iostream>
using namespace std;

class Point2D {
	private:
		int x;
		int y;
		double value;
	public:
		void setCoord(int n1, int n2);	// mutator
		void setValue(double v);		// mutator
		int getCoordX();		// accessor
		int getCoordY();		// accessor
		double getValue();		// accessor
		void assignPoint2D(int n1, int n2, double v);	// mutator
		void displayPoint2D();
};

// Please implement the definitions of five additional member functions.
void Point2D::setCoord(int n1, int n2) {
	x = n1;
	y = n2;
}
void Point2D::setValue(double v) {
	value = v;
}
int Point2D::getCoordX() {
	return x;
}
int Point2D::getCoordY() {
	return y;
}
double Point2D::getValue() {
	return value;
}
void Point2D::assignPoint2D(int n1, int n2, double v) {
	x = n1;
	y = n2;
	value = v;
}
void Point2D::displayPoint2D() {
	cout<<"("<<x<<","<<y<<") = "<<value<<endl;
}

int main() {
	Point2D a;
	a.setCoord(1,3);
	cout<<"a(x,y) = "<<a.getCoordX()<<" "<< a.getCoordY()<<endl;
	return 0;	
}
