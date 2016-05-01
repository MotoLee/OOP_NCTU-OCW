// lab11-3-2.cpp
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
		virtual ~Shape() {}
		void setColor(int c) {
			color = c;
		}
		int getColor() const{
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
			x = new int (0);
			y = new int (0);
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
class Polygon: public Shape {
	public:
		bool is_closed() {
			return true;
		}
};
class Triangle: public Polygon {
	private:
		Point2D *vertices;
	public:
// constructor for Triangle
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
		void draw(){
			cout<<"Color:  "<<Shape::getColor()<<endl;
			cout<<"Vertices: "<<endl;
			cout<<vertices[0].getX()<<", "<<vertices[0].getY()<<endl;
			cout<<vertices[1].getX()<<", "<<vertices[1].getY()<<endl;
			cout<<vertices[2].getX()<<", "<<vertices[2].getY()<<endl;
		};
};
int main() {
	Point2D *vec = new Point2D[3];
	vec[0].setPoint2D(1,1);
	vec[1].setPoint2D(6,1);
	vec[2].setPoint2D(1,8);
	Triangle t(vec,255);
	delete []vec;
	t.draw();
	return 0;
}
