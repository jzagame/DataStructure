#pragma once
#include <iostream>
#include <string>
#include "item.h"
using namespace std;

class dungeon {
private:
	string name;
	item* ii;
	dungeon* left;
	dungeon* right;
	int dmg;
public:
	dungeon(string temp, item* temp1,int temp2);
	string getName();
	int getDmg();
	item* getItem();
	void setLeft(dungeon* temp);
	void setRight(dungeon* temp);
	dungeon* getLeft();
	dungeon* getRight();
	void complete();
	void inorderTraversal(dungeon* node);
};