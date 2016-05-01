// Point2D.h
#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
using namespace std;

class Point2D {
	private:
		int x;
		int y;
	public:
		Point2D() {
			x = 0;
			y = 0;
		}
		Point2D(int a, int b) {
			x = a;
			y = b;
		}
		int getX() const {
			return x;
		}
		int getY() const {
			return y;
		}
		void setX(int n) {
			x = n;
		}
		void setY(int n) {
			y = n;
		}
		friend ostream& operator<< (ostream& out, Point2D pt);
};

template<class T>
void rand1D(T* vec , int n) { };
// function template specialization
template<>
void rand1D(Point2D* vec, int n) {
	for(int i=0; i<n; i++) {
		vec[i].setX(rand()%10);
		vec[i].setY(rand()%10);
	}
};

// overload operator
ostream& operator<< (ostream& out, Point2D pt) {
	out<<"("<<pt.getX()<<", "<<pt.getY()<<") "<<endl;
	return out;
};


#endif
