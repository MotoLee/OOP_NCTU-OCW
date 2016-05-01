#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class score {
	private:
		int sc[5];
	public:
		void setScore(int* s);
		int getScore(int index);
};
void score::setScore(int* s) {
	for(int i=0; i<5; i++)
		sc[i] = s[i];
}
int score::getScore(int index) {
	return sc[index];
}
class student {
	private:
		string name;
		score t_score;
		score s_score;
		double final_score = 0;
	public:
		student(istream & data);
		double getFinalScore() const;
		string getName() const;
};
student::student(istream & data) {
	string tmp;
	data >> name;
	int tsc[5];
	for(int i=0; i<5; i++) {
//		cout<< "test " << i << endl;
		data >> tmp;
		tsc[i] = stoi(tmp);
	}
	int ssc[5];
	for(int i=0; i<5; i++) {
//		cout<< "test " << i << endl;
		data >> tmp;
		ssc[i] = stoi(tmp);
	}
	t_score.setScore(tsc);
	s_score.setScore(ssc);
	
	// calculate final scores
	for(int i=0; i<5; i++) {
		final_score += t_score.getScore(i);
	}
	final_score = final_score / 5;
	for(int i=0; i<5; i++) {
		final_score += s_score.getScore(i) * 5;
	}
}
double student::getFinalScore() const {
	return final_score;
}
string student::getName() const{
	return name;
}

int main(int argc, char *argv[]) {

	map<int, student> classroom;

	// Parsing data from input file
	ifstream fs(argv[1], ios::in);

	if(fs) {
		// Get number of students
		string line;
		getline(fs, line,'\n');
		int number = stoi(line);
		int id;

		// Get all students' data
		for(int i=0; i<number; i++) {
			fs >> line;
			id = stoi(line);
			student stu(fs);
			classroom.insert(pair<int, student>(id, stu));
		}
	}

	// read file and store student¡¦s information
	for (map<int,student>::const_iterator iter = classroom.begin(); iter != classroom.end(); iter++) {
		cout << "ID: " << iter->first << " ";
		cout << "name: " << (iter->second).getName() << " ";
		cout << "score: " << (iter->second).getFinalScore() << endl;
	}
	
	return 0;
}
