// lab8-2-2.cpp
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::istringstream;
using std::string;

int main() {
	string s1 = "value 6";
	string s2;
	istringstream format_str(s1);
	int a;
	format_str >> s2 >> a;
	cout << a << endl;
	
	return 0;
}
