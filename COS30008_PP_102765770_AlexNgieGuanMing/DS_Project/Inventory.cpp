	#include "Inventory.h"

Inventory::Inventory(string t_itemName, int t_itemNumber) {
	itemName = t_itemName;
	next = NULL;
	itemNumber = t_itemNumber;
}

Inventory* Inventory::getNext() {
	return next;
}

string Inventory::getItemName() {
	return itemName;
}

int& Inventory::getItemNumber() {
	return itemNumber;
}

void Inventory::setItemName(string temp) {
	itemName = temp;
}

void Inventory::setItemNumber(int temp) {
	itemNumber = temp;
}

void Inventory::setNext(Inventory* temp) {
	next = temp;
}


