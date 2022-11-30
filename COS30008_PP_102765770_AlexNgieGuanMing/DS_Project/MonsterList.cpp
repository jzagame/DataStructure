#include "MonsterList.h"

MonsterList::MonsterList() {
	list = nullptr;
}

void MonsterList::add(Monster* temp) {
	Monster* t = list;
	if(t == nullptr){
		list = temp;
	}
	else {
		while (t != nullptr) {
			if (t->getNext() == nullptr) {
				break;
			}
			t = t->getNext();
		}
		t->setNext(temp);
	}
}

void MonsterList::printAll() {
	Monster* temp = list;
	while (temp != nullptr) {
		temp->characterStatus();
		//cout << temp->getName() << " Hp: " << temp->getCurrentHp() << "/" << temp->getMaxHp() << endl;
		cout << "Item : ["; temp->printInventory(); cout << "]" << endl;
		if (temp->getNext() == nullptr) {
			break;
		}
		temp = temp->getNext();
	}
}

Monster& MonsterList::find(string name) {
	Monster* temp = list;
	Monster* a;
	while (temp != nullptr) {
		if (temp->getName() == name) {
			a = temp;
			break;
		}
		if (temp->getNext() == nullptr) {
			break;
		}
		temp = temp->getNext();
	}
	return *temp;
}