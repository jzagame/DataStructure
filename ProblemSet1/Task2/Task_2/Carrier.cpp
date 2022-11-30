#include "Carrier.h"

Carrier::Carrier() {
	NumOfAircraft = 100;
	NumSend = 20;
	CarrierType = "Type A";
}

void Carrier::Print() {
	cout << "Carrier " << CarrierType << " have " << NumOfAircraft << " aircraft and send " << NumSend << " to fight \n";
}