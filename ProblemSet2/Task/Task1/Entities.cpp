#include "Entities.h"
#include <string.h>

Entities::Entities() {
	fName = "";
	fEntityID = 0;
	fHP = 200;
	fCurrentHP = 200;
}

Entities::~Entities() {
	cout << "Destructor Work" << endl;
}

int Entities::getfEntityID() {
	return fEntityID;
}

string Entities::getfName() {
	return fName;
}

void Entities::setfEntityID(int temp) {
	fEntityID = temp;
}

void Entities::setfName(string temp) {
	fName = temp;
}

string Entities::getfMessage() {
	return fMessage;
}

double Entities::getfCurrentHP() {
	return fCurrentHP;
}

istream& operator>>(istream& ist, Entities& object) {
	vector<string> splitString; // create an vector to store array
	string temp; // create varaible to store input command temporary
	istringstream iss; // split string into word
	cout << "\nEnter (Exit - quit , increase current HP - HEAL 20) : " << endl;
	getline(ist, temp); // read command
	if (temp.compare("EXIT") == 0) { // if input is EXIT
		object.fMessage = temp; // store full command into fmessage
	}
	else {
		iss.str(temp); // split string into word
		for (string s; iss >> s;) { // for loop until the end of the array in iss
			splitString.push_back(s); // push word splited by iss into splitString(vector)
		}
		object.fCurrentHP += stod(splitString[1]); // add up current hp and heal hp
		object.fMessage = temp; // store full command into fmessage
	}
	
	return ist;
}

void Entities::grab(Iterator1D &temp) { // set iterator1D item
	i1 = &temp;
}
void Entities::grab(Iterator2D &temp) {
	i2 = &temp;
} // set iterator2D item

void Entities::InventoryNext(Iterator1D temp) {
	if (temp.operator==(i1->operator++()) == 0) { // if max of the index, stop moving and move backward 1 time to make sure always in the last index
		i1->operator--();
	}

}

void Entities::InventoryNext(Iterator2D temp) {
	if (temp.operator==(i2->operator++()) == 0) { // if max of the index, stop moving and move backward 1 time to make sure always in the last index
		i2->operator--();
	}
}

void Entities::InventoryPrev(Iterator1D& temp) {
	if (temp.operator==(i1->operator--()) == 0) { // // if min of the index, stop moving and move toward 1 time to make sure always in the first index
		i1->operator++();
	}
}

void Entities::InventoryPrev(Iterator2D& temp) {
	if (temp.operator==(i2->operator--()) == 0) { // // if min of the index, stop moving and move toward 1 time to make sure always in the first index
		i2->operator++();
	}
}

const string& Entities::InventoryGet(int temp) { // get current item of the index in Iterator class, 1 is iterator1D otherwise is Iterator 2D
	if (temp == 1) {
		return i1->operator*();
	}
	else {
		return i2->operator*();
	}
}


void Entities::ReceiveItem(Entities &temp, Iterator1D temp_1) { 
	i1->initialize();
	while (temp_1.operator==(*i1)) {
		if (i1->operator*() == "empty") {
			i1->setItem(temp.InventoryGet(2));
			break;
		}
		i1->operator++();
		if (temp_1.operator==(*i1) == 0) {
			i1->operator--();
			break;
		}
	}
}
void Entities::ReceiveItem(Entities& temp, Iterator2D temp_1) {
	i2->initialize();
	while (temp_1.operator==(*i2)) {
		if (i2->operator*() == "empty") {
			i2->setItem(temp.InventoryGet(1));
			break;
		}
		i2->operator++();
		if (temp_1.operator==(*i2) == 0) {
			i2->operator--();
			break;
		}
	}
}


void Entities::RemoveItem(Iterator2D temp_1) { // set transfered item slot to empty 
	i2->setItem("empty");
}

void Entities::RemoveItem(Iterator1D temp_1) {// set transfered item slot to empty 
	i1->setItem("empty");
}

void Entities::Print(Iterator2D temp) { // print content of iterator2D class
	i2->initialize();
	while (temp.operator==(*i2)) {
		cout << i2->operator*();
		i2->operator++();
		if (temp.operator==(*i2) == 0) {
			i2->operator--();
			cout << endl;
			break;
		}
		else {
			cout << "->";
		}
	}
}
  
void Entities::Print(Iterator1D temp) {// print content of iterator1D class
	i1->initialize();
	while (temp.operator==(*i1)) {
		cout << i1->operator*();
		i1->operator++();
		if (temp.operator==(*i1) == 0) {
			i1->operator--();
			cout << endl;
			break;
		}
		else {
			cout << "->";
		}
	}
}
