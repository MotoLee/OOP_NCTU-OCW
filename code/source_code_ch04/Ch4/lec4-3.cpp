#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class CScore {
	private:
		char id[6];
		char name[20];
		int  subj[3];
		static int sum[3];
		mutable int sCount;

	protected:
		static const int Max;

	public:
		const int & sc;
		CScore(char *, char *, int *);
		void showSCore() {
			cout << id << " " << name << " "
			     << subj[0] << " " << subj[1] << " "
			     << subj[2] << endl;
		}
		static void showSum() {
			cout << sum[0] << " " << sum[1] << " " << sum[2] << endl;
		}
//add more const methods
		char* getName() const {
			return (char *)name;
		}
		void setName(const char* uname) {
			strcpy(name, uname);   //not const
		}
//add more method for mutable
		void showName() const {
			cout << sCount++ << ": " << name << endl;
		}
//add method for explcit
		//CScore(const char* cstr):sc(subj[1]), sCount(0) { cout << cstr << endl; }
		explicit CScore(const char* cstr):sc(subj[1]), sCount(0) {
			cout << cstr << endl;
		}
};

CScore::CScore(char *uid, char *uname, int *uscore) :
	sc(subj[0]), sCount(22) {
	strcpy(id, uid);
	strcpy(name, uname);
	subj[0] = (uscore[0]>Max)?Max:uscore[0];
	subj[1] = (uscore[1]>Max)?Max:uscore[1];
	subj[2] = (uscore[2]>Max)?Max:uscore[2];
	sum[0] += subj[0];
	sum[1] += subj[1];
	sum[2] += subj[2];
}

const int CScore::Max = 100;
int CScore::sum[3] = {0,0,0};


int main() {

	//part 1
	int * ia1 = new int[3];
	ia1[0]=43;
	ia1[1]=62;
	ia1[2]=85;
	CScore S1("99123", "Tom", ia1);
	S1.showSCore();
	S1.showSum();
	//int ia2[3] = {72,82,23};
	int * ia2 = new int[3];
	ia2[0]=72;
	ia2[1]=82;
	ia2[2]=23;
	CScore S2("99145", "Bill", ia2);
	S2.showSCore();
	S2.showSum();

	//part 2
	cout << S1.getName() << endl; //OK!
	S1.setName("Tom Mitchell"); //OK!
	const CScore & S3 = S1;
	cout << S3.getName() << endl; //OK!
	S3.setName("Bob"); //compilation error!

	//part 3
	S1.showName();
	S2.showName();
	S3.showName();

	//part 4
	//CScore S4 = "Chuck";
	CScore S4("Chuck");

	system("Pause");
	return 0;
}

