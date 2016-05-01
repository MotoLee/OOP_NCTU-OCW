// lab11-2.cpp
#include <iostream>
using std::cout;
using std::endl;

/* The Point2D and Point4D defined in lab11-1  */
/* Add declarations of display() in Point2D and Point4D, respectively. */
class Point2D {
	private:
		int *x;
		int *y;
	public:
		Point2D() {
			x = new int (0);
			y = new int (0);
			cout << "New X and Y" << endl;
		}
		virtual ~Point2D() {
			delete x;
			delete y;
			cout << "Delete X and Y" << endl;
		}
		virtual void display() const {
			cout << *x << "," << *y;
		}
};
class Point4D : public Point2D {
	private:
		int *z;
		int *t;
	public:
		Point4D() : Point2D() {
			z = new int (0);
			t = new int (0);
			cout << "New Z and T " << endl;
		}
		~Point4D() {
			delete z;
			delete t;
			cout << "Delete Z and T" << endl;
		}
		void display() const {
			Point2D::display();
			cout << "," << *z << "," << *t;
		}
};
int main() {
	Point2D *pt = new Point4D;
	pt->display();
	cout << endl;
	delete pt;
	return 0;
}
