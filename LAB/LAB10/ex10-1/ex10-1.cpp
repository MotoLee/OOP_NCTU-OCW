// ex10-1
#include <iostream>
using namespace std;

#define	PI	3.14

class Point2D {
	private:
		int x;
		int y;
	public:
		Point2D() { x = 0; y = 0; }
		Point2D(int a, int b) { x = a; y = b; }
		void setValue(int a, int b){ x = a; y = b; }
		void display(){
			cout<<x<<","<<y;
		}
		int getX() const { return x; }
		int getY() const { return y; }
// ¡K
};
class Shape {
	protected:
		int color;
	public:
		Shape(){ color = 255; }
		Shape(int c){ color = c; }
};
class Circle : public virtual Shape{
	private:
		Point2D center;
		double radius;
	public:
		Circle(){ radius = 0; };
		Circle(Point2D c, double r){
			center = c;
			radius = r;
		}
		void draw(){
			cout<<"center : ";
			center.display();
			cout<<endl<<"radius: "<<radius<<endl;
		};
		double area(){
			return (PI * radius * radius);
		}
};
class Triangle : public virtual Shape{
	private:
		Point2D *vertices;
	public:
		Triangle(){ vertices = NULL; }
		Triangle(Point2D* v){
			vertices = new Point2D[3];
			for(int i=0; i<3; i++) 
				vertices[i] = v[i];
		}
		~Triangle() {
			delete [] vertices;
		}
		void draw(){
			cout<<"Vertice: "<<endl;
			for(int i=0; i<3; i++){
				vertices[i].display();
				cout<<endl;
			}
		};
		int area(){
			int s = 0;
			for (int i=0; i<3; i++){
				s += vertices[i].getX() * vertices[(i+1)%3].getY() - vertices[i].getY() * vertices[(i+1)%3].getX();
			}
			return (s/2);
		}
};
class Circle_in_Triangle: public Circle, public Triangle {
	public:
		Circle_in_Triangle() : Circle(), Triangle() { }
		Circle_in_Triangle(Point2D p, double r, Point2D* v) : Circle(p,r), Triangle(v) { }
		double area(){
			return (Triangle::area() - Circle::area());
		}
		void draw() {
			cout << "Circle's color: " << Circle::color << endl;
			cout << "Triangle's color: " << Triangle::color << endl;
			Circle::draw();
			Triangle::draw();
			cout << "Area of Circle: "<<Circle::area()<<endl;
			cout << "Area of Triangle: "<<Triangle::area()<<endl;
			cout << "Area of Circuit_in_Triangle: "<<area()<<endl;
		}
};

int main() {
	Point2D p(2,2);
	int radius = 1;
	Point2D *vec = new Point2D [3];
	// (2,1) & (8,1) & (5,6)
	vec[0].setValue(2,1);
	vec[1].setValue(8,1);
	vec[2].setValue(5,6);
			
	Circle_in_Triangle ct(p, radius, vec);
	ct.draw();
	
	return 0;
}
