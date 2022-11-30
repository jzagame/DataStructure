#pragma once
#include "Food.h"

class FoodList {
private:
	Food* list;
public:
	FoodList();
	void add(Food* temp);
	Food* getFood();
	void PrintAll();
	Food* searchIng(string temp);
};
