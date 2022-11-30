#include "Character.h"

Character::Character(string t_name,int t_hp,SkillNode *s) {
	Name = t_name;
	MaxHp = t_hp;
	CurrentHp = t_hp;
}

int Character::getMaxHp() {
	return MaxHp;
}

int Character::getCurrentHp() {
	return CurrentHp;
}

string Character::getName() {
	return Name;
}

void Character::setCurrentHp(int dmg) {
	CurrentHp -= dmg;
}

void Character::add(string s_temp,int s_level) { // add new skill node
	SkillNode* t_skillNode = *&skillNode; //create pointer reference of skillnode
	if (t_skillNode == nullptr) { // if skill node is empty
		skillNode = new SkillNode(s_temp, s_level); // this skill node constructor already initialize prev and next node is null
	}
	else { // if skill node exist something
		while (t_skillNode->getNextSkillNode() != NULL) { // loop until the last skill node
			t_skillNode = t_skillNode->getNextSkillNode();
		}
		SkillNode* temp = new SkillNode(s_temp, s_level); // create new skill node want tp add
		temp->setPrevSkillNode(t_skillNode); // set new skill node prev skill node
		t_skillNode->setNextSkillNode(temp); // insert new skill node to the last skill node
		
	}
	cout << "\n Successfully create new skill \n" << endl;
}

void Character::remove(string s_name) {
	SkillNode* t_skillNode = *&skillNode; // create pointer refrence of skill node
	while (t_skillNode->getName() != "") { // check if not empty
		if (t_skillNode->getName() == s_name) { // check if name same with selected name
			if (t_skillNode->getNextSkillNode() == nullptr && t_skillNode->getPrevSkillNode() == nullptr) { //if current node both side (prev,next) is null
				skillNode = new SkillNode(); // skill node init to empty
			}
			else if (t_skillNode->getPrevSkillNode() == nullptr && t_skillNode->getNextSkillNode() != nullptr) { // if prev is null and next exist, first node
				t_skillNode = t_skillNode->getNextSkillNode(); // get next skill node
				t_skillNode->setPrevSkillNode(nullptr); //set this node prev is null
				skillNode = t_skillNode; // reassign to skill node, now the node become header
			}
			else { // below means selected node have previos node
				if (t_skillNode->getNextSkillNode() != nullptr) { // if next node exist
					t_skillNode->getNextSkillNode()->setPrevSkillNode(t_skillNode->getNextSkillNode()); // set current node's prev node is current node's next node 
					t_skillNode->getPrevSkillNode()->setNextSkillNode(t_skillNode->getPrevSkillNode()); // set current node's next node is current node's prev node
				}
				else { // if next node no exist , (in last node)
					t_skillNode->getPrevSkillNode()->setNextSkillNode(nullptr); 
					// set next node to nullptr , this mean current node is last node, so no need to change prev node
				}
			}
			cout << t_skillNode->getName() << " remove Successfully\n" << endl;
			read(); // print current double link-list
			break; // stop while loop and quit
			
		}
		t_skillNode = t_skillNode->getNextSkillNode(); // go to next node, if not found same skill name
	}
}

void Character::modify(string temp,string s_name, int s_level) { // modify node, parameter -> search key, new name, new level
	SkillNode* t_skillNode = *&skillNode; // copy pointer refrence of skill node
	while (t_skillNode->getName() != "") {
		if (skillNode->getName() == temp) { // if same name found
			t_skillNode->setName(s_name); // set name
			t_skillNode->setLevel(s_level); // set level
			cout << "Amend Data Successfully\n" << endl;
			break;
		}
		t_skillNode = t_skillNode->getNextSkillNode();
	}
}


void Character::find(string s_name) { // find node by search key
	SkillNode* t_skillNode = *&skillNode; // create pointer refrence of skill node
	bool x = true; // check whether it found or not, found == false, not found == true
	while (t_skillNode->getName() != "") { 
		if (t_skillNode->getName() == s_name) {
			t_skillNode->printDetail(); // print node detail
			cout << "Skill Found \n" << endl;
			x = false; // set flag to false
			break; // stop while loop and quit
		}
		if (t_skillNode->getNextSkillNode() == nullptr) { // if next node is null
			break; // break while loop
		}
		t_skillNode = t_skillNode->getNextSkillNode(); // go to next skill node
	}
	if (x) { // if flag is true , print message 
		cout << "Skill Not Found \n" << endl;
	}
}

void Character::read() {
	SkillNode* t_skillNode = *&skillNode;
	while (t_skillNode->getName() != "") {
		cout << t_skillNode->getName();
		if (t_skillNode->getNextSkillNode() == nullptr) {
			cout << "\n";
			break;
		}
		cout << " -> ";
		t_skillNode = t_skillNode->getNextSkillNode();
	}
}

void Character::PrintAllSkill() {
	SkillNode* t_skillNode = *&skillNode;
	int i = 1;
	while (t_skillNode->getName() != "") {
		cout << i << ". " << t_skillNode->getName() << endl;
		if (t_skillNode->getNextSkillNode() == nullptr) {
			cout << "\n";
			break;
		}
		i++;
		t_skillNode = t_skillNode->getNextSkillNode();
	}
}