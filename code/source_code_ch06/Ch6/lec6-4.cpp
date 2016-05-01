#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class CStu {
		int sid;
		string name;
		double gpa;
		friend ostream& operator<<(ostream&, CStu);
		friend istream& operator>>(istream&, CStu&);
};

ostream& operator<<(ostream& out, CStu s) {
	out << s.sid << " " << s.name << " "
	    << s.gpa << endl;
	return out;
}
istream& operator>>(istream& in, CStu& s) {
	in >> s.sid >> s.name >> s.gpa;
	return in;
}

int main() {
	CStu a;
	ofstream out;
	out.open("out6-4.txt");
	cout << "Enter id, name, and gpa\n";
	while (cin >> a) {
		out << a;
		cout << "Enter id, name, and gpa\n";
	}
	out.close();
	return 0;

	system("Pause");
	return 0;
}

