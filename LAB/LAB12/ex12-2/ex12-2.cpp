// ex12-2.cpp
#include<iostream>
#include "Point2D.h"
#include "Vector.h"
using namespace std;


int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	
	// devc & devc2
	Vector<double> dvec(n,1);
	double *b = new double[n];
	for (int i=0; i<n; i++) b[i] = i;
	Vector<double> dvec2(n,b);
	cout << "dvec = ";
	dvec.display();
	cout << "dvec2 = ";
	dvec2.display();	
	dvec2 += dvec;
	cout << "new dvec = ";
	dvec2.display();	
	double c = dot(dvec, dvec2);
	cout << "dot(dvec, dvec2) = " << c << endl << endl;
	
	srand(1);
	Point2D *v = new Point2D[n];
	rand1D<Point2D>(v,n); // 0~9
	
	// vp1 & vp2
	Vector<Point2D> vp1(n,1);
	Vector<Point2D> vp2(n,v);
	cout << "vp1 = ";
	vp1.display();
	cout << "vp2 = ";
	vp2.display();
	vp2 += vp1;
	cout << "new vp2 = ";
	vp2.display();
	Point2D d = dot(vp1, vp2);
	cout << "dot(vp1, vp2) = " << d << endl;
	
	return 0;
}
