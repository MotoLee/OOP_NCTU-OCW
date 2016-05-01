#include <iostream>
#include "Point2D.h"
#include "Point4D.h" 
using std::cout;
using std::endl;

Point2D::Point2D(){
	x = new int();
	y = new int();
	*x = 0;
	*y = 0;
}
Point2D::Point2D(int a, int b){
	x = new int();
	y = new int();
	*x = a;
	*y = b;
}
void Point2D::display () const{
	cout << "x = " << *x << ", y = " << *y ;
}
void Point2D::setValue(int a, int b){
	cout<<"a = "<<a<<", b = "<<b<<endl;
	*x = a;
	*y = b;
}
int* Point2D::getValueX(const Point2D &a) const { return a.x; }
int* Point2D::getValueY(const Point2D &a) const { return a.y; }

Point4D::Point4D(){
	z = new int();	*z = 0;
	t = new int();	*t = 0;
}
Point4D::Point4D(int n1, int n2, int n3, int n4) : Point2D(n1, n2){
	z = new int();	*z = n3;
	t = new int();	*t = n4;
}

void Point4D::display() const {
	Point2D::display();
	cout << ", z = " << *z << ", t = " << *t ;
}
void Point4D::operator= (const Point2D& a){
	setValue(*(getValueX(a)), *(getValueY(a)));
}


int main() {
	Point2D pt1(1,2);
	Point2D pt2(3,4);
	
	pt1.display(); cout << endl;
	pt2.display(); cout << endl;
	
	pt2 = pt1;
	pt2.display(); cout << endl;
	
	Point4D pt4(5,6,7,8);
	pt4.display(); cout << endl;
	
	pt2 = pt4;
	pt2.display(); cout << endl;
	
	pt4 = pt1;
	pt4.display(); cout << endl; //pt4 could be (1, 2,7,8) or (1,2,0,0)
	
	return 0;
}

