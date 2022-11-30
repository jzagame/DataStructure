#include "Player.h"

Player::Player(string name,string script, double hp,double damage,double temp_m):Character(name,script,hp,damage) {
	inventory = NULL;
	money = temp_m;
	for (int i = 1; i < 3; i++) {
		chance.push(i);
	}
}

stack<int> Player::getChance() {
	return chance;
}

void Player::add(string t_itemName, int t_itemNumber) {
	Inventory* t_inv = inventory; 
	bool flag = true; // true is new item , false == exists
	if (t_inv == nullptr) { // if inventory is empty
		inventory = new Inventory(t_itemName,t_itemNumber); // create new inventory
	}
	else {
		while (t_inv != nullptr) { // if inventory pointer not null
			if (t_inv->getItemName() == t_itemName) { // if itemname is exist in inventory
				flag = false; // flag set to false
				t_inv->getItemNumber() += t_itemNumber; //add the number of item
				break; // break while loop and quit
			}
			if (t_inv->getNext() == nullptr) { // if next pointer == null
				break; // break loop
			}
			t_inv = t_inv->getNext(); // get next inventory
		}
		if (flag) { // true when item is no exist in inventory of player
			Inventory* temp = new Inventory(t_itemName, t_itemNumber); // add new item
			t_inv->setNext(temp); // set new item to the end of the single link list
		}
	}
}

void Player::remove(string t_itemName, int t_itemNumber) {
	Inventory* t_inv = inventory;
	bool flag = true;
	while (t_inv != nullptr) {   //decrease item number by searching name of item 
		if (t_inv->getNext() == nullptr || t_inv->getItemName() == t_itemName) {
			t_inv->setItemNumber(t_inv->getItemNumber() - t_itemNumber);
			flag = false;
			break;
		}
		t_inv = t_inv->getNext();
	}
}

Inventory& Player::search(string t_itemName) {
	Inventory* t_inv = inventory;
	bool flag = true;
	while (t_inv != nullptr) {   //decrease item number by searching name of item 
		if (t_inv->getNext() == nullptr || t_inv->getItemName() == t_itemName) {
			return *t_inv;
		}
		t_inv = t_inv->getNext();
	}
}

