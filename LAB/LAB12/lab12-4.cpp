// lab12-4.cpp
#include <iostream>
using namespace std;

class Complex {
	private:
		double real;
		double image;
	public:
		Complex(const double a, const double b) : real(a), image(b) {}
		Complex(const Complex &c) : real(c.real), image(c.image) {}
		void display() const {
			cout << real << " " << image << endl;
		}
};
// template Point2D defined in lab12-3
template <class T>
class Point2D {
	private:
		T x;
		T y;
	public:
		Point2D() : x(T(0)), y(T(0)) {}
		Point2D(T a, T b) : x(a), y(b) {}
		void display() const;
};
template <>
class Point2D<Complex> {
	private:
		Complex x;
		Complex y;
	public:
		Point2D(const Complex &a, const Complex &b) : x(a),y(b) {}
		void display() const;
};
void Point2D<Complex>::display() const {
	x.display();
	y.display();
}

int main() {
	
	Complex c1(1.9,3.4);
	Complex c2(2.0,1.3);
	Point2D<Complex> pc(c1,c2);
	pc.display();
	
	return 0;
}
