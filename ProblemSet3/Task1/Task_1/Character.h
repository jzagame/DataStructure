#pragma once
#include <iostream>
#include <string>
#include "SkillNode.h"


using namespace std;

class  Character {
private:
	string Name; // store the name of player
	int MaxHp; // store the max hp of player , current hp cnt more than max hp
	int CurrentHp; // store current hp of player
	//task 3
	SkillNode* skillNode; //pointerrrrrr of skill Node
public:
	Character(string t_name,int t_hp,SkillNode* s); // constructor of character class
	int getMaxHp(); // return max hp of player
	int getCurrentHp(); // return current hp of player
	string getName(); // return name of the player
	void setCurrentHp(int dmg); // calculate current hp of player by passing income dmg
	//task 3 
	void find(string s_name); //task 3 - find skill exist or not
	void add(string s_temp, int s_level); // task 3 - add new skill node
	void remove(string s_name); // task 3 - remove skill node
	void read(); // task 3 - read the content of skill node
	void modify(string temp,string s_name, int s_level); // task 3 - modfify the content of skill node
	void PrintAllSkill(); // 
};