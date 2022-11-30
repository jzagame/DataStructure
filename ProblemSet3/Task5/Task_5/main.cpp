#include "Character.h"
#include "SkillList.h"

string Menu() { // function of menu
	string selection;
	cout << "---Menu---" << endl;
	cout << "1. Find" << endl;
	cout << "2. Add head" << endl;
	cout << "3. Add tail" << endl;
	cout << "4. Remove head" << endl;
	cout << "5. Remove Tail" << endl;
	cout << "6. Read" << endl;
	cout << "7. Modify" << endl;
	cout << "Enter 'exit' to quit" << endl;
	cout << "Selection : "; getline(cin, selection);
	return selection;
}


int main() {
	Character* c;
	SkillNode* s;
	string a, b, e, d, selection;
	cout << "Enter Name : "; getline(cin, a);
	cout << "Enter MaxHP : "; getline(cin, b);

	s = new SkillNode();
	c = new Character(a, stoi(b));
	c->addback("a", 1);
	c->addback("b", 2);
	c->addback("c", 3);
	c->addfront("d",3);
	c->addfront("e", 3);
	c->addfront("f", 3);
	while (selection != "exit") { // if selection != next, loop keep going
		selection = Menu(); // call function menu
		if (selection == "1") { // if 1 == find
			cout << "---Find skill---" << endl;
			cout << "Enter skill Name : "; getline(cin, e); // enter skill name
			c->find(e); // call find in character class and pass search key
		}
		else if (selection == "2") { // if 2 == add front
			cout << "---Insert new Skill(Head)---" << endl;
			cout << "Skill Name : "; getline(cin, e); // enter skill name
			cout << "Level : "; getline(cin, d); // enter skill level
			c->addfront(e, stoi(d));// calll addfront in character cllass and pass name and level by parameter
		}
		else if (selection == "3") { // if 3 == add back
			cout << "---Insert new Skill(Tail)---" << endl;
			cout << "Skill Name : "; getline(cin, e); // enter skill name
			cout << "Level : "; getline(cin, d); // enter skill level
			c->addback(e, stoi(d));// calll addback in character cllass and pass name and level by parameter
		}
		else if (selection == "4") { // if 4 == remove front
			c->removefront(); // remove first node
			c->read();
		}
		else if (selection == "5") {
			c->removeback(); //remove last node
			c->read();
		}
		else if (selection == "6") {
			cout << "---Available skill---" << endl;
			c->read();
		}
		else if (selection == "7") {
			cout << "---Available skill---" << endl;
			c->PrintFromHead();  // print skill from head
			cout << "Enter Skill Name to Amend : "; getline(cin, b); // enter skill name wish to amend
			cout << "Enter New Skill Name : "; getline(cin, d); // enter new skill name
			cout << "Enter New Level : "; getline(cin, e); // enter new level
			c->modify(b, d, stoi(e));
			// call modify function in character class and pass, b d e , search key/new name/new level by parameter
		}
		else { // when exit will print exising node in this 2 format
			c->PrintFromHead();
			c->PrintFromTail();
		}
	}
	return 0;
}