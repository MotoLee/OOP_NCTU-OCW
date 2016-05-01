// Vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <class T>
class Vector {
	private:
		T* vec;
		int len;
	public:
		Vector(int n) {
			len = n;
			vec = new T[len];
			for(int i=0; i<len; i++)
				vec[i] = 0;
		};
		Vector(int n, int t) {
			len = n;
			vec = new T[len];
			for(int i=0; i<len; i++)
				vec[i] = t;
		};
		Vector(int n, T* pt) {
			len = n;
			vec = new T[len];
			for(int i=0; i<len; i++)
				vec[i] = pt[i];
		};
//		~Vector(){
//			cout<<"delete Vector"<<endl;
//			delete vec;
//		}
		void display() {
			for(int i=0; i<len; i++)
				cout<<vec[i]<<" ";
			cout<<endl;
		}
		operator+= (Vector<T> & v) {
			for(int i=0; i<len; i++) {
				vec[i] += v.vec[i];
			}
		}
		int getlen() const {
			return len;
		}
		T getVec(int i) const {
			return vec[i];
		}
		template<class S>
		friend S dot (const Vector<S> & v1, const Vector<S> & v2);
};

// Specialize the constructor in Vector
template<>
Vector<Point2D>::Vector(int n, int t) {
	len = n;
	vec = new Point2D[len];
	for(int i=0; i<len; i++) {
		vec[i].setX(t);
		vec[i].setY(t);
	}
}
// Specialize a function in Vector
template<>
void Vector<Point2D>::display() {
	for(int i=0; i<len; i++)
		cout<<"("<<vec[i].getX()<<", "<<vec[i].getY()<<") ";
	cout<<endl;
}
// Specialize an operator overloading function in Vector
template<>
Vector<Point2D>::operator+= (Vector<Point2D> & v) {
	for(int i=0; i<len; i++) {
		vec[i].setX(vec[i].getX()+v.vec[i].getX());
		vec[i].setY(vec[i].getY()+v.vec[i].getY());
	}
}
// friend function dot
template <class S>
S dot (const Vector<S> & v1, const Vector<S> & v2) {
	S sum = 0;
	for(int i=0; i<v1.getlen(); i++) {
		sum += v1.getVec(i) * v2.getVec(i);
	}
	return sum;
}
// function template specialization
template <>
Point2D dot(const Vector<Point2D> & v1, const Vector<Point2D> & v2) {
	Point2D sum(0,0);
	for(int i=0; i<v1.getlen(); i++) {
		sum.setX(sum.getX() + v1.getVec(i).getX() * v2.getVec(i).getX());
		sum.setY(sum.getY() + v1.getVec(i).getY() * v2.getVec(i).getY());
	}
	return sum;
}


#endif
