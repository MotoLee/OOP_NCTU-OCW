// lab13-1-3.cpp
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {
	int n = 5;
	vector<int> vec(n,-1); 	// vec = {-1,-1,-1,-1,-1}
	vector<int> u(3);
	for (int i=0; i<3; i++) u[i] = i; 	// u = {0,1,2}
	vec.insert(vec.begin()+2, u.begin(), u.end());		
	// insert u into vec, vec = {-1,-1,0,1,2,-1,-1,-1}
	vec.insert(vec.begin()+1, 10); // vec = {-1 ,10,-1,0,1,2,-1,-1,-1}
	vec.pop_back(); // vec = {-1,10,-1,0,1,2,-1,-1}
	vec.erase(vec.begin()+3); // vec = {-1,10,-1,1,2,-1,-1}
	vec.clear(); // vec = {}
	for (int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	
	return 0;
}
