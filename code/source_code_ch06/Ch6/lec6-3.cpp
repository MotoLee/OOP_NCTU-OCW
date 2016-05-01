#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    fstream myFile;
    myFile.open("test1.dat", ios::in);
    if (myFile.good())
        cout << "File opened!" << endl;
    else
        cout << "Cannot open file!" << endl;
	myFile.open("test2.dat", ios::out);
    if (myFile.good())
        cout << "File opened!" << endl;
    else
        cout << "Cannot open file!" << endl;
 	myFile.open("test3.dat", ios::app);
    if (myFile.good())
        cout << "File opened!" << endl;
    else
        cout << "Cannot open file!" << endl;
    myFile.open("test4.dat", ios::ate);
    if (myFile.good())
        cout << "File opened!" << endl;
    else
        cout << "Cannot open file!" << endl; 
		
		
	double sum=0, t; int count=0;
    ifstream in("dat6-3.txt", ios::in);
    if (!in) 
        cout << "Cannot open file!" << endl;
    while (in >> t) {
        sum += t;
        count++;
    }
    cout << "avg = " << sum/count << endl;
	
		
		   
    system("Pause");    
    return 0;
}

