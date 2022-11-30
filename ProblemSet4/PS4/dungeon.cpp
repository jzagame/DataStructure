#include "dungeon.h"

dungeon::dungeon(string temp, item* temp1,int temp2) {
	name = temp;
	ii = temp1;
	left = nullptr;
	right = nullptr;
	dmg = temp2;
}

int dungeon::getDmg() {
	return dmg;
}

void dungeon::setLeft(dungeon* temp) { 
	left = temp; 
}

void dungeon::setRight(dungeon* temp) {
	right = temp;
}

dungeon* dungeon::getLeft() {
	return left;
}

dungeon* dungeon::getRight() {
	return right;
}

void dungeon::complete() {
	ii->emptyItem();
}

void dungeon::inorderTraversal(dungeon* node) { // check tree is correct or not only
	if (node == nullptr) {
		return;
	}
	else {
		inorderTraversal(node->getLeft());
		cout << node->getName() << "->";
		inorderTraversal(node->getRight());
	}
}

item* dungeon::getItem() {
	return ii;
}

string dungeon::getName() {
	return name;
}