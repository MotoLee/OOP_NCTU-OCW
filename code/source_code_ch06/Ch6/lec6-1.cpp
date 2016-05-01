#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXLINE = 256;

int main() {
	int x;

	//get with no argument
	cout << "Enter a key for get():" << endl;
	x = cin.get();
	cout << x << endl;

	char line[MAXLINE];
	//get with arguments;
	cout << "Enter a line for get() w/ 2 arguments:" << endl;
	cin.get(line,'\t');
	cout << line << endl;
	cout << "Enter a line for get() w/ 3 arguments:" << endl;
	cin.get(line, 100, '\n');
	cout << line << endl;
	//getline with arguments;
	cout << "Enter a line for getline() w/ 3 arguments:" << endl;
	cin.getline(line, 10, ' ');
	cout << line << endl;
	//ignore with arguments;
	cout << "Enter your first and last names: ";
	char first = cin.get();
	cin.ignore(256,' ');
	char last = cin.get();
	cout << "Your initial is " << first << "." << last << "." << endl;

//	system("Pause");
	return 0;
}

