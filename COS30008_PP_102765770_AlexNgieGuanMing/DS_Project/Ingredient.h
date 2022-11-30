#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ingredient {
private:
	string name[20] = { "meat","vegetable","tomato","noodles","rice","oil","salt","sugar","chili","milk","water",
		"pork","egg","soy sauce","fish","cucumber","strawberry","pumpkin","apple","orange" };;
	int index;
	int maxSize;
public:
	Ingredient();
	string getName();
	void operator++();
	void operator--();
	string operator[](int position);
	bool operator==(Ingredient& temp);
	void printAll(); // extra function to prove array is work 
};
