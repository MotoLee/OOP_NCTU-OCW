// lab13-2-2.cpp
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;

int main() {
	map<string,int> age;
	age["Mary"] = 22;
	age["Jacky"] = 18;
	age["John"] = 20;
	for (map<string,int>::const_iterator iter = age.begin();
	        iter != age.end(); iter++) {
		cout << "name: " << iter->first << " ";
		cout << "age: " << iter->second << endl;
	}
	
	return 0;
}
