// lab5-3.cpp
#include <iostream>
#include <assert.h>

//1. class PointND defined in lab5-2
//2. add the definition of copy constructor to the class
const int num = 10;
class PointND {
	private:
		int *coord;
		double value;
	public:
		PointND();
		PointND(const PointND &pt);
		~PointND();
		void assignValue(double v);
		void assignCoord(int *vec, int len);
		void displayPointND();
};
PointND::PointND() {
	value = 0.0;
	coord = new int [num];
	for (int i=0; i<num; i++) coord[i] = 0;
}
// copy constructor
PointND::PointND(const PointND &pt) {
	value = pt.value;
	coord = new int [num];
	for (int i=0; i<num; i++) coord[i] = pt.coord[i];
}
PointND::~PointND() {
	delete []coord;
}
void PointND::assignValue(double v) {
	value = v;
}
void PointND::assignCoord(int *vec, int len) {
	assert(len <= num); // make sure len <= num
	for (int i=0; i<len; i++)
		coord[i] = vec[i];
}
void PointND::displayPointND() {
	std::cout << "(";
	for (int i=0; i<num; i++) {
		std::cout << coord[i];
		if (i!=num-1)
			std::cout << ", ";
	}
	std::cout << ") = " << value << std::endl;
}

int main() {
	int *vec = new int [num];
	for (int i=0; i<num; i++) vec[i] = i;
	PointND pt1;
	pt1.assignValue(4.3);
	pt1.assignCoord(vec,num);
	pt1.displayPointND();
	PointND pt2(pt1);
	pt2.displayPointND();
	delete []vec;
	return 0;
}
