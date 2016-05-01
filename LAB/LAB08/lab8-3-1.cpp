// lab8-3-1.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream out("out.dat", ios::binary);
	for ( int i = 0 ; i < 10 ; ++i) {
		out.write((char*)&i, sizeof(i));
	}
	out.close();
	return 0;
}
