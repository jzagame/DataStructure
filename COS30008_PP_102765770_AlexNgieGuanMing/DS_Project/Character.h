#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;

typedef struct {
	double x;
	double y;
}Position;

class Character { // base class
private:
	string name; 
	string script;
	double maxHp;
	double currentHp;
	double damage;
	Position pos;
public:
	Character(string t_name,string t_script,double t_hp,double t_dmg);
	string getName();
	string getScript();
	double getMaxHp();
	double& getCurrentHp();
	double getDamage();
	Position& getPos();
	void increaseMaxHp(double temp);
	void increaseDamage(double temp);
	void setPosition(double x, double y);
	void hpDecrease(double temp);
	void characterStatus();
};