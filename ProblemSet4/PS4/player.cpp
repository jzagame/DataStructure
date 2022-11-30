#include "player.h"

player::player() {
	name = "";
	hp = 0;
}

player::player(string temp1, double temp2) {
	name = temp1;
	hp = temp2;
}

string player::getName() {
	return name;
}

double player::getHp() {
	return hp;
}

void player::hpDown(double down) { // descrese hp
	hp -= down;
}

void player::accept(Visitor& v) { //call visitor
	v.Visit(*this);
}


void player::playerDetails() {
	cout << "\nName  : " << name << endl;
	cout << "Hp    : " << hp << endl;
}

void player::setItem(item* temp) {
	item* i = quest;
	if (i == nullptr) {
		quest = temp;
	}
	else {
		while (i != nullptr) {
			if (i->getNext() == nullptr) {
				break;
			}
			i = i->getNext();
		}
		i->setNext(temp);
	}
}

item* player::getItem() {
	return quest;
}


void player::generateQuest() {
	item* ib = new item("itemb", 3);
	item* id = new item("itemd", 2);
	item* ie = new item("iteme", 2);
	item* ih = new item("itemh", 2);
	quest = ib;
	ib->setNext(id);
	id->setNext(ie);
	ie->setNext(ih);
}

void player::completeQuest(item* temp) {
	item* xx = quest;
	while (xx != nullptr) {
		if (xx->getItemName() == temp->getItemName()) {
			cout << "Player get Item : " << xx->getItemName() << " | Item number : " << xx->getNum() << endl;
			xx->itemFound(temp->getNum());
			break;
		}
		if (xx->getNext() == nullptr) {
			cout << "Player quest dont need this item" << endl;
			break;
		}
		xx = xx->getNext();
	}
	
}

string player::completed() {
	string x = "exit";
	item* xx = quest;
	while (xx != nullptr) {
		if (xx->getNum() > 0) {
			x = " ";
			break;
		}
		if (xx->getNext() == nullptr) {
			cout << "\nPlayer quest dont need this item" << endl;
			break;
		}
		xx = xx->getNext();
	}
	return x;
}

void player::checkQuest() {
	item* x = quest;
	while (x != nullptr) {
		cout << "Quest Item : " << x->getItemName() << " Need : " << x->getNum() << endl;
		if (x->getNext() == nullptr) {
			break;
		}
		x = x->getNext();
	}
}