#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;


class Item {
//	friend class Character;
	private:
	public:
		string ItemName;
		int ArmorLow = 0, ArmorHigh = 0;
		int DamageLow = 0, DamageHigh = 0;

	public:
		Item* Next = NULL;
		Item(string in);
		Item();
		~Item();
		void setValue(string s, string l, string h);
		bool compareName(string s);
};
class Character {
	private:
		string name;
		string equipment;
		int ArmorLow = 0, ArmorHigh = 0;
		int DamageLow = 0, DamageHigh = 0;

	public:
		Character* Next = NULL;
		Character(string n);
		Character();
		~Character();
		void showData() {
			cout<<name<<"\t Damage:"<<DamageLow<<"-"<<DamageHigh<<"\t Armor:"<<ArmorLow<<"-"<<ArmorHigh<<endl;
		}
		void addData(Item* i);		// mappping string to values
};
