#include "item.h"

Item::Item(string in) {
	ItemName = in;
}
void Item::setValue(string s, string l, string h) {
	if(s == "Armor") {
		ArmorLow = stoi(l);
		ArmorHigh = stoi(h);
	} else if(s == "Damage") {
		DamageLow = stoi(l);
		DamageHigh = stoi(h);
	} else {
		cout<<"Error: string = "<<s<<endl;
	}
}
bool Item::compareName(string s) {
//	cout<<"** equipment = "<<s<<", ItemName = "<<ItemName<<endl;
	return (s == ItemName) ? true : false;
}

Character::Character(string n) {
	name = n;
}
void Character::addData(Item* i) {
//	cout<<"name = "<<name<<", i->ItemName = "<<i->ItemName<<endl;
	ArmorLow += i->ArmorLow;
	ArmorHigh += i->ArmorHigh;
	DamageLow += i->DamageLow;
	DamageHigh += i->DamageHigh;
}

