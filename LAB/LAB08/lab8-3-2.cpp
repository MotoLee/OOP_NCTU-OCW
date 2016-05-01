// lab8-3-2.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int num = 0;
	ifstream in("out.dat");
	for ( int i = 0 ; i < 10 ; ++i) {
		in.read((char*)&num,sizeof(i));
		cout << num << endl;
	}
	in.close();
	return 0;
}
