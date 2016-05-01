#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class CComplex {
    double real, imag;
public:
    CComplex() { real=0; imag=0; }
    CComplex(double r, double i) { real=r; imag=i; }
    void setCComplex(double r, double i) { real=r; imag=i; }
    void display() { cout << "(" << real
        << "," << imag << "i)" << endl; }
};

int main() {
	ifstream inp("dat6-7.txt", ios::in);
	if (!inp) { cout << "dat6-7.txt cannot be opened!\n"; return -1; }
	string line, text;
	int ccnum = 0;
	while (getline(inp,line)) {
		ccnum++;
		text = text + " " + line ;
	}
	
	CComplex * ccary = new CComplex[ccnum];
	stringstream ss(text); cout << ss.str() << endl;
	double r,i;
	for (int x=0; x<ccnum; ++x) {
		ss >> r >> i; cout << r << i << endl;
		ccary[x].setCComplex(r,i);
		ccary[x].display();
	}
	
	system("Pause");    
    return 0;
}		
