#include "FoodList.h"

FoodList::FoodList() {
	list = nullptr;
}

void FoodList::add(Food* temp) {
	Food* f = list;
	if (f == nullptr) {
		list = temp;
	}
	else {
		while (f != nullptr) {
			if (f->getNext() == nullptr) {
				break;
			}
			f = f->getNext();
		}
		f->setNext(temp);
	}
}

Food* FoodList::getFood() {
	Food* temp = list;
	int num = rand() % (8 - 0 + 1) + 0; 
	for (int i = 0; i < num ; i++) {
		if (temp->getNext() == nullptr) {
			break;
		}
		temp = temp->getNext();
	}
	return temp;
}

void FoodList::PrintAll() {
	Food* f = list;
	while (f != nullptr) {
		cout << "Name : " << f->getName() << endl;
		cout << "Need : ";
		f->ingrediantDetail();
		if (f->getNext() == nullptr) {
			break;
		}
		f = f->getNext();
	}
}

Food* FoodList::searchIng(string temp) {
	Food* f = list;
	while (f != nullptr) {
		if (f->getName() == temp) {
			break;
		}
		f = f->getNext();
	}
	return f;
}