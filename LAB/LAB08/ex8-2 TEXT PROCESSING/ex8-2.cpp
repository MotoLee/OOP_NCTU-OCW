#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class CWord {
	private:
		string str;
		int length;

	public:
		static int num;		
		CWord* Next = NULL;	
			
		CWord(string s, int l){ str = s; length = l; }
		CWord();
		~CWord();
		int getLength(){ return length;	}
		string getString(){ return str;	}
};
int CWord::num = 0;

int main() {

	CWord* article = NULL;
	CWord* article_head = NULL;
	fstream fs;
	
	fs.open("ex8-2.txt", ios::in);	
	if(fs) {
		string line;
		while(fs >> line) {
			// Check if word is available
			int c = (int) line.at(0);
			int len = line.length();
			if(!(c>=48 && c<=57) &&	// number 0 - 9
			        !(c>=65 && c<=90) &&	// A to Z
			        !(c>=97 && c<=122)) {	// a to z
				line.erase(len-1, 1);
				len = line.length();
			}
			// Create new element
			if (article == NULL) {
				article = new CWord(line, len);
				article_head = article;
			} else {
				article->Next = new CWord(line, len);
				article = article->Next;
			}
			// Set value			
			article->num++;
		}
	}
	fs.close();

	// find longest
	article = article_head;
	string longest;
	int longestlen = 0;
	while(article != NULL) {
		if (article->getLength() >= longestlen) {
			longestlen = article->getLength();
			longest = article->getString();
		}
		article = article->Next;
	}

	fs.open("ex8-2-out.txt", ios::out);
	cout << "The number of words read is " << article_head->num << endl;
	cout << "The longest word has a length of "<< longestlen << endl;
	cout << "The longest word is " << longest << endl;
	fs.close();

	return 0;
}
