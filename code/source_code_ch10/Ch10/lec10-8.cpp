#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T, int MAXSIZE>
class CStack {
		T elems[MAXSIZE];
		int top;
	public:
		CStack() {
			top=0;
		}
		bool empty() {
			return (top==0);
		}
		bool full() {
			return (top==MAXSIZE);
		}
		void push(T e) {
			if (top==MAXSIZE) {
				cout << "full";
				return;
			}
			elems[top++] = e;
		}
		T pop() {
			if (top<=0) {
				cout << "empty";
				exit(-1);
			}
			top--;
			return elems[top];
		}
};

template <class T, int MAXSIZE>
void ShowStack(CStack<T,MAXSIZE> &s) {
	while (!s.empty())
		cout << s.pop();
	cout << endl;
}

int main() {
	CStack<int, 25> cs1;
	for (int idx=1; idx<10; ++idx)
		cs1.push(idx);
	ShowStack(cs1);

	CStack<char, 10> cs2;
	for (int jdx=65; jdx<70; ++jdx)
		cs2.push(jdx);
	ShowStack(cs2);

	system("pause");
	return 0;
}
