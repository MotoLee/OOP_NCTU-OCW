#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T>
T FindMax(T x, T y) {
	T max = x;
	if (y > max) max = y;
	return max;
}

template <class T>
T FindMax(T x, T y, T z) {
	T max = x;
	if (y > max) max = y;
	if (z > max) max = z;
	return max;
}

class PhoneCall {
		int minutes;
	public:
		PhoneCall(int min=0) {
			minutes = min;
		}
		bool operator>(PhoneCall&);
		friend ostream& operator<<(ostream&, PhoneCall);
};
bool PhoneCall::operator>(PhoneCall& call) {
	bool isTrue = false;
	if (minutes > call.minutes)
		isTrue = true;
	return isTrue;
}

ostream& operator<<(ostream& out, PhoneCall call) {
	out << "Phone call that lasts "
	    << call.minutes
	    << " minutes\n";
	return out;
}

int main() {
	int a;
	double b;
	int x1=1, x2=2, x3=3, x;
	double y1=3.3, y2=2.2, y3=1.1, y;
	//call FindMax with 2 and 3 integers
	cout << FindMax(x1, x2) << " versus "
	     << FindMax(x1, x2, x3) << endl;
	//call FindMax with 2 and 3 doubles
	cout << FindMax(y1, y2) << " versus "
	     << FindMax(y1, y2, y3) << endl;

	system("pause");
	return 0;
}


