// Point2D.h
#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
using namespace std;

class Point2D {
	private:
		int *x;
		int *y;
	public:
		Point2D(int a, int b);
		Point2D();
		void display() const;
		void setValue(int a, int b);
		int* getValueX(const Point2D &a) const;
		int* getValueY(const Point2D &a) const;
};

#endif
