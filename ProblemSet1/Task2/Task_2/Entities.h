#pragma once
#include <iostream>
#include <string>
#include <vector>  
#include <sstream> 

using namespace std;

class Entities {
private:
	string fOwner;
	int fID;
	double fPosition;
	double fMaxHP;
	double fCurrentHP;
	double fMaxEnergy;
	double fCurrentEnergy;
	bool fGameState;

	string fMessage;

public:
	Entities(); // constructor
	Entities(double c_hp, double c_mp, double c_pos); //overload constructor with parameter
	~Entities(); // destructore

	//getter
	string getfOwner();
	int getfID();
	double getfPosition();
	double getfMaxHP();
	double getfCurrentHP();
	double getfMaxEnergy();
	double getfCurrentEnergy();
	bool getfGameState();

	//setter
	void setfOwner(string temp);
	void setfID(int temp);
	void setfPostion(double temp);
	void setfMaxHP(double temp);
	void setfCurrentHP(double temp);
	void setfMaxEnergy(double temp);
	void setfCurrentEnergy(double temp);
	void setfGameState(bool temp);

	void PintStatus(); // to print our player current state
	void Listen(string temp); // use to store fmessage
	void Tell(); //used to display message

	//friends
	friend istream& operator>>(istream& ist,Entities& object); // input data
	friend ostream& operator<<(ostream& ost, const Entities& object); // output data

};
