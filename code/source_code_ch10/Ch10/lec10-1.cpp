#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T>
T FindMax(T x, T y, T z) {
	T max = x;
	if (y > max)
		max = y;
	if (z > max)
		max = z;
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
	out << "Phone call that lasts " << call.minutes << " minutes\n";
	return out;
}

int main() {
	int a;
	double b;
	PhoneCall c1(4), c2(6), c3(11), c;
	a = FindMax(3, 5, 4);
	b = FindMax(12.3, 5.9, 25.4);
	c = FindMax(c1, c2, c3);
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";

	system("pause");
	return 0;
}


