#include "Ingredient.h"


Ingredient::Ingredient() {
	index = 0;
	maxSize = 20;
}

string Ingredient::getName() {
	return name[index];
}


void Ingredient::operator++() {
	index++;
}
void Ingredient::operator--() {
	index--;
}

string Ingredient::operator[](int position) {
	if (position < 0 || position >= maxSize) { // if position is small than 0 or larger than max size
		return name[maxSize - 1]; // return back last index item
	}
	return name[position]; // normal return
}

bool Ingredient::operator==(Ingredient& temp)
{
	return (temp.index >= 0 && temp.index <= maxSize);
}

void Ingredient::printAll() {
	for (int i = 0; i < 20; i++) {
		cout << " | " << name[i];
	}
}