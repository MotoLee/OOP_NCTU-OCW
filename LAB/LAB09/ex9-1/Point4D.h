// Point4D.h
#ifndef POINT4D_H
#define POINT4D_H

#include "Point2D.h"
class Point4D : public Point2D{
	private:
		int *z;
		int *t;
	public:
		Point4D(int n1, int n2, int n3, int n4);
		Point4D();
		void display() const;
		void operator= (const Point2D& a);
};
#endif
