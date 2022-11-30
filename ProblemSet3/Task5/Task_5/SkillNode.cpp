#include "SkillNode.h"

SkillNode::SkillNode() {
	Name = "";
	Level = 0;
	next = NULL;
	prev = NULL;

}

SkillNode::SkillNode(string t_name, int t_level) {
	Name = t_name;
	Level = t_level;
	next = NULL;
	prev = NULL;
}

int SkillNode::getLevel() {
	return Level;
}

string SkillNode::getName() {
	return Name;
}

void SkillNode::setLevel(int temp) {
	Level = temp;
}

void SkillNode::setName(string temp) {
	Name = temp;
}

SkillNode* SkillNode::getNextSkillNode() {
	return next;
}

SkillNode* SkillNode::getPrevSkillNode() {
	return prev;
}

void SkillNode::setNextSkillNode(SkillNode* temp) {
	next = temp;
}

void SkillNode::setPrevSkillNode(SkillNode* temp) {
	prev = temp;
}

void SkillNode::printDetail() {
	cout << "Skill Detail" << endl;
	cout << "Name : " << Name << endl;
	cout << "Level : " << Level << endl << endl;
}