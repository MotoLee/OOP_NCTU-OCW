// Evaluation.h
#ifndef EVALUATION_H
#define EVALUATION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class score {
	private:
		int sc[5];
	public:
		void setValue(string data);
		int getScore(int index);
};
class tests : public score {
	public:
		void setValue(string data);
		int getScore(int index);
};
class sport : public score {
	public:
		void setValue(string data);
		int getScore(int index);
};
class evaluation : public tests, sport {
	private:
		double avgScore = 0;
	public:
		void setValue(string data);
		double calculateScores();
};

class student {
	private:
		long int id;
		string name;
		evaluation final_score;
	public:
		student(string data);
		student();
		long int getID() const;
		string getName() const;	
		double getAvgScore();
};

class school {
	private:
		student* list;
		int number = 0;
	public:
		school(string in_path);
		void report(string out_path);

};

#endif