bool Player::validOfUse(string t_itemName, int t_itemNumber) {
	Inventory* t_inv = inventory;
	if (t_inv == nullptr) {
		return false;
	}
	else {
		while (t_inv != nullptr) {
			if (t_inv->getItemName() == t_itemName) {
				if (t_inv->getItemNumber() > 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (t_inv->getNext() == nullptr) {
				return false;
			}
			t_inv = t_inv->getNext();
		}
	}
}

void Player::readyToUse(string t_itemName, int t_itemNumber) {
	Inventory* t_inv = inventory;
	while (t_inv != nullptr) {
		if (t_inv->getItemName() == t_itemName) {
			t_inv->getItemNumber() -= t_itemNumber;
			break;
		}
		if (t_inv->getNext() == nullptr) {
			break;
		}
		t_inv = t_inv->getNext();
	}
}

string Player::getMyScript() {
	return getScript();
}

void Player::MyInventory() {
	Inventory* x = inventory;
	while (x != nullptr) {
		cout << x->getItemName() << " : " << x->getItemNumber() << endl;
		x = x->getNext();
	}
	if (inventory == nullptr) {
		cout << "\nInventory is Empty" << endl;
	}
	cout << "\n";
}

void Player::status() { // print status of character
	characterStatus(); // function inherit from base class (Character class) to print hp, name , position etc
	cout << "Life     : " << chance.top()  << endl;
	cout << "Pos X/Y  : " << getPos().x << "/" << getPos().y << endl;
	cout << "Gold     : " << money  << endl;
}

void Player::StatusUpgrade(queue<string> &temp) { // upgrade status of player, max hp and damage
	cout << "\n---Upgrading...----" << endl; // upgrade status per time cost 100
	if (money >= 100) { // if player current money > 100
		while (temp.empty() == false){ 
			if (money < 100) { // if player current money > 100
				cout << "Money no enuf" << endl;
				temp.pop();
			}
			else if(temp.front() == "1") { // 
				increaseMaxHp(10); //  max hp increase 10
				cout << "HP Increate 10 -- ";
				cout << "Max/Current HP : " << getMaxHp() << "/" << getCurrentHp() << endl;
				money -= 100; // money - 100
				temp.pop(); // pop up 1 item from queue
				Sleep(500);
			}
			else if (temp.front() == "2") {
				increaseDamage(5); // damage increase 5
				cout << "Damage Increase 5" << endl;
				cout << "Damage : " << getDamage() << endl;
				money -= 100; // money - 100
				temp.pop(); // pop up 1 item from queue
				Sleep(500);
			}
			
		}
	}
	else {
		cout << "Money mo enuf" << endl;
	}
}

bool Player::attackMonster(Monster* monster) {
	bool flag = false; // this flag is to check whther is monster dead or player dead
	cout << "Current Position (x,y) : " << getPos().x << "," << getPos().y << endl;
	if (getPos().x > monster->getPos().x) { // if user current position x bigger than monster current position x
		while (getPos().x > monster->getPos().x) { // while user current position x bigger thatn monster current position x, loop will continue
			getPos().x -= 50; // user current position x - 50, getpos is inherit from base class (Character)
			cout << "Player Move (X,Y) : " + to_string(getPos().x) + "," + to_string(getPos().y) << endl; // print out statement
			Sleep(500);
		}
	}
	else {// if user current position x smaller than monster current position x
		while (getPos().x < monster->getPos().x) { // while user current position x smaller thatn monster current position x, loop will continue
			getPos().x += 50;  // user current position x + 50, getpos is inherit from base class (Character)
			cout << "Player Move (X,Y) : " + to_string(getPos().x) + "," + to_string(getPos().y) << endl;// print out statement
			Sleep(500);
		}
	}
	if (getPos().y > monster->getPos().y) {// if user current position y bigger than monster current position y
		while (getPos().y > monster->getPos().y) { // while user current position y bigger than monster current position y, loop will continue
			getPos().y -= 50; // user current position y - 50, getpos is inherit from base class (Character)
			cout << "Player Move (X,Y) : " + to_string(getPos().x) + "," + to_string(getPos().y) << endl;// print out statement
			Sleep(500);
		}
	}
	else {// if user current position y smaller than monster current position y
		while (getPos().y < monster->getPos().y) {  // while user current position y smaller than monster current position y, loop will continue
			getPos().y += 50;// user current position y + 50, getpos is inherit from base class (Character)
			cout << "Player Move (X,Y) : " + to_string(getPos().x) + "," + to_string(getPos().y) << endl;// print out statement
			Sleep(500);
		}
	}
	if (monster->getCurrentHp() == 0) { // if mosnter current hp is 0
		cout << monster->getName() << " already dead!" << endl; // appear monster has been defeated
	}
	else if (getCurrentHp() == 0) { // if player hp is 0
		cout << " player already dead.Quiting adventure..." << endl; //apear msg
		flag = true;
	}
	else { // else player and mosnter hp > 0
		while (monster->getCurrentHp() > 0) { // continuous lopp when mosnter hp > 0
			if (monster->getCurrentHp() - getDamage() > 0) {
				monster->getCurrentHp() -= getDamage(); // decrease monter hp by player damge
			}
			else {
				monster->getCurrentHp() = 0;
			}
			cout << "Player attack " << monster->getName() << endl; // display player hp
			cout << monster->getName() + " HP : " << monster->getCurrentHp() << " / " << monster->getMaxHp() << endl << endl; // display monster hp
			Sleep(500);
			if (monster->getCurrentHp() == 0) { // if monster hp == 0
				break; // break loop
			}
			getCurrentHp() -= monster->getDamage(); //decrease player hp by monster damage
			cout << monster->getName() << " attack player " << endl; // appear msg 
			cout << getName() + " HP : " << getCurrentHp() << " / " << getMaxHp() << endl << endl; // dusplay plater current hp
			Sleep(500);
			if (getCurrentHp() == 0) { // if player hp is 0
				cout << "Player already dead.Quiting adventure..." << endl; // appear msg
				flag = true; // set flag to true
				break;
			}
		}
		if (flag == false) { // flag == false mean player win
			cout << monster->getName() + " defeated by player" << endl; // display msg
			cout << "Item get : "; monster->printInventory(); cout << endl; // display msg item get
			Inventory* temp = monster->getItem(); //get item from monster
			while (temp != nullptr) {
				add(temp->getItemName(),temp->getItemNumber()); // add it into player inventory
				if (temp->getNext() == nullptr) { // if no next pointer, break
					break;
				}
				temp = temp->getNext(); // get next pointer
			}
			monster->emptyInventory(); // empty inventory of monster
		}
	}
	
	return flag; // return true or false, false means monster defeat, true is player dead
	
}

void Player::BackToRestaurant(double x,double y) {
	chance.pop(); // decrease 1 hp
	setPosition(x,y); // initialize the position of player
	getCurrentHp() = getMaxHp(); // recovery player hp by assigning Maxhp to current hp
	if (chance.empty() != 1) { // if still left life, print this message
		cout << "Hp regeneration done." << endl; // appear msg
	}
	else {
		cout << "Game End!" << endl;
	}
}

void Player::BackToRestaurant(string temp) {
	cout << "\nCurrent Position (x,y) : " << to_string(getPos().x) + "," + to_string(getPos().y) << endl; 
	while (getPos().x > 0) {
		getPos().x -= 50;
		cout << "Player Move (X,Y) : " + to_string(getPos().x) + "," + to_string(getPos().y) << endl;
		Sleep(500);
	}
	while (getPos().y > 0) {
		getPos().y -= 50;
		cout << "Player Move (X,Y) : " + to_string(getPos().x) + "," + to_string(getPos().y) << endl;
		Sleep(500);
	}
	getCurrentHp() = getMaxHp();
	cout << temp << endl;
}

void Player::addMoney(double temp) {
	money += temp;
}