// ex1-2.cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// #define DEBUG

// Constant
const int MAX = 1000;

typedef struct {
	double coeff;
	int power;
} Items;

typedef struct {
	Items items[MAX];
	int num_items;
} Poly;

// Declaration
void ReadTextFile(char* argv_1, Poly &eq);
void DifferentationPoly(Poly &eq);
void PrintComplex(char* argv_2, Poly &eq);

int main(int argc, char *argv[]) {
	Poly eq;
	ReadTextFile(argv[1], eq); // process text file
	DifferentationPoly(eq); // differentiation of polynomials
	PrintComplex(argv[2], eq); // print the results on file.
	return 0;
}


void ReadTextFile(char* argv_1, Poly &eq) {
	cout<<"input file: "<<argv_1<<endl;

	string input;
	string item_string[MAX];
	// read file
	ifstream myfile(argv_1);
	if (myfile.is_open()) {
		getline(myfile, input);
		cout<<"input = "<<input<<endl;
	}
	// Parsing text
	int j=0;
	eq.num_items=0;
	for(int i=1; i<input.length(); i++) {
		if ((input.at(i)=='+') || (input.at(i)=='-')) {
			item_string[eq.num_items] = input.substr(j,i-j);
#ifdef DEBUG
			cout<<"item_"<<eq.num_items<<"="<<item_string[eq.num_items]<<endl;
#endif			
			eq.num_items++;
			j=i;
		}
	}
	item_string[eq.num_items] = input.substr(j,input.length()-j);
	eq.num_items++;

	// parsing individual text item
	for (int i=0; i<eq.num_items; i++) {
		int found = item_string[i].find("X");
		if(found == string::npos) {
			// coefficient
			eq.items[i].coeff = stof(item_string[i]);
			// power
			eq.items[i].power = 0;
		} else {
			if(item_string[i].substr(0, found) == "+") {
				eq.items[i].coeff = 1;
			} else {
				// coefficient
				eq.items[i].coeff = stof(item_string[i].substr(0, found));
			}
			// power
			if(item_string[i].length() == found+1) { // power = 1
				eq.items[i].power = 1;
			} else {	// power >= 2
				string tmp = item_string[i].substr(found+2, item_string[i].length()-found-2);
				eq.items[i].power = stoi(tmp);
			}
		}
		#ifdef DEBUG
		cout<<"eq.items["<<i<<"].coeff = "<<eq.items[i].coeff<<endl;
		cout<<"eq.items["<<i<<"].power = "<<eq.items[i].power<<endl;
		#endif 
	}
	// sort
	cout<<"sort"<<endl;
	for(int i=0; i<eq.num_items; i++) {
		for(int j=i; j<eq.num_items; j++) {
			if (eq.items[i].power < eq.items[j].power) {
				// swap
				int tmp_power = eq.items[j].power;
				double tmp_coeff = eq.items[j].coeff;
				eq.items[j].power = eq.items[i].power;
				eq.items[j].coeff = eq.items[i].coeff;
				eq.items[i].power = tmp_power;
				eq.items[i].coeff = tmp_coeff;
			}
		}
		#ifdef DEBUG		
		cout<<"eq.items["<<i<<"].coeff = "<<eq.items[i].coeff<<endl;
		cout<<"eq.items["<<i<<"].power = "<<eq.items[i].power<<endl;
		#endif 
	}
}

void DifferentationPoly(Poly &eq) {
	cout<<"diff"<<endl;
	for(int i=0; i<eq.num_items; i++) {
		if (eq.items[i].power != 0) {
			eq.items[i].coeff = eq.items[i].power * eq.items[i].coeff;
			eq.items[i].power = eq.items[i].power - 1;
		} else {
			eq.items[i].coeff = 0;
			eq.items[i].power = 0;
			eq.num_items--;			
		}
		#ifdef DEBUG	
		cout<<"eq.items["<<i<<"].coeff = "<<eq.items[i].coeff<<endl;
		cout<<"eq.items["<<i<<"].power = "<<eq.items[i].power<<endl;
		#endif 
	}
}


void PrintComplex(char* argv_2, Poly &eq) {
	
	// write file
	ofstream myfile (argv_2, ios::app);
	
	if(myfile.is_open()) {

		if (eq.items[0].power>1) {
			myfile<<eq.items[0].coeff<<"X^"<<eq.items[0].power;
			cout<<eq.items[0].coeff<<"X^"<<eq.items[0].power;
		} else if (eq.items[0].power==1) {
			myfile<<eq.items[0].coeff<<"X";
			cout<<eq.items[0].coeff<<"X";
		} else if (eq.items[0].power==0) {
			myfile<<eq.items[0].coeff;
			cout<<eq.items[0].coeff;
		}

		for(int i=1; i<eq.num_items; i++) {
			if (eq.items[i].power>1) {
				myfile<<"+"<<eq.items[i].coeff<<"X^"<<eq.items[i].power;
				cout<<"+"<<eq.items[i].coeff<<"X^"<<eq.items[i].power;
			} else if (eq.items[i].power==1) {
				myfile<<"+"<<eq.items[i].coeff<<"X";
				cout<<"+"<<eq.items[i].coeff<<"X";
			} else if (eq.items[i].power==0) {
				myfile<<"+"<<eq.items[i].coeff;
				cout<<"+"<<eq.items[i].coeff;
			}
		}
	} else {
		cout<< "WRITE FILE ERROR!!"<< endl;
	}
}
