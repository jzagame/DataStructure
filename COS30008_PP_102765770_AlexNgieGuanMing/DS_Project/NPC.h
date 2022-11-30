#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Character.h"

using namespace std;

class NPC :Character{ // NPC class is derived class of character class
private:
	string order;
	NPC* next;
	NPC* prev;
public:
	NPC(string temp_order,string name,string script,double hp,double damage);
	void Status();
	string getOrder();
	void setNext(NPC* temp);
	void setPrev(NPC* temp);
	NPC* getNext();
	NPC* getPrev();
	string getNName();
};
