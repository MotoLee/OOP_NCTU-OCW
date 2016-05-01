// lab9-1-2.cpp
/* The Point2D and Point4D class defined in lab9-1-1 */
#include <iostream>
using std::cout;
using std::endl;

class Point2D {
	private:
		int x;
		int y;
	public:
		Point2D(int n1 = 0, int n2 = 0):x(n1), y(n2) {}
		void display() const;
};
void Point2D::display() const {
	cout << x << "," << y;
}
class Point4D : public Point2D {
	private:
		int z;
		int t;
	public:
		Point4D(int n1 =0,int n2 = 0,int n3 = 0,int n4 = 0) : Point2D(n1,n2),z(n3),t(n4) {}
		void display() const;
};
void Point4D::display() const {
	Point2D::display();
	cout << "," << z << "," << t;
}

int main() {
	Point2D pt2(3,4);
	Point4D pt4(1,2,3,4);
	pt4.display();
	cout << endl;
	pt2 = pt4; // OK, every Point2D is a Point4D
	pt2.display();
	cout << endl;
	pt4 = pt2; // Error, not every Ponint4D is a Point2D
	pt4.display();
	cout << endl;
	return 0;
}
