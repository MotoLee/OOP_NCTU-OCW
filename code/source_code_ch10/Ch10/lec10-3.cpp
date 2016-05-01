#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
//template function
template <class T>
void repeatValue(T val, int times) {
	for (int x=0; x<times; ++x) {
		cout << "#" << (x+1) << " " << val << endl;
	}
}
//class declaration
class Store {
		int  storeid;
		string address;
		string manager;
	public:
		Store(int sid, string add, string mgr) {
			storeid = sid;
			address = add;
			manager = mgr;
		}
		friend ostream& operator<<(ostream&, Store);
};

ostream& operator<<(ostream& out, Store store) {
	out << "Str:" << store.storeid << " "
	    << "Add:" << store.address << " "
	    << "Mgr:" << store.manager ;
	return out;
}

int main() {
	double a=3.0;
	char b='B';
	string c="good";
	Store d(113, "23 Ave. Q", "Jacky");
	repeatValue(a, 3);
	repeatValue(b, 2);
	repeatValue(c, 4);
	repeatValue(d, 2);

	system("pause");
	return 0;
}
