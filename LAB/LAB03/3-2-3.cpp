// lab3-2-3.cpp
#include <iostream>

typedef struct {
	int x;
	int y;
	double value;
} Point2D;

void assignPoint2D(Point2D &obj, int x, int y, double value) {
	obj.x = x;
	obj.y = y;
	obj.value = value;
}

void displayPoint2D(Point2D &obj) {
	std::cout << "(" << obj.x << "," << obj.y << ") = "  << obj.value << std::endl;
}

int main() {
	Point2D ptArray[10];
	for (int i=0; i<10; i++) {
		assignPoint2D(ptArray[i],i,i+2,i*10);
		displayPoint2D(ptArray[i]);
	}
	return 0;
}
