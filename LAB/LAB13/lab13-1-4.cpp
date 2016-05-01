// lab13-1-4.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

int main() {
	int n = 10;
	vector<int> vec(n);
	for (int i=0; i<vec.size(); i++) 	// vec = {1,7,4,0,9,4,8,8,2,4}
		vec[i] = rand()%n;
	sort(vec.begin(), vec.end()); 		// vec = {0,1,2,4,4,4,7,8,8,9}
	reverse(vec.begin(), vec.end()); 	// vec = {9,8,8,7,4,4,4,2,1,0}
	for (int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	
	vector<int>::iterator iter = find(vec.begin(), vec.end(), 8);
	if (iter!=vec.end())
		cout << "8 is in the vector: " << iter - vec.begin() + 1 << "th" << endl;
	else
		cout << "8 is not in the vector" << endl;
	
	return 0;
}
