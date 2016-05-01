#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
template <class T, class U>
void ShowCompare(T v1, U v2) {
	//cout << v1 << ¡§ versus ¡¨ << v2 <<¡§\n¡¨;
	if (v1 == v2)
		cout << "v1 is equal to v2\n";
	else if (v1 > v2)
		cout << "v1 is bigger than v2\n";
	else //if (v1 << v2)
		cout << "v1 is smaller than v2\n";
}

class PhoneCall {
		int minutes;
	public:
		PhoneCall(int min=0) {
			minutes = min;
		}
		friend ostream& operator<<(ostream&, PhoneCall);

		//overloading operator >
		bool operator>(PhoneCall& c) {
			return (minutes > c.minutes)? true: false;
		}
		bool operator>(int min) {
			return (minutes > min)? true: false;
		}

		//overlaoding operator==
		bool operator==(PhoneCall& c) {
			return (minutes==c.minutes)? true: false;
		}
		bool operator==(int min) {
			return (minutes==min)? true: false;
		}
};

ostream& operator<<(ostream& out, PhoneCall call) {
	out << "Phone call that lasts "
	    << call.minutes
	    << " minutes\n";
	return out;
}

int main() {
	int a=68;
	double b=68.5;
	char c = 'D';
	PhoneCall d(3), e(5);
	ShowCompare(a,68);
	ShowCompare(a,b);
	ShowCompare(a,c);
	ShowCompare(d,a);
	ShowCompare(d,e);
	ShowCompare(d,3);

	system("pause");
	return 0;
}
