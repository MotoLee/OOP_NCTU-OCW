#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// template class
template <class T>
class Number {
		T number;
	public:
		Number(T val) {
			number = val;
		}
		void ShowNumber() {
			cout << "Number = " << number << endl;
		}
};


int main() {
	Number<int> a(65);
	a.ShowNumber();
	Number<double> b(8.8);
	b.ShowNumber();
	Number<char> c('D');
	c.ShowNumber();
	Number<int> d('D');
	d.ShowNumber();
	Number<char> e(70);
	e.ShowNumber();

	system("pause");
	return 0;
}
