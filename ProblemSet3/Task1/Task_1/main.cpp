#include "SkillNode.h";
#include "Character.h"

string Menu() { // function of menu
	string selection;
	cout << "---Menu---" << endl;
	cout << "1. Find" << endl;
	cout << "2. Add" << endl;
	cout << "3. Remove" << endl;
	cout << "4. Read" << endl;
	cout << "5. Modify" << endl;
	cout << "Enter 'exit' to quit" << endl;
	cout << "Selection : "; getline(cin, selection);
	return selection;
}


int main() {
	Character *c;
	SkillNode* s;
	string a, b,e,d,selection;
	cout << "Enter Name : "; getline(cin, a);
	cout << "Enter MaxHP : "; getline(cin, b);

	s = new SkillNode();
	c = new Character(a, stoi(b),s);
	c->add("a", 1);
	c->add("b", 2);
	c->add("c", 3);
	while (selection != "exit") { // if selection != next, loop keep going
		selection = Menu(); // call function menu
		if (selection == "1") { // if 1 == find
			cout << "---Find skill---" << endl;
			cout << "Enter skill Name : "; getline(cin, e); // enter skill name
			c->find(e); // call find in character class and pass search key
		}
		else if (selection == "2") { // if 2 == add
			cout << "---Insert new Skill---" << endl;
			cout << "Skill Name : "; getline(cin, e); // enter skill name
			cout << "Level : "; getline(cin, d); // enter skill level
			c->add(e, stoi(d));// calll add in character cllass and pass name and level by parameter
		}
		else if (selection == "3") { // if 3 == remove
			cout << "---Remove skill---" << endl;
			c->PrintAllSkill(); // call print skill function in character class to print current skill
			cout << "Enter skill Name : "; getline(cin,e); // enter skill name wish to remove
			c->remove(e); // call remove in character class and pass search key(name) by parameter
		}
		else if (selection == "4") { // if 4 == read
			cout << "---Available Skill---" << endl;
			c->read(); // read in character class to print current link list
		}
		else if (selection == "5") { // if 5 == modiffy
			cout << "---Available skill---" << endl;
			c->PrintAllSkill(); // call print all skill in character class
			cout << "Enter Skill Name to Amend : "; getline(cin, b); // enter skill name wish to amend
			cout << "Enter New Skill Name : "; getline(cin, d); // enter new skill name
			cout << "Enter New Level : "; getline(cin, e); // enter new level
			c->modify(b, d, stoi(e)); 
			// call modify function in character class and pass, b d e , search key/new name/new level by parameter
		}
	}
	return 0;
}


