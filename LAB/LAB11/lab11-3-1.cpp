// lab11-3-1.cpp
#include <iostream>
using std::cout;
using std::endl;

/* abstract class Shape defined in lab11-3 */
class Shape {
	protected:
		int color;
	public:
		virtual void draw() = 0;	// pure virtual
		virtual bool is_closed() = 0;	// pure virtual
		virtual ~Shape() {
			cout << "Delete Shape" << endl;
		}
		void setColor(int c) {
			color = c;
		}
		int getColor() const {
			return color;
		}
};
/* general class Point2D defined in lab11-2 */
class Point2D {
	private:
		int *x;
		int *y;
	public:
		Point2D() {
			x = new int;
			y = new int;
			*x = 0;
			*y = 0;
			cout << "New X and Y" << endl;
		}
		Point2D(int a, int b) {
			x = new int;
			y = new int;
			*x = a;
			*y = b;
			cout << "New X and Y" << endl;
		}
		~Point2D() {
//			cout << "Before: Delete Point2D: " << x << ", " << y << endl;
			if(x != NULL) {
				delete x;
			}
			if(y != NULL) {
				delete y;
			}
			cout << "Delete Point2D" << endl;
		}
		void display() const {
			cout << *x << "," << *y;
		}
		void setPoint2D(int a, int b) {
			*x = a;
			*y = b;
			cout << "setPoint2D" << endl;
		}
		int getX() const {
			return *x;
		}
		int getY() const {
			return *y;
		}
};
class Circle: public Shape {
	private:
		Point2D center;
		double radius;
	public:
		// constructor of Circle.
		Circle(Point2D& pt, double r, int c) {
			center.setPoint2D(pt.getX(), pt.getY());
			Shape::setColor(c);
			radius = r;
		}
		void draw() {
			cout<<"Color: "<<Shape::getColor()<<endl;
			cout<<"Center: "<<center.getX()<<", "<<center.getY()<<endl;
			cout<<"Radius: "<<radius<<endl;
		}
		bool is_closed() {
			return true;
		}
		~Circle() {
			cout << "Delete Circle" <<endl;
		}
};
int main() {
	Point2D pt(3,4);
	cout<<"test 1"<<endl;
	Circle c(pt,5,255);
	cout<<"test 2"<<endl;
	c.draw();
	cout<<"test 3"<<endl;
	return 0;
}
