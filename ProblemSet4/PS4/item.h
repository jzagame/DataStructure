#pragma once
#include <iostream>
#include <string>

using namespace std;

class item{
private:
	string itemname;
	int num;
	item* next;
public:
	item(string temp,int temp1);
	string getItemName();
	int getNum();
	item* getNext();
	void setNext(item* temp);
	void itemFound(int temp);
	void emptyItem();
};