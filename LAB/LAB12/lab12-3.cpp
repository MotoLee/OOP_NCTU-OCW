// lab12-3.cpp
#include <iostream>
#include <iomanip>
using namespace std;

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
template <class T>
void Point2D<T>::display() const {
	cout << x << " " << y << endl;
}

int main() {
	Point2D<int> p1;
	p1.display();
	Point2D<double> p2(1.9,3.4);
	p2.display();
	
	return 0;
}
