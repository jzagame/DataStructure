#pragma once
#include "Entities.h"
#include <iostream>

using namespace std;

class Zealot :public Entities{
private:
	string belief;
	string elements;
public:
	Zealot();
	void Print();
};