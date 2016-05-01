// lab8- 1.cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	char c;
	char str[100];
	// first example: getline()
	cout << "Enter a sentence: " << endl;
	cin.getline(str, 10, '\n');
	cout << "The sentence you enter is: " << str << endl;
	// second example: get()
	cout << "Enter a character: " << endl;
	cin.get(c);
	cout << "The character you type is: " << c << endl;
	return 0;
}
