#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class comp {
public: 
	  bool operator() (int x, int y) { 
        return x<y; 
    }  	
};
int main(){
	vector<int> iv;
	for (int i = 40; i>=0; --i)
	   iv.push_back(i);
	vector <int>::iterator i;
	for (i=iv.begin(); i!=iv.end(); i++)
		cout << *i << " ";
	cout << endl << endl;
	sort( iv.begin(), iv.end(), comp());
	for (i=iv.begin(); i!=iv.end(); i++)
		cout << *i << " ";
	cout << endl << endl;
	
	
	system("pause");
	return 0;
}
