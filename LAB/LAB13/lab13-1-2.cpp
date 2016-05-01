// lab13-1-2.cpp
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

class Point2D {
	private:
		int x;
		int y;
	public:
		Point2D(): x(0), y(0) {}
		Point2D(int a, int b): x(a), y(b) {}
		friend ostream &operator << (ostream &out, const Point2D &p) {
			out << "(" << p.x << "," << p.y << ")";
		}
};

int main() {
	int n = 10;
	vector<Point2D> vec(n); // call Point2D()
	for (int i=0; i<vec.size(); i++)
		vec[i] = Point2D(i*2,i*3); // call Point2D(int a, int b)
	for (int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	
	return 0;
}
