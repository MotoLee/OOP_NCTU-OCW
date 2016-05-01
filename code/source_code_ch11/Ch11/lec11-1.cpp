#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector <int> v1(10);
    vector <int>::iterator i;
    int n = 0;
    for (i=v1.begin(); i!=v1.end(); i++)
        *i = n++;
    for (i=v1.begin(); i!=v1.end(); i++)
        cout << *i << " ";
    cout << endl;
    
	system("pause");
    return 0;
}

