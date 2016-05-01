// ex12-1
#include <iostream>
#include <stdlib.h>
using namespace std;

class Point2D {
	private:
		int x;
		int y;
	public:
		int getX() const {
			return x;
		}
		int getY() const {
			return y;
		}
		void setX(int n) {
			x = n;
		}
		void setY(int n) {
			y = n;
		}
// add any member if necessary
};
template<class T>
T* new1D(int n, int k) {
	T* tmp = new T[n];
	return tmp;
}
template<class T>
void rand1D(T* vec, int n);
template<>
void rand1D(int* vec, int n) {
	for(int i=0; i<n; i++)
		vec[i] = rand()%10 + 1;
}
template<>
void rand1D(double* vec, int n) {
	for(int i=0; i<n; i++)
		vec[i] = (double) (rand() % 1000) / 100;
}
template<>
void rand1D(char* vec, int n) {
	for(int i=0; i<n; i++)
		vec[i] = rand()%26 + 97;
}
template<>
void rand1D(Point2D* vec, int n) {
	for(int i=0; i<n; i++) {
		vec[i].setX(rand()%10);
		vec[i].setY(rand()%10);
	}
}
template<class T>
void display1D(T* vec, int n) {
	for(int i=0; i<n; i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}
template<>
void display1D(Point2D* vec, int n) {
	for(int i=0; i<n; i++)
		cout<<"("<<vec[i].getX()<<", "<<vec[i].getY()<<")";
	cout<<endl;
}
template<class T>
void sort1D(T* vec, int n) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
//			cout<<"i="<<i<<", j="<<j<<", vec["<<i<<"]="<<vec[i]<<", vec["<<j<<"]="<<vec[j]<<", all: ";
			if (vec[i] > vec[j]) {
				// swap
				T tmp = vec[i];
				vec[i] = vec[j];
				vec[j] = tmp;
			}
//			for(int k=0; k<n; k++)
//				cout<<vec[k]<<" ";
//			cout<<endl;
		}
	}
}
template<>
void sort1D(Point2D* vec, int n) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			// swap x & y
			if ( vec[i].getX() >= vec[j].getX() ) {
//				cout<<"i="<<i<<", j="<<j<<", before swap x: ";
//				display1D(vec,n);
				int tmp = vec[i].getX();
				vec[i].setX(vec[j].getX());
				vec[j].setX(tmp);
				tmp = vec[i].getY();
				vec[i].setY(vec[j].getY());
				vec[j].setY(tmp);
//				cout<<"after swap x:";
//				display1D(vec,n);				
				// if x is equal, then swap y
				if(vec[i].getX() == vec[j].getX() && vec[i].getY() > vec[j].getY()) {
//					cout<<"before swap Y: ";
//					display1D(vec,n);
					tmp = vec[i].getY();
					vec[i].setY(vec[j].getY());
					vec[j].setY(tmp);
//					cout<<"after swap Y: ";
//					display1D(vec,n);					
				}
			}
		}
	}
}
template<class T>
void analysis(int n, int k = 0) {
	T* vec = new1D<T>(n, k);
	// for int 1~10, for double 0.00~10.00, for char a~z, for Point2D x: 0~9 y:0~9
	rand1D<T>(vec,n);
	display1D<T>(vec,n);

	sort1D<T>(vec,n);
	display1D<T>(vec,n);
}

int main() {

	int n;
	cout << "Enter n: ";
	cin >> n;
	srand(1);

	analysis<int>(n);
	analysis<double>(n);
	analysis<char>(n);
	analysis<Point2D>(n);

	return 0;
}
