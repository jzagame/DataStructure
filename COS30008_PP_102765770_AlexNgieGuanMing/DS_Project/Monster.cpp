#include "Monster.h"

Monster::Monster(string name, string script, double hp, double damage,double x,double y) :Character(name, script, hp, damage) {
	inventory = NULL;
	setPosition(x, y);
	next = nullptr;
}

Monster::~Monster() {
	inventory = NULL;
}

void Monster::add(string itemName) {
	Inventory* temp = inventory; // create temporary inventory
	int num = (1 + rand() % (4 - 1 + 1)); // random a number from 1 to 4
	if (temp == nullptr) { // if inventory is null
		inventory = new Inventory(itemName, num); // create and assign to inventory
	}
	else { // if invnetory is not empty
		while (temp != nullptr) { // loop until the pointer is null
			if (temp->getNext() == nullptr) { // next pointer is null
				break; // break while lopp
			}
			temp = temp->getNext(); // get next pointer of current pointer
		}
		Inventory* new_i = new Inventory(itemName,num); // create new inventory pointer
		temp->setNext(new_i); // set it to next of current pointer
	}

}

void Monster::setNext(Monster* temp) { // set next pointer of current mosnter
	next = temp; 
}

Monster* Monster::getNext() { // get next pointer of current mosnter
	return next;
}

Inventory* Monster::getItem() {  // set inventory of current mosnter
	return inventory;
}

void Monster::printInventory() { // print inventory detail
	Inventory* temp = inventory;
	while (temp != nullptr) {
		cout << temp->getItemName() << "-" << temp->getItemNumber() << "  ";
		if (temp->getNext() == nullptr) {
			break;
		}
		temp = temp->getNext();
	}
}

void Monster::emptyInventory() { // empty the inventory when monster die
	Inventory* temp = inventory;
	while (temp != nullptr) {
		temp->setItemNumber(0);
		if (temp->getNext() == nullptr) {
			break;
		}
		temp = temp->getNext();
	}
}