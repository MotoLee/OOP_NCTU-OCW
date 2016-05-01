#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class CScore {
	char * name;
	int score[3];
public:
	int gender;
	double computeAverage();
	CScore();
	CScore(char * inName, int * sary);
}; 

CScore::CScore()
{
	name = NULL; gender = 0;
	for (int i=0; i<3; ++i)
		score[i] = 0;		
}
CScore::CScore(char * inName, int * sary)
{
	name = new char[strlen(inName)+1]; gender = 0;
	strcpy(name, inName);
	for (int i=0; i<3; ++i)
		score[i] = sary[i];		
}

double CScore::computeAverage()
{
	return (score[0]+score[1]+score[2])/3.0;
}

int main() {
	CScore * StuAry = new CScore [3]; 
	int ia0[3] = {43,62,85}; StuAry[0] = CScore("Adam", ia0);
	int ia1[3] = {72,82,23}; StuAry[1] = CScore("Bill", ia1);
	int ia2[3] = {31,53,76}; StuAry[2] = CScore("Nick", ia2);
	//part 1
	cout << "part 1: " << endl;
	double sum = 0;
	for (int i=0; i<3; i++) {
    	sum += StuAry[i].computeAverage();
	}
	cout << sum/3.0 << endl;
	
	//part 2
	cout << "part 2: " << endl;
	CScore * p1 = &StuAry[2];
	cout << p1->computeAverage() << endl;
	double (CScore::* p2)() = &CScore::computeAverage;
	//[Q] what if? double (CScore::* p2)() = &(StuAry[0].computeAverage);
	cout << (p1->*p2)() << endl;

	//part 3
	int (CScore::* ps1) = &CScore::gender; 
	//[Q] what if? int (CScore::* ps1) = &CScore::score[0];
	cout << p1->*ps1 << endl;
	
	system("Pause");
	return 0;
}

