#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> ignore; //words to ignore
    map<string, int> freq;
    //map of words and their frequencies
    string word; //used to hold input word

     //-- read file of words to ignore.
    ifstream ignoreFile("ignore-list.txt");
    while (ignoreFile >> word) {
        ignore.insert(word); 
        //insert word to set ignore 
    }
    //-- count from input stream.
    while ((cin >> word)&&(word != "exit")) {
        if (ignore.find(word)==ignore.end())
            freq[word]++; //update map freq 
    }
     //-- write word(key)/count as a pair
    map<string, int>::const_iterator iter;
    for (iter = freq.begin(); iter != freq.end();  ++iter) {
//        cout << (*iter).first << " " << (*iter).second << endl;
		cout << iter->first << " " << iter->second << endl;
        //itr mani. using first & second
    }

	system("pause");
	return 0;
}
