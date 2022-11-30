#pragma once
#include "Entities.h"
#include <iostream>

using namespace std;

class Dragoon :public Entities{
private:
	string DragonType;
public:
	Dragoon();
	void Print();
};