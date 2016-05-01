#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class CPoint {
    int x, y;
public:
    //this is hidden in setPt() and Print()
    void setPt(int c, int d) { x=c; y=d; } 
    //void setPt(int x, int y) { this->x=x; this->y=y; } 
    //[Q] What's wrong? 
	//void setPt(int a, int b) { *this.x=a; *this.y=b; } 
   
    void Print() { cout << x << " " << y << endl; }
    //void Print() { cout << this->x << " " << this->y << endl; }
    CPoint offset(int diff) {  
        x += diff; y += diff;
        return *this;
    }
};

int main() {

	//part 1
	CPoint p, q;
	int x=3, y=5; 
	p.setPt(x,y);
	cout << "p: "; p.Print(); //cout << " address = " << &p << " " << endl; 
	
	//part 2
	q = p.offset(3); //cout << "q address = " << &q << " " << endl; 
	cout << "q: "; q.Print(); //cout << " address = " << &q << " " << endl; 
	cout << "p: "; p.Print(); //cout << " address = " << &p << " " << endl; 
	
	system("Pause");
	return 0;
}

