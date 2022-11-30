#pragma once
#include <iostream>
#include <string>

using namespace std;

class Inventory { // single link list
private:
	string itemName;
	int itemNumber;
	Inventory* next;
public:
	Inventory(string t_itemName,int t_itemNumber);
	Inventory* getNext();
	int& getItemNumber();
	string getItemName();
	void setNext(Inventory* temp);
	void setItemName(string temp);
	void setItemNumber(int temp);
};
