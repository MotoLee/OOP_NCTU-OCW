#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T>
class TBase {
private:
    T x, y;
public:
    TBase() {}	
    TBase(T a, T b) : x(a), y(b) {}
    ~TBase() {}
    T getX();
    T getY();	
};

template <class T>
T TBase<T>::getX() { return x; }
template <class T>
T TBase<T>::getY() { return y; }

class TDerived1: public TBase<int> {
private:
    int z;
public:
    TDerived1(int a, int b, int c) : TBase<int>(a,b), z(c) {}
    int getZ() { return z; }
};

template <class T>
class TDerived2 : public TBase<T> {
private:
    T z;
public:
    TDerived2(T a, T b, T c) : TBase<T>(a,b), z(c) {}
    T getZ() { return z; }
};

template <class T>
class TDerived3 : public TDerived1 {
private:
    T w;
public:
    TDerived3(int a, int b, int c, T d) : TDerived1(a,b,c), w(d) {}
    T getW() { return w; }
};


int main() 
{
 	TBase<int> c1(0,1);
 	cout << "TBase: x=" << c1.getX() << " y=" << c1.getY() << endl;
 	
 	TDerived1 c2(1,3,5);
 	cout << "TDerived1: x=" << c2.getX() << " y=" << c2.getY() << " z=" << c2.getZ() << endl;
 	
 	TDerived2<double> c3(2.2, 4.4, 6.6);
 	cout << "TDerived2: x=" << c3.getX() << " y=" << c3.getY() << " z=" << c3.getZ() << endl;
 	
 	TDerived3<int> c4(3.5, 6.5, 9.5, 12.5);
 	cout << "TDerived3: x=" << c4.getX() << " y=" << c4.getY() << " z=" << c4.getZ() << " w=" << c4.getW() << endl;
 	
	system("pause");
    return 0;	
}
