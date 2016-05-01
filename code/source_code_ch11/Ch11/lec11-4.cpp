#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;

int FuncSquared(int a) {
    return a*a;
} 

int main ()
{
    list<int> x;
    list<int>::const_iterator c=x.begin();
    list<int>::reverse_iterator r;
//in main()
    for (int n=0; n<10; n+=3) {
        x.push_front(n); //direct mani.
        x.push_back(n+1);
    }
    for (r=x.rbegin(); r!=x.rend(); r++)
        *r = FuncSquared(*r); //itr mani.

    for (c=x.begin(); c!=x.end(); c++)
        cout << *c << " "; //itr. mani.
    cout << endl;    

	system("pause");
    return 0;
}

