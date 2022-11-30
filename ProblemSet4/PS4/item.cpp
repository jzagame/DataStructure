#include "item.h"

item::item(string temp,int temp1) {
	itemname = temp;
	num = temp1;
	next = nullptr;
}

string item::getItemName() {
	return itemname;
}

item* item::getNext() {
	return next;
}

void item::setNext(item* temp) {
	next = temp;
}

int item::getNum() {
	return num;
}

void item::emptyItem() {
	num = 0;
}

void item::itemFound(int temp) {
	if (num - temp <= 0) {
		num = 0;
	}
	else {
		num -= temp;
	}
}