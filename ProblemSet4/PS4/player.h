#pragma once
#include <iostream>
#include <string>
#include "item.h"
#include "Visitor.h"
#include "dungeon.h"

class Visitor;

using namespace std;

class player {
protected:
	string name;
	double hp;
	item* quest;
public:
	player();
	player(string temp1, double temp2);
	string getName();
	double getHp();
	virtual void hpDown(double temp); //minus hp
	virtual void accept(Visitor& v); //call visitor
	void setItem(item* temp);
	void playerDetails();
	item* getItem();
	void generateQuest();
	void completeQuest(item* temp);
	string completed();
	void checkQuest();
};