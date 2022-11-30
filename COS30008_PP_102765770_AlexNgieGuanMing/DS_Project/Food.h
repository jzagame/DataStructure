#pragma once
#include <iostream>
#include <string>

using namespace std;

class Food {
private:
	string name;
	double cost;
	string ii;
	int total;
	Food* next;
public:
	Food(string tempName,double tempCost,string temp);
	Food* getNext();
	void setNext(Food* temp);
	void ingrediantDetail();
	string getII();
	double getCost();
	string getName();
};