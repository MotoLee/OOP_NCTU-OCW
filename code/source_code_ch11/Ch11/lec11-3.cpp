#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
int main ()
{
    vector <int> v2(10); //size of 10
    vector <int>::const_iterator c=v2.begin();
    vector <int>::reverse_iterator r;
    int n = 0;
    for (r=v2.rbegin(); r!=v2.rend(); r++)
        *r = n++;
    for (n=0; n<10; n++)
        cout << c[n] << " ";
    cout << endl;
    
    system("pause");
    return 0;
}

