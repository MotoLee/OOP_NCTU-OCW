// Ex6-1.cpp
#include<iostream>
using namespace std;

class quadrangle {
	public:
		class vertex;
		friend class quadrangle::vertex;
//		quadrangle(vertex &a, vertex &b, vertex &c, vertex &d);
		quadrangle(quadrangle::vertex &a, quadrangle::vertex &b) : a{
			rect = true;
			list[0].x = a.x;
			list[0].y = a.y;
			list[1].x = b.x;
			list[1].y = a.y;
			list[2].x = b.x;
			list[2].y = b.y;
			list[3].x = a.x;
			list[3].y = b.y;
		};
		~quadrangle() {};
//		void move(vertex &m);
		void draw();
		class vertex {
				friend class quadrangle;
			public:
				int x, y;
				vertex(int a, int b) {
					x=a;
					y=b;
				}
				~vertex() {};
		};

	private:
		bool rect = false;
//		static vertex origin(0,0);
		vertex list[4];
};

//quadrangle::quadrangle(vertex &a, vertex &b, vertex &c, vertex &d) {
//	list[0].x = a.x;
//	list[0].y = a.y;
//	list[1].x = b.x;
//	list[1].y = b.y;
//	list[2].x = c.x;
//	list[2].y = c.y;
//	list[3].x = d.x;
//	list[3].y = d.y;
//	if ((list[0].x == list[3].x) && (list[1].x == list[2].x) && (list[0].y == list[1].y) && (list[2].y == list[3].y))
//		rect = true;
//}

//void quadrangle::move(vertex &m) {
//	vertex tmp;
//	tmp.x = list[0].x - m.x;
//	tmp.y = list[0].y - m.y;
//	list[0].x = tmp.x;
//	list[0].y = tmp.y;
//	list[1].x = b.x - tmp.x;
//	list[1].y = a.y - tmp.y;
//	list[2].x = b.x - tmp.x;
//	list[2].y = b.y - tmp.y;
//	list[3].x = a.x - tmp.x;
//	list[3].y = b.y - tmp.y;
//}
void quadrangle::draw() {
	cout<<"v1: ("<<list[0].x<<","<<list[0].y<<") ";
	cout<<"v2: ("<<list[1].x<<","<<list[1].y<<") ";
	cout<<"v3: ("<<list[2].x<<","<<list[2].y<<") ";
	cout<<"v4: ("<<list[3].x<<","<<list[3].y<<") "<<endl;
}

int main() {
//	quadrangle q1(quadrangle::vertex(0,0),
//	              quadrangle::vertex(3,2),
//	              quadrangle::vertex(10,7),
//	              quadrangle::vertex(8,10));
//	quadrangle q2(quadrangle::vertex(3,6), quadrangle::vertex(10,9));
	quadrangle::vertex a(3,6);
	quadrangle::vertex b(10,9);
	cout<<a.x<<a.y<<endl;
	quadrangle q2(a, b);
//	cout << "q1 information" << endl;
//	q1.draw();
//	cout << endl;
	cout << "q2 information" << endl;
//	q2.draw();
	cout << endl;
//	cout << "q1 move to (5,5) " << endl;
//	q1.move(quadrangle::vertex(5,5));
//	cout << "q1 information" << endl;
//	q1.draw();
//	cout << endl;
//	quadrangle::origin = quadrangle::vertex(-5,3);
//	cout << "q2 move to (-1,2) " << endl;
//	q2.move(quadrangle::vertex(-1,2));
//	cout << "q2 information" << endl;
//	q2.draw();
//	cout << endl;

	return 0;
} // end main
