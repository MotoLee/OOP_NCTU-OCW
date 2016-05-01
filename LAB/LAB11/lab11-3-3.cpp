// lab11-3-3.cpp
#include <iostream>
using std::cout;
using std::endl;

/* abstract class Shape defined in lab11-3 */
class Shape {
	protected:
		int color;
	public:
		virtual void draw() = 0;	// pure virtual
		virtual ~Shape() {}
		void setColor(int c) {
			color = c;
		}
		int getColor() const {
			return color;
		}
		virtual double area() = 0;
};
/* general class Point2D defined in lab11-2 */
class Point2D {
	private:
		int *x;
		int *y;
	public:
		Point2D() {
			x = new int (0);
			y = new int (0);
//			cout << "New X and Y" << endl;
		}
		Point2D(int a, int b) {
			x = new int (a);
			y = new int (b);
//			cout << "New X and Y" << endl;
		}
		~Point2D() {
			delete x;
			delete y;
//			cout << "Delete X and Y" << endl;
		}
		void display() const {
			cout << *x << "," << *y;
		}
		void setPoint2D(int a, int b) {
			*x = a;
			*y = b;
//			cout << "setPoint2D" << endl;
		}
		int getX() const {
			return *x;
		}
		int getY() const {
			return *y;
		}
};
// Triangle
class Triangle: public Shape {
	private:
		Point2D *vertices;
	public:
		Triangle(Point2D* vec) {
			vertices = new Point2D[3];
			vertices[0].setPoint2D(vec[0].getX(),vec[0].getY());
			vertices[1].setPoint2D(vec[1].getX(), vec[1].getY());
			vertices[2].setPoint2D(vec[2].getX(), vec[2].getY());
		}
		Triangle(Point2D* vec, int c) {
			vertices = new Point2D[3];
			vertices[0].setPoint2D(vec[0].getX(),vec[0].getY());
			vertices[1].setPoint2D(vec[1].getX(), vec[1].getY());
			vertices[2].setPoint2D(vec[2].getX(), vec[2].getY());
			Shape::setColor(c);
		}
		~Triangle() {
			delete [] vertices;
		}
		void draw() {
			cout<<"Color:  "<<Shape::getColor()<<endl;
			cout<<"Vertices: "<<endl;
			cout<<vertices[0].getX()<<", "<<vertices[0].getY()<<endl;
			cout<<vertices[1].getX()<<", "<<vertices[1].getY()<<endl;
			cout<<vertices[2].getX()<<", "<<vertices[2].getY()<<endl;
		};
		double area(){
			double s = 0;
			for (int i=0; i<3; i++){
				s += vertices[i].getX() * vertices[(i+1)%3].getY() - vertices[i].getY() * vertices[(i+1)%3].getX();
			}
			s = (s<0) ? -s : s;
			return (s/2);
		}
};
// Circle
class Circle: public Shape {
	private:
		Point2D center;
		double radius;
	public:
		Circle(Point2D& c, double r) {
			int x = c.getX();
			int y = c.getY();
			center.setPoint2D(x,y);
			radius = r;
		}
		~Circle() {
		}
		void draw() {
			cout<<"Color:  "<<Shape::getColor()<<endl;
			cout<<"Center: "<<endl;
			cout<<center.getX()<<", "<<center.getY()<<endl;
			cout<<"Radius: "<<radius<<endl;
		};
		double area(){
			return 3.14 * radius * radius;
		}		
};
// Rectangle
class Rectangle: public Shape {
	private:
		Point2D *vertices;
	public:
		Rectangle(Point2D* vec) {
			vertices = new Point2D[4];
			vertices[0].setPoint2D(vec[0].getX(),vec[0].getY());
			vertices[1].setPoint2D(vec[1].getX(), vec[1].getY());
			vertices[2].setPoint2D(vec[2].getX(), vec[2].getY());
			vertices[3].setPoint2D(vec[3].getX(), vec[3].getY());
		}
		Rectangle(Point2D* vec, int c) {
			vertices = new Point2D[4];
			vertices[0].setPoint2D(vec[0].getX(),vec[0].getY());
			vertices[1].setPoint2D(vec[1].getX(), vec[1].getY());
			vertices[2].setPoint2D(vec[2].getX(), vec[2].getY());
			vertices[3].setPoint2D(vec[3].getX(), vec[3].getY());
			Shape::setColor(c);
		}
		~Rectangle() {
			delete [] vertices;
		}
		void draw() {
			cout<<"Color:  "<<Shape::getColor()<<endl;
			cout<<"Vertices: "<<endl;
			cout<<vertices[0].getX()<<", "<<vertices[0].getY()<<endl;
			cout<<vertices[1].getX()<<", "<<vertices[1].getY()<<endl;
			cout<<vertices[2].getX()<<", "<<vertices[2].getY()<<endl;
			cout<<vertices[3].getX()<<", "<<vertices[3].getY()<<endl;
		};
		double area() {
			return (vertices[1].getX() - vertices[0].getX()) * (vertices[3].getY() - vertices[0].getY());
		}
};

int main() {
	Point2D pt(3,4);
	Circle cir(pt, 5);

	Point2D *vec = new Point2D [3];
	vec[0].setPoint2D(1,1);
	vec[1].setPoint2D(1,6);
	vec[2].setPoint2D(8,1);
	Triangle tri(vec);
	delete []vec;

	vec = new Point2D [4];
	vec[0].setPoint2D(1,1);
	vec[1].setPoint2D(6,1);
	vec[2].setPoint2D(6,6);
	vec[3].setPoint2D(1,6);
	Rectangle rect(vec);
	delete [] vec;

	Shape *collection[3];
	collection[0] = &cir;
	collection[1] = &tri;
	collection[2] = &rect;

	cout << "Area of Circle: " << collection[0]->area() << endl;
	cout << "Area of Triangle: " << collection[1]->area() << endl;
	cout << "Area of Rectangle: " << collection[2]->area() << endl;
	return 0;
}
