// Evaluation.cpp
#include "Evaluation.h"

// Score
void score::setValue(string data) {
	stringstream ss(data);
	for (int i=0; i<5; i++) {
		ss>>sc[i];
	}
}
int score::getScore(int index) {
	return ((index < 5) && (index >= 0)) ? sc[index] : 0;
}

void tests::setValue(string data) {
	score::setValue(data);
}
int tests::getScore(int index) {
	return score::getScore(index);
}

void sport::setValue(string data) {
	score::setValue(data);
}
int sport::getScore(int index) {
	return score::getScore(index);
}

void evaluation::setValue(string data) {
	int* num = new int[5];
	stringstream ss(data);
	string s1, s2;
	for (int i=0; i<5; i++) {
		ss>>num[i];
		s1 = s1 + to_string(num[i]) + " ";
	}
	tests::setValue(s1);
	for (int i=0; i<5; i++) {
		ss>>num[i];
		s2 = s2 + to_string(num[i]) + " ";
	}
	sport::setValue(s2);
}
double evaluation::calculateScores() {
	// calculate avg scores
	avgScore = 0;
	for(int i=0; i<5; i++) {
		avgScore += tests::getScore(i);
	}
	avgScore = avgScore / 5;
	for(int i=0; i<5; i++) {
		avgScore += sport::getScore(i) * 5;
	}
	return avgScore;
}

// Students
student::student(string data) {
	stringstream ss(data);
	ss >> id >> name;
	getline(ss, data, '\n');
	final_score.setValue(data);
}
student::student() {
	id = 0;
}
long int student::getID() const {
	return id;
}
string student::getName() const {
	return name;
}
double student::getAvgScore() {
	return final_score.calculateScores();
}

// Schools
school::school(string in_path) {

	// Parsing data from input file
	fstream fs;
	fs.open(in_path, ios_base::in);

	if(fs) {
		// Get number of students
		string line;
		getline(fs, line,'\n');
		number = stoi(line);

		// Generate a list
		list = new student[number];

		// Parsing data
		int c = 0;
		while(getline(fs, line,'\n')) {
			// Check if number of students is correct
			if(c <= number) {
				student stu(line);
				list[c] = stu;
			} else {
				cout<<"ERROR: Number of students is not match."<<endl;
			}
			c++;
		}
		fs.close();
	}
}
void school::report(string out_path) {

	// output the calculated results
	fstream fs;
	fs.open(out_path, ios_base::out);

	if(fs) {
		double sum = 0;
		for(int i=0; i<number; i++) {
			fs << list[i].getID() << " " << list[i].getName() << " " << list[i].getAvgScore() << endl;
			cout << list[i].getID() << " " << list[i].getName() << " " << list[i].getAvgScore() << endl;
			sum += list[i].getAvgScore();
		}
		fs << "Average: " << sum/5 << endl;
		cout << "Average: " << sum/5 << endl;
	}
	fs.close();

}

