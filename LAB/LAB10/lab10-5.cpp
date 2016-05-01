// lab10-5.cpp
#include <iostream>
using std::cout;
using std::endl;

#define	PI	3.14

class Point2D {
	private:
		int x;
		int y;
	public:
		Point2D() { x = 0; y = 0; }
		Point2D(int a, int b) { x = a; y = b; }
		void setValue(int a, int b){ x = a; y = b; }
		void display() const{
			cout<<"("<<x<<", "<<y<<")";
		};
		int getX(){ return x; }
		int getY(){ return y; }
// ¡K
};
class Shape {
	protected:
		int color;
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
			cout<<"center = ";
			center.display();
			cout<<endl<<"radius = "<<radius<<endl;
		};
		double area(){
			return (PI * radius * radius);
		}
//¡K
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
			for(int i=0; i<3; i++){
				cout<<"vertice["<<i<<"] = ";
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
		using Triangle::area; 
		Circle_in_Triangle() : Circle(), Triangle() { }
		Circle_in_Triangle(Point2D p, double r, Point2D* v) : Circle(p,r), Triangle(v) { }
		void draw() {
			cout << "Circle's color: " << Circle::color << endl;
			cout << "Triangle's color: " << Triangle::color << endl;
			Circle::draw();
			Triangle::draw();
		}
};

int main() {
	Point2D p(7,7);
	Point2D *vec = new Point2D [3];
//	// (1,2) & (3,4) & (5,6)
//	vec[0].setValue(0,0);
//	vec[1].setValue(3,0);
//	vec[2].setValue(0,6);		
	Circle_in_Triangle ct(p,5,vec);
	ct.draw();
	return 0;
}
