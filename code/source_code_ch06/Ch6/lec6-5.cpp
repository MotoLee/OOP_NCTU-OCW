#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
	ofstream out("6-4.txt", ios::out | ios::binary);
	if (!out) {
		cout << "Cannot open 6-4.txt for write" << endl; 
		return -1;	
	}	
	for (int i=1; i<100; i+=2) {
		out.write((char *)&i, sizeof(i));
	}
	out.close();
	
	ifstream inp("6-4.txt", ios::in | ios::binary);
	if (!inp){
		cout << "Cannot open 6-4.txt for read" << endl; 
		return -1;	
	}
	inp.seekg(15*sizeof(int)); //move to 16th odd integers
	int x;
	for (int i=1; i<50 && !inp.eof(); ++i) {
		inp.read((char *)&x, sizeof(i));
		cout << x << " ";
		if (!(i%=10)) cout << endl;	
	}
	cout << endl;
	inp.close();	
	
    system("Pause");    
    return 0;
}	
