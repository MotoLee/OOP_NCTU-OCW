// lab5-2.cpp
#include <iostream>
#include <assert.h>

const int num = 10;
class PointND {
	private:
		int *coord;
		double value;
	public:
		PointND();
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
	PointND pt1;
	pt1.displayPointND();
	
	PointND pt2;
	pt2.assignValue(1.0);
	pt2.displayPointND();
	int *vec = new int [num];
	for (int i=0; i<num; i++) vec[i] = i;
	
	PointND pt3;
	pt3.assignValue(4.3);
	pt3.assignCoord(vec, num);
	pt3.displayPointND();
	delete []vec;
	
	return 0;
}
