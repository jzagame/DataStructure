#pragma once
#include <iostream>
#include <string>
#include "SkillNode.h"

using namespace std;

class SkillList {
private:
	SkillNode* skillNode;
	SkillNode* head;
	SkillNode* tail;
public:
	SkillList();
	~SkillList();
	void find(string s_name); //task 5 - find skill exist or not
	void addfront(string s_temp, int s_level); // task 5 - add new skill node at first
	void addback(string s_temp, int s_level); // task 5 - add new skill node at last
	void removefront(); // task 5 - remove frsit skill node
	void removeback(); // task 5 - remove last skill node
	void read(); // task 5 - read the content of skill node
	void modify(string temp, string s_name, int s_level); // task 3 - modfify the content of skill node
	void PrintFromTail(); // 
	void PrintFromHead();
};