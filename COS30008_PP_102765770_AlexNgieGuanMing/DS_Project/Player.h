#pragma once
#include "Character.h"
#include "Inventory.h"
#include <Queue>
#include <dos.h>
#include "Monster.h"
#include <stack>


class Player:Character { // player class is derive class of character class
private:
	Inventory* inventory;
	double money;
	stack<int> chance; // used to store life
	
public:
	Player(string name, string script, double hp, double damage,double temp_m);
	string getMyScript();
	void add(string t_itemName, int t_itemNumber);
	void remove(string t_itemName, int t_itemNumber);
	bool validOfUse(string t_itemName, int t_itemNumber);
	void readyToUse(string t_itemName, int t_itemNumber);
	Inventory& search(string t_itemName);
	void addMoney(double temp);
	void MyInventory();
	void status();
	void StatusUpgrade(queue<string>& temp);
	bool attackMonster(Monster* monster);
	void BackToRestaurant(double x, double y);
	void BackToRestaurant(string temp);
	stack<int> getChance();
};
