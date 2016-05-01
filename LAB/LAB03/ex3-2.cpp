// ex3-2.cpp
#include <iostream>
#include <cstdlib>	// rand, srand
#include <ctime>	// time

using namespace std;

// Declaration
void init();
void EnterIndex(int now, int &index1, int &index2);
bool Check(int now, int &index1, int &index2);
void ShowAnswer();

// Type definition
struct Answer {
	char alphabat[18] = {0};
	int index[18][2] = {{0}, {0}};
} answer, record;

// Variables
char Card[36] = {0};
char myCard[36] = {0};

int main() {

	// initialize random seed
	srand(time(NULL));

	// initial card desk
	init();

	// Enter index
	int index1, index2, now=0;
	while(now<18) {
		EnterIndex(now, index1, index2);
		Check(now, index1, index2);
	}

	return 0;
}

void init() {

	char alphabat[26] = {0};
	for (int i=0; i<26; i++) {
		alphabat[i] = 'A' + i;
	}

	for (int i=0, j=0, k=0; i<18; i++) {
		// choose a unique alphabat
		j = rand()%26;
		while(alphabat[j]==0) {
			j = rand()%26;
		}
		answer.alphabat[i] = alphabat[j];
		alphabat[j] = 0;
		// choose two unique index
		k = rand()%36;
		while(Card[k]!=0) {
			k = rand()%36;
		}
		Card[k] = answer.alphabat[i];
		answer.index[i][0] = k+1;
		while(Card[k]!=0) {
			k = rand()%36;
		}
		Card[k] = answer.alphabat[i];
		answer.index[i][1] = k+1;
	}

}

void EnterIndex(int now, int& index1, int& index2) {

	// Enter first index
	cout<<"Please enter Card index:";
	cin>>index1;
	// if enter 0, show the answer
	if(index1 == 0) {
		index2 = 0;
		ShowAnswer();
	}
	// index out of range
	else if((index1>36)||(index1<0)) {
		cout<<"WRONG INDEX..."<<endl;
	} else {
		// show the card desk
		for (int i=0; i<6; i++) {
			for (int j=0; j<6; j++) {
				if ((6*i+j+1 == index1) || (myCard[6*i+j]!=0)) {
					cout<<Card[6*i+j]<<" ";
				} else {
					cout<<"*"<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;

		// Enter second index
		cout<<"Please enter Card index:";
		cin>>index2;
		// if enter 0, show the answer
		if(index2 == 0) {
			index1 = 0;
			ShowAnswer();
		}
		// index out of range
		else if((index2>36)||(index2<0)) {
			cout<<"WRONG INDEX..."<<endl;
		}
		// show the card desk
		else {
			for (int i=0; i<6; i++) {
				for (int j=0; j<6; j++) {
					if ((6*i+j+1 == index1) || (6*i+j+1 == index2) || (myCard[6*i+j]!=0)) {
						cout<<Card[6*i+j]<<" ";
					} else {
						cout<<"*"<<" ";
					}
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
}

bool Check(int now, int& index1, int& index2) {
	// Not finished
	if(now < 18) {
		// Correct (index1 = index2)
		if(Card[index1-1]==Card[index2-1]) {
			cout<<"Good Job!"<<endl;
			// set myCard, record
			myCard[index1-1] = myCard[index2-1] = record.alphabat[now] = Card[index1-1];
			record.index[now][0] = index1;
			record.index[now][1] = index2;
			now++;
		} else {
			cout<<"Try Again!"<<endl;
		}
	} 
	// Finish the game
	else if(now==18) {
		cout<<"Congratulation!!"<<endl;
	}
	else{
		cout<<"ERROR..."<<endl;
	}
}

void ShowAnswer() {

	// show answer list
	cout<<"answer: "<<endl;
	for (int i=0; i<18; i++) {
		cout<<answer.alphabat[i]<<" ";
	}
	cout<<endl;
	for (int i=0; i<18; i++) {
		cout<<answer.index[i][0]<<" ";
	}
	cout<<endl;
	for (int i=0; i<18; i++) {
		cout<<answer.index[i][1]<<" ";
	}
	cout<<endl;	
//	// show record list
//	cout<<"record: "<<endl;
//	for (int i=0; i<18; i++) {
//		cout<<record.alphabat[i]<<" ";
//	}
//	cout<<endl;
//	for (int i=0; i<18; i++) {
//		cout<<record.index[i][0]<<" ";
//	}
//	cout<<endl;
//	for (int i=0; i<18; i++) {
//		cout<<record.index[i][1]<<" ";
//	}
//	cout<<endl;		
	// show the answer card desk
	cout<<"Card: "<<endl;
	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			cout<<Card[6*i+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
//	// show the card desk
//	cout<<"myCard: "<<endl;
//	for (int i=0; i<6; i++) {
//		for (int j=0; j<6; j++) {
//			cout<<myCard[6*i+j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
}
