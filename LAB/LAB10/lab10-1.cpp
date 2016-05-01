//lab10-1.cpp
#include <iostream>
class B {
	private:
		int i;
	protected:
		float f;
	public:
		B() { i = 0; f = 0.0; d = 0.0; }
		double d;
		void g1(B b) { f = b.f; }
};
//class X: public B {
class X: protected B {
	protected:
		short s;
	public:
		X() { s = 0; }
		void g2(X x) { f = x.f; }
		void g3(B b) { f = b.f;	} //comment
};
int main() {
	B b1;
	X x1;
	x1.g1(b1);
	return 0;
}
