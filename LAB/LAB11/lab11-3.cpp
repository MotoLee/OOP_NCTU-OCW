// lab11-3.cpp
#include <iostream>
using std::cout;
using std::endl;

class Shape {
	protected:
		int color;
	public:
		virtual void draw() = 0;
		virtual bool is_closed() = 0;
		virtual ~Shape() {}
};
int main() {
	Shape s;
	return 0;
}
