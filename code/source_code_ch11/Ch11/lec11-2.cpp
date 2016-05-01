#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main(){

	vector<string> vec;
	copy( istream_iterator<string>(cin),         
          istream_iterator<string>(),
    	  back_inserter(vec) );
    	  
	sort( vec.begin(), vec.end() );
	unique_copy( vec.begin(),vec.end(),	ostream_iterator<string> (cout,"\n") );
	
	system("pause");
	return 0;
}
