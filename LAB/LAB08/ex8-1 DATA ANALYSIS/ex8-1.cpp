// ex8-1.cpp
#include "item.h"

int main() {
	// linked-list Items
	Item* item = NULL;
	Item* itemhead = NULL;

	fstream file;
	// Read Items
	file.open("ex8-1-2.txt", ios::in);
	if(file) {
		string line;
		while(file >> line) {
//			cout<<"line = "<<line<<endl;
			stringstream iss(line);
			getline(iss, line, ':');
			// get item name
			if(line == "Item") {
				file >> line;
				if(item == NULL) {
//					cout<<"Head!!"<<endl;
					item = new Item(line);
					itemhead = item;
				} else {
//					cout<<"Next!!"<<endl;
					item->Next = new Item(line);
					item = item->Next;
				}
//				cout << "item = " << item->ItemName << endl;
			}
			// get armor
			else if(line == "Armor") {
				string al, ah;
				getline(iss,al,'-');
				ah = al;
				getline(iss,ah);
				item->setValue(line,al,ah);
//				item->ArmorHigh = stoi(ah);
//				item->ArmorLow = stoi(al);
//				cout<<"al="<<item->ArmorLow<<", ah="<<item->ArmorHigh<<endl;
			}
			// get damage
			else if (line == "Damage") {
				string dl, dh;
				getline(iss,dl,'-');
				dh = dl;
				getline(iss,dh);
				item->setValue(line,dl,dh);
//				item->DamageHigh = stoi(dh);
//				item->DamageLow = stoi(dl);
//				cout<<"dl="<<item->DamageLow<<", dh="<<item->DamageHigh<<endl;
			}
		}
	} else {
		cout<<"Error: Open file (ex8-1-2.txt) error..."<<endl;
	}
	file.close();

	// Read data from txt file
	Character* list = NULL;
	Character* listhead = NULL;
	file.open("ex8-1-1.txt", ios::in);
	if(file) {
		string name, equipment;
		while(file >> name) {
			// Get name
			if(list == NULL) {
				list = new Character(name);
				listhead = list;
			} else {
				list->Next = new Character(name);
				list = list->Next;
			}
//			cout<<"name = "<<name<<endl;
			// get equipment
			getline(file, equipment);
			istringstream iss(equipment);
			while(iss >> equipment) {
//				cout<<"equipment = "<<equipment<<endl;
				// convert equipment to Armor, Damage
				item = itemhead;
				while((item==NULL)||(!(item->compareName(equipment)))) {
					item = item->Next;
				}
				list->addData(item);
			}
			list->showData();
		}
	} else {
		cout<<"Error: Open file (ex8-1-1.txt) error..."<<endl;
	}
	file.close();

	return 0;
}
