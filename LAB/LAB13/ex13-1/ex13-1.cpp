#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Complex {
	private:
		double real;
		double image;
	public:
		Complex();
		Complex(double r, double i) {
			real = r;
			image = i;
		};
		double getR() {
			return real;
		}
		double getI() {
			return image;
		}
		double getAbs() {
			return sqrt(real*real + image*image);
		}
		void setValue(double r, double i);
};

Complex::Complex() {
	real = 0;
	image = 0;
}
void Complex::setValue(double r, double i) {
	real = r;
	image = i;
}
// Comparison function for sort()
bool comComplex(Complex a, Complex b) {
	return a.getAbs() > b.getAbs();
}

int main() {
	int n=5;
	cout<<"Enter n: "<<n<<endl;
	vector<Complex> cp(n);
	cp[0].setValue(1.6,4.7);
	cp[1].setValue(1.6,4.5);
	cp[2].setValue(7.5,8.4);
	cp[3].setValue(6.4,6.9);
	cp[4].setValue(3.8,3.4);

	cout<<"Original sequence:"<<endl;
	for(int i=0; i<n; i++) {
		cout<<"("<<cp[i].getR()<<", "<<cp[i].getI()<<") ";
	}
	cout<<endl;
	cout<<"Sorted sequence:"<<endl;
	sort(cp.begin(), cp.end(), comComplex);
	for(int i=0; i<n; i++) {
		cout<<"("<<cp[i].getR()<<", "<<cp[i].getI()<<") ";

	}
	cout<<endl;
	
	return 0;
}
