#include "SkillList.h"

SkillList::SkillList() {
	head = NULL;
	tail = NULL;
	skillNode = NULL;
}

void SkillList::addback(string s_temp, int s_level) { // add new skill node
	SkillNode* current_tail = *&tail; //create pointer reference of skillnode
	if (current_tail == nullptr) { // if skill node is empty
		skillNode = new SkillNode(s_temp, s_level); // this skill node constructor already initialize prev and next node is null
		head = *&skillNode;// become pointer refrence of skill node
		tail = *&skillNode;// become pointer refrence of skill node
	}
	else { // if skill node exist something
		SkillNode* temp = new SkillNode(s_temp, s_level); // create new skill node want tp add
		temp->setPrevSkillNode(current_tail); // set previous node(new node) is current tail
		current_tail->setNextSkillNode(temp); // set current tail next node is new node
		tail = temp; // new node become tail
	}
	cout << "\n Successfully add new skill at back\n" << endl;
}

void SkillList::addfront(string s_temp, int s_level) {
	SkillNode* current_head = *&head; //create pointer reference of skillnode
	if (current_head == nullptr) { // if skill node is empty
		skillNode = new SkillNode(s_temp, s_level); // this skill node constructor already initialize prev and next node is null
		head = *&skillNode; // become pointer refrence of skill node
		tail = *&skillNode; // become pointer refrence of skill node
	}
	else { // if skill node exist something
		SkillNode* temp = new SkillNode(s_temp, s_level); // create new skill node want to add
		temp->setNextSkillNode(current_head); // set next skill node(new node) is current head
		current_head->setPrevSkillNode(temp); // set current head prev skill node is new skill node
		head = temp; // new skill node become head
	}
	cout << "\n Successfully add new skill at front\n" << endl;
}

void SkillList::removefront() {
	SkillNode* current_head = *&head; // get current head
	if (current_head->getNextSkillNode() != nullptr) { // when more that 2 node
		SkillNode* temp = current_head->getNextSkillNode(); //save current head next node to temp
		temp->setPrevSkillNode(nullptr); // set temp previous node to null
		head = temp; // temp become head
	}
	else { // only 1 node
		skillNode = nullptr;
		head = nullptr;
		tail = nullptr;
	}
}

void SkillList::removeback() {// when more that 2 node
	SkillNode* current_tail = *&tail; // get current tail
	if (current_tail->getPrevSkillNode() != nullptr) {// when more that 2 node
		SkillNode* temp = current_tail->getPrevSkillNode(); // save current tail prev node to temp
		temp->setNextSkillNode(nullptr); // set temp next node to null
		tail = temp; // temp become tail
	}
	else {// only 1 node
		skillNode = nullptr;
		head = nullptr;
		tail = nullptr;
	}
}

void SkillList::modify(string temp, string s_name, int s_level) { // modify node, parameter -> search key, new name, new level
	SkillNode* t_skillNode = *&skillNode; // copy pointer refrence 
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


void SkillList::find(string s_name) { // find node by search key
	SkillNode* t_skillNode = *&head; // create pointer refrence of head
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

void SkillList::read() {
	SkillNode* t_skillNode = *&head;
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

void SkillList::PrintFromTail() {
	SkillNode* temp_tail = *&tail;
	while (temp_tail->getName() != "") {
		cout << temp_tail->getName();
		if (temp_tail->getPrevSkillNode() == nullptr) {
			cout << "\n";
			break;
		}
		cout << " -> ";
		temp_tail = temp_tail->getPrevSkillNode();
	}
}

void SkillList::PrintFromHead() {
	SkillNode* temp_head = *&head;
	while (temp_head->getName() != "") {
		cout << temp_head->getName();
		if (temp_head->getNextSkillNode() == nullptr) {
			cout << "\n";
			break;
		}
		cout << " -> ";
		temp_head = temp_head->getNextSkillNode();
	}
}
