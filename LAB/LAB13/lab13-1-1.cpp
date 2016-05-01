// lab13-1-1.cpp
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {
	int n = 10;
	vector<int> vec1(n); // allocate a vector with 10 elements
	for (int i=0; i<vec1.size(); i++)
		vec1[i] = i * i; // use subscripting to access elements
	for (int i=0; i<vec1.size(); i++)
		cout << vec1[i] << " ";
	cout << endl;
	
	vector<int> vec2; // allocate an empty vector
	for (int i=0; i<n; i++)
		vec2.push_back(i * 2); // use push_back() to add elements
	vector<int>::const_iterator iter;
	for (iter = vec2.begin(); iter!= vec2.end(); iter++)
		cout << *(iter) << " "; // use iterator to traverse container
	cout << endl;
	
	return 0;
}
