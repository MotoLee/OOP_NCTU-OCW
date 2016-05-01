#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class CPoint {
	friend class CLine;
    int x, y;
    friend CPoint offset(CPoint &, int);
    void Offset(int diff) {
        x += diff; y += diff; 
    }
public:    
    CPoint() { x=0; y=0; }
    CPoint(int a, int b) { x=a; y=b; }
	void set(int a, int b) { x=a; y=b; } 
    void Print() { cout << x << " " << y << endl; }
};

CPoint offset(CPoint &pt, int diff) {
    pt.x += diff; pt.y += diff; 
    return pt;
}

class CLine {
    CPoint p1, p2;
public:    
    //CLine(int x, int y, int w, int z) : p1(x,y), p2(w,z) {} //or??
    CLine(int x, int y, int w, int z) {
		p1.x = x; p1.y = y;
		p2.x = w; p2.y = z; 	
	} 
    void Print() { 
        //call public member function in 
        //class CPoint for p and q
        cout << "Point 1: "; p1.Print();  
        cout << "Point 2: "; p2.Print(); 
	} 
    void Display() { 
        offset(p1,100); //call friend func
        p2.Offset(200); //call private func in CPoint
        Print(); 
	}
};

int main() {

	//part 1
	CPoint p1(2,4); p1.Print();
	offset(p1,4); 
	//[Q] what if? p1.Offset(7);
	p1.Print();
	
	//part 2
	CLine l1(1,3,5,7), l2(2,4,6,8);
	l1.Print();
	l2.Display();
	//part 3
	
	system("Pause");
	return 0;
}

