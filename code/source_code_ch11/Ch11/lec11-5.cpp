#include <cstdlib>
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

int main(){
    set<char> s;
    s.insert('A');
    s.insert('D');
    s.insert('D'); //2nd insertion of ．D・
    s.insert('C');
    s.insert('C'); //2nd insertion of ．C・
    s.insert('B');
// in main()    
    cout << "The set contains: ";
	  set<char>::const_iterator p;
    for (p=s.begin( ); p!=s.end( ); p++)
        cout << *p << " "; //itr. mani.
    cout<< "\nRemoving C" << endl;
    s.erase('C'); //direct mani.
    for (p=s.begin( ); p!=s.end( ); p++)
        cout << *p << " ";
    cout << endl;
    
    
    system("pause");
	return 0;
}
