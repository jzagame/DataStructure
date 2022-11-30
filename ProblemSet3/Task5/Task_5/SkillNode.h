#pragma once
#include <iostream>
#include <string>

using namespace std;

class SkillNode {
private:
	string Name; // skill name
	int Level; // skill level
	SkillNode* next; // next node
	SkillNode* prev;// previous skill node
public:
	SkillNode(); //constructor of skill node
	SkillNode(string t_name, int t_level); // constructor of skill node with parameter
	int getLevel(); // return level
	string getName(); // return name
	SkillNode* getNextSkillNode(); // return next skill Node
	SkillNode* getPrevSkillNode(); // return prev skill Node
	void setNextSkillNode(SkillNode* temp); // set next skill node
	void setPrevSkillNode(SkillNode* temp); // set prev skill node
	void printDetail(); // print node detail
	void setLevel(int temp); // set node level
	void setName(string temp); // set node name
};
