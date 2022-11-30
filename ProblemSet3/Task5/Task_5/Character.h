#pragma once
#include <iostream>
#include <string>
#include "SkillList.h"

using namespace std;

class  Character {
private:
	string Name; // store the name of player
	int MaxHp; // store the max hp of player , current hp cnt more than max hp
	int CurrentHp; // store current hp of player
	SkillList SL;
public:
	Character(string t_name, int t_hp); // constructor of character class
	int getMaxHp(); // return max hp of player
	int getCurrentHp(); // return current hp of player
	string getName(); // return name of the player
	void setCurrentHp(int dmg); // calculate current hp of player by passing income dmg
	//task 3 
	void find(string s_name); //task 3 - find skill exist or not
	void addfront(string s_temp, int s_level); // task 3 - insert node at front
	void addback(string s_temp, int s_level); // task 3 - insert node at back
	void removefront(); // task 3 - remove skill node
	void removeback(); // task 3 - remove skill node
	void read(); // task 3 - read the content of skill node
	void modify(string temp, string s_name, int s_level); // task 3 - modfify the content of skill node
	void PrintFromTail(); 
	void PrintFromHead();
};
