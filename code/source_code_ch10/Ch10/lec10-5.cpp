#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T> 
T doubleVal (T val) {
    val *= 2;
    return val;
}

int main() 
{
 	int a=6; double b=7.4;
    cout << a << " & " << doubleVal(a) << "\n";
    cout << b << " & " << doubleVal(b) << "\n";
    cout << b << " & " << doubleVal<int>(b) << "\n";

	system("pause");
    return 0;	
}
