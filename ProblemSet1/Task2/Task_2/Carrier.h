#pragma once
#include "Entities.h"
#include <iostream>

using namespace std;

class Carrier :public Entities{
private:
	int NumOfAircraft;
	int NumSend;
	string CarrierType;
public:
	Carrier();	
	void Print();
};