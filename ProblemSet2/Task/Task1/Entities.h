#pragma once
#include <iostream>
#include <string>
#include <vector>  
#include <sstream> 
#include <cmath>
#include "Iterator1D.h"
#include "Iterator2D.h"

using namespace std;

class Entities {
private:
	int fEntityID;
	string fName;
	double fHP;
	Iterator1D *i1;
	Iterator2D *i2;
	double fCurrentHP;
	string fMessage;

public:
	Entities(); // constructor of entities
	~Entities(); // destructor of entity
	int getfEntityID(); // getter of entity id
	void setfEntityID(int temp);// setter of entity id
	string getfName(); // getter of entity name
	void setfName(string temp); // setter of entity name
	string getfMessage();
	double getfCurrentHP();
	void grab(Iterator1D &temp); //store Itertor in entities class
	void grab(Iterator2D &temp); //store Itertor in entities class
	void InventoryNext(Iterator1D temp); // Move Itertor1D to next index
	void InventoryNext(Iterator2D temp);// Move Itertor2D to next index
	void InventoryPrev(Iterator1D& temp); // Move Itertor1D to previous index
	void InventoryPrev(Iterator2D& temp);// Move Itertor2D to previous index
	const string& InventoryGet(int temp); // get current index item
	void ReceiveItem(Entities& temp,Iterator1D temp_1); // player 2 receive item from player 1
	void ReceiveItem(Entities& temp, Iterator2D temp_1);// player 1 receive item from player 2
	void RemoveItem(Iterator2D temp_1); // player 2 remove item
	void RemoveItem(Iterator1D temp_1); // player 1 remove item
	void Print(Iterator1D); // print current item iterator1D class have
	void Print(Iterator2D); // print current item iterator2D class have

	friend istream& operator>>(istream& ist,Entities& object);
	//friend ostream& operator<<(ostream& ost,const Entities& object);
};