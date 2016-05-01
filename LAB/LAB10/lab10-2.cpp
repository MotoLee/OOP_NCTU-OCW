// lab10-2.cpp
#include <iostream>
using std::cout;
using std::endl;

class Point2D {
	private:
		int x;
		int y;
	public:
		Point2D() { x = 0; y = 0; }
		Point2D(int a, int b) { x = a; y = b; }
//		void setValue(int a, int b){ x = a; y = b; }
		void display() const{
			cout<<"("<<x<<", "<<y<<")";
		};
// ¡K
};
class Circle {
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
			cout<<"center = ";
			center.display();
			cout<<endl<<"radius = "<<radius<<endl;
		};
//¡K
};
class Triangle {
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
			for(int i=0; i<3; i++){
				cout<<"vertice["<<i<<"] = ";
				vertices[i].display();
				cout<<endl;
			}
		};
};
class Circle_in_Triangle: public Circle, public Triangle {
	public:
		Circle_in_Triangle() : Circle(), Triangle() { }
		Circle_in_Triangle(Point2D p, double r, Point2D* v) : Circle(p,r), Triangle(v) { }
		void draw() {
			Circle::draw();
			Triangle::draw();
		}
};

int main() {
	Point2D p;
	Point2D *vec = new Point2D [3];
	// (1,2) & (3,4) & (5,6)
//	vec[0].setValue(1,2);
//	vec[1].setValue(3,4);
//	vec[2].setValue(5,6);
	Circle_in_Triangle ct(p,0,vec);
	ct.draw();
	return 0;
}
