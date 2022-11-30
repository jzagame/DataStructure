#pragma once
#include <cstdlib>
#include "Character.h"
#include "Inventory.h"

class Monster :public Character { // monster class is derived class of character class
private:
	Inventory* inventory;
	Monster* next;
public:
	Monster(string name, string script, double hp, double damage,double x ,double y);
	~Monster();
	void add(string itemName);
	void setNext(Monster* temp);
	Monster* getNext();
	Inventory* getItem();
	void printInventory();
	void emptyInventory();
};
