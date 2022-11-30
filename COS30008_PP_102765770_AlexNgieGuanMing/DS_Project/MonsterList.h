#pragma once
#include "Monster.h"

class MonsterList {
private:
	Monster* list;
	
public:
	MonsterList();
	void add(Monster* temp);
	Monster& find(string name);
	void printAll();
};