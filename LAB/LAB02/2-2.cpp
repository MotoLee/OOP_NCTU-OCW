// ex2-2.cpp
#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
using namespace std;

typedef struct {
	int *data;
	int length;
	bool sign;
} BIGNUMBER;

void ReadTextFile(char* argv_1, BIGNUMBER &a, BIGNUMBER &b);
BIGNUMBER BigNumberOperation(BIGNUMBER a, BIGNUMBER b, char c);
void WriteResults(char* argv_2, BIGNUMBER* results);

int main(int argc, char *argv[]) {
	BIGNUMBER a, b;
	ReadTextFile(argv[1], a, b);
	BIGNUMBER results[2];
	results[0] = BigNumberOperation(a,b,'+');
	results[1] = BigNumberOperation(a,b,'-');
	WriteResults(argv[2], results);
	return 0;
}

void ReadTextFile(char* argv_1, BIGNUMBER &a, BIGNUMBER &b) {

	cout<<"ReadTextFile"<<endl;
	// read text from file
	string line[2];
	ifstream myfile(argv_1);
	if(myfile.is_open()) {
		for(int i=0; ((i<2) && (getline(myfile, line[i])!=NULL)); i++) {
			cout<<"line["<<i<<"] = "<<line[i]<<endl;
//			for(int j=0; j<line[i].length(); j++) {
//				cout<<"line["<<i<<"].at("<<j<<")="<<line[i].at(j)<<endl;
//			}
		}
	} else {
		cout<<"READ ERROR!"<<endl;
	}
	// parsing
	a.sign = (line[0].at(0) == '-')? 1:0;
	if(a.sign) {
		a.length = line[0].length()-1;
		a.data = new int[a.length];
		for(int i=a.length-1; i>=0; i--) {
			a.data[i] = line[0].at(i+1)-'0';
		}
	} else {
		a.length = line[0].length();
		a.data = new int[a.length];
		for(int i=a.length-1; i>=0; i--) {
			a.data[i] = line[0].at(i)-'0';
		}
	}
	b.sign = (line[1].at(0) == '-')? 1:0;
	if(b.sign) {
		b.length = line[1].length()-1;
		b.data = new int[b.length];
		for(int i=b.length-1; i>=0; i--) {
			b.data[i] = line[1].at(i+1)-'0';
		}
	} else {
		b.length = line[1].length();
		b.data = new int[b.length];
		for(int i=b.length-1; i>=0; i--) {
			b.data[i] = line[1].at(i)-'0';
		}
	}

}

BIGNUMBER BigNumberOperation(BIGNUMBER a, BIGNUMBER b, char c) {
		
	cout<<"BigNumberOperation"<<endl;

	// create a new int* to save the result
	int* a_ptr = a.data;
	int* b_ptr = b.data;
	// This is important!! Create a new int array, in order not to overwrite the original memory
	a.data = new int[a.length];	
	b.data = new int[b.length];
	for(int i=0; i<a.length; i++) {
		a.data[i] = a_ptr[i];
	}
	for(int i=0; i<b.length; i++) {
		b.data[i] = b_ptr[i];
	}
	
	// a-b = a+(-b)
	if(c == '-') {
		if(b.sign) {
			b.sign = false;
		} else {
			b.sign = true;
		}
	}
	cout<<"a.sign = "<<a.sign<<endl;
	cout<<"b.sign = "<<b.sign<<endl;

	// make sure a.length > b.length
	if(a.length < b.length) {
		BIGNUMBER tmp = a;
		a = b;
		b = tmp;
	}
	// plus
	if(a.sign==b.sign) {	// (+) + (+) or (-) + (-)
		// add
		for(int i=0; i<b.length; i++) {
			a.data[a.length-1-i] = a.data[a.length-1-i] + b.data[b.length-1-i];
//			cout<<"a.data["<<a.length-1-i<<"]="<<a.data[a.length-1-i]<<endl;
		}
		// check if bigger than 9?
		for(int i=a.length-1; i>0; i--) {
			if(a.data[i]>=10) {
				a.data[i] = a.data[i] - 10;
				a.data[i-1]++;
			}
		}
		// check if need to enlarge?
		if(a.data[0]>=10) {
			int* tmp = a.data;
			a.length = a.length + 1;
			a.data = new int[a.length];
			for(int i=a.length-1; i>0; i--) {
				a.data[i] = tmp[i-1];
			}
			a.data[1] = a.data[1]-10;
			a.data[0] = 1;
		}
	} else {	// (+) + (-) or (-) + (+)
		// add
		for(int i=0; i<b.length; i++) {
			a.data[a.length-1-i] = a.data[a.length-1-i] - b.data[b.length-1-i];
//			cout<<"a.data["<<a.length-1-i<<"]="<<a.data[a.length-1-i]<<endl;
		}
		// check if smaller than 0?
		for(int i=a.length-1; i>0; i--) {
			if(a.data[i]<0) {
				a.data[i] = a.data[i] + 10;
				a.data[i-1]--;
			}
//			cout<<"a.data["<<i<<"]="<<a.data[i]<<endl;
		}

	}

	cout<<"-------------"<<endl;
	cout<<"Return: "	;
	for(int i=0; i<a.length; i++) {
		cout<<a.data[i];
	}
	cout<<endl;
	cout<<"-------------"<<endl;

	return a;
}

void WriteResults(char* argv_2, BIGNUMBER* results) {

	cout<<"WriteResults"<<endl;
	// write files
	ofstream myfile(argv_2);

	if(myfile.is_open()) {
		// add
		cout<<"A + B = ";
		myfile<<"A + B = ";
		for(int i=0; i<results[0].length; i++) {
			cout<<results[0].data[i];
			myfile<<results[0].data[i];
		}
		cout<<endl;
		myfile<<endl;
		// subtract
		cout<<"A - B = ";
		myfile<<"A - B = ";
		for(int i=0; i<results[1].length; i++) {
			cout<<results[1].data[i];
			myfile<<results[1].data[i];
		}
		cout<<endl;
		myfile<<endl;
	}
	
	delete [] results[0].data;
	delete [] results[1].data;
	results = NULL;

}

