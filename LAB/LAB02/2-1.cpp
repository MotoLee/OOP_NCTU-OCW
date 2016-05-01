// ex2-1.cpp
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

// define the structure
typedef struct {
	int id;
	string name;
	int easy[3];
	int medium[3];
	int hard[3];
	int score;
	int time;
} Student;

// Declaration
void ReadTextFile(char* argv_1, Student* &list);
void EvaluationScore(Student* &list);
void PrintScore(char* argv_2, Student* &list);

// global variable
int student_num = 0;

int main(int argc, char* argv[]) {
	Student* list;
	ReadTextFile(argv[1], list);
	EvaluationScore(list);
	PrintScore(argv[2], list);
	return 0;
}

void ReadTextFile(char* argv_1, Student* &list) {

	string line;
	string* list_str;

	// count line number
	ifstream myfile(argv_1);
	if(myfile.is_open()) {
		while (getline(myfile, line) != NULL) {
			student_num++;
		}
		myfile.close();
	} else {
		cout<<"READ ERROR!"<<endl;
	}
	// read line from text file
	list_str = new string[student_num];
	student_num=0;
	ifstream myfile2(argv_1);
	if(myfile2.is_open()) {
		while (getline(myfile2, line) != NULL) {
			list_str[student_num] = line;
			cout<<"list_str["<<student_num<<"] = "<<line<<endl;
			student_num++;
		}
		myfile2.close();
	} else {
		cout<<"READ ERROR!"<<endl;
	}
	// parsing
	list = new Student[student_num];
	for(int i=0; i<student_num; i++) {
		int found = list_str[i].find(" ");
		int prev_found = found;
		// id
		list[i].id = stoi(list_str[i].substr(0, found));
//		cout<<"list["<<i<<"].id = "<<list[i].id<<endl;
		// name
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].name = list_str[i].substr(prev_found+1, found-prev_found);
//		cout<<"list["<<i<<"].name = "<<list[i].name<<endl;
		// easy
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].easy[0] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].easy[1] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].easy[2] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
//		cout<<"list["<<i<<"].easy = "<<list[i].easy[0]<<list[i].easy[1]<<list[i].easy[2]<<endl;
		// medium
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].medium[0] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].medium[1] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].medium[2] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
//		cout<<"list["<<i<<"].medium = "<<list[i].medium[0]<<list[i].medium[1]<<list[i].medium[2]<<endl;
		// hard
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].hard[0] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].hard[1] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
		prev_found = found;
		found = list_str[i].find(" ", found+1);
		list[i].hard[2] = stoi(list_str[i].substr(prev_found+1, found-prev_found));
//		cout<<"list["<<i<<"].hard = "<<list[i].hard[0]<<list[i].hard[1]<<list[i].hard[2]<<endl;
		// time
		prev_found = found;
		list[i].time = stoi(list_str[i].substr(prev_found+1));
//		cout<<"list["<<i<<"].time = "<<list[i].time<<endl;
	}

}

void EvaluationScore(Student* &list) {
	for(int i=0; i<student_num; i++) {
		// score
		list[i].score = (list[i].easy[0] + list[i].easy[1] + list[i].easy[2]) * 10 +
		                (list[i].medium[0] + list[i].medium[1] + list[i].medium[2]) * 20 +
		                (list[i].hard[0] + list[i].hard[1] + list[i].hard[2]) * 30;
		if (list[i].score>100)
			list[i].score = 100;
	}
	// sort score
	for(int i=0; i<student_num; i++) {
		for(int j=i; j<student_num; j++) {
			if ((list[i].score < list[j].score) // swap by score
			        || ((list[i].score == list[j].score) && (list[i].time > list[j].time))) {	// swap by time
				Student temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}

void PrintScore(char* argv_2, Student* &list) {
	// write files
	ofstream myfile(argv_2, ios::app);

	if(myfile.is_open()) {
		for(int i=0; i<student_num; i++) {
			cout<< list[i].id<<" "<<list[i].name<<" "<<list[i].score<<" "<<list[i].time<<endl;
			myfile<< list[i].id<<" "<<list[i].name<<" "<<list[i].score<<" "<<list[i].time<<endl;
		}
	}

}

