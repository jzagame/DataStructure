#include "Entities.h"


Entities::Entities() {
	cout << "Hi, IM Concstructor" << endl;
	fOwner = "Alex";
	fID = 12;
	fPosition = 30;
	fMaxHP = 100;
	fCurrentHP = 100;
	fCurrentEnergy = 100;
	fMaxEnergy = 100;
	fGameState = false;
}

Entities::Entities(double c_hp,double c_mp,double c_pos) {
	fCurrentHP = c_hp;
	fCurrentEnergy = c_mp;
	fPosition = c_pos;
	fOwner = "Benjamin";
	fID = 12;
	fMaxHP = 100;
	fMaxEnergy = 100;
	fGameState = false;
}

Entities::~Entities() {
	cout << "\nHi, IM destructor for " << endl; 
	this->PintStatus();
}

string Entities::getfOwner() {
	return fOwner;
}

int Entities::getfID() {
	return fID;
}

double Entities::getfCurrentHP() {
	return fCurrentHP;
}

double Entities::getfCurrentEnergy() {
	return fCurrentEnergy;
}

double Entities::getfMaxHP() {
	return fMaxHP;
}

double Entities::getfMaxEnergy() {
	return fMaxEnergy;
}

double Entities::getfPosition() {
	return fPosition;
}

bool Entities::getfGameState() {
	return fGameState;
}

void Entities::setfOwner(string temp) {
	fOwner = temp;
}

void Entities::setfCurrentHP(double temp) {
	fCurrentHP = temp;
}

void Entities::setfID(int temp) {
	fID = temp;
}

void Entities::setfMaxHP(double temp) {
	fMaxHP = temp;
}

void Entities::setfMaxEnergy(double temp) {
	fMaxEnergy = temp;
}

void Entities::setfCurrentEnergy(double temp) {
	fCurrentEnergy = temp;
}

void Entities::setfPostion(double temp) {
	fPosition = temp;
}

void Entities::setfGameState(bool temp) {
	fGameState = temp;
}

void Entities::PintStatus() {
	cout << "----Current State----" << endl;
	cout << "Player ID : " << fID << endl;
	cout << "Player Name : " << fOwner << endl;
	cout << "Position : " << fPosition << endl;
	cout << "HP : " << fCurrentHP << endl;
	cout << "MP : " << fCurrentEnergy << endl;
}

void Entities::Listen(string temp) {
	fMessage = temp;
}

void Entities::Tell() {
	cout << "Message : " << fMessage << endl;
}

istream& operator>>(istream& ist, Entities& object) {
	//cout << "Enter fMessage (friend Operator Overload): ";
	//getline(ist, object.fMessage);

	vector<string> splitString; // create an vector to store array
	string temp; // create varaible to store input command temporary
	istringstream iss; // split string into word

	cout << "Heal HP by command (Example : HEAl 20) : ";
	getline(ist,temp); // read command
	iss.str(temp); // split string into word
	for (string s; iss >> s;) { // for loop until the end of the array in iss
		splitString.push_back(s); // push word splited by iss into splitString(vector)
	}
	object.fMessage = temp; // store full command into fmessage
	object.fCurrentHP += stod(splitString[1]); // add up current hp and heal hp
	return ist;
}

ostream& operator<<(ostream& ost, const Entities& object) {

	ost << "Print fMessage (friend Operator Overload) : " << object.fMessage << endl;
	//ost << "Current HP : " << object.fCurrentHP << endl;
	return ost;
}
