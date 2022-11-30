#include "Food.h"

Food::Food(string tempName, double tempCost,string temp) {
	name = tempName;
	cost = tempCost;
	ii = temp;
}

Food* Food::getNext() {
	return next;
}

void Food::setNext(Food* temp) {
	next = temp;
}

void Food::ingrediantDetail() {
	cout << ii << endl;
}
string Food::getName() {
	return name;
}

string Food::getII() {
	return ii;
}

double Food::getCost() {
	return cost;
}