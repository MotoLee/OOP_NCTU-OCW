// Ex6-1.cpp
#include<iostream>
using namespace std;

class classA {
	public:
		classA(int &a, int &b);
		int x, y;
};
classA::classA(int &a, int &b){
	x=a;y=b;
} 

class classB {
	public:
		classB(classA &a);
		int x, y;
};
classB::classB(classA &a){
	x=a.x;y=a.y;
} 

int main(){
	
	classB test(classA(1,2));
	
}
