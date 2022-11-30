#include "Character.h"

Character::Character(string t_name, int t_hp) {
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


void Character::addfront(string s_temp, int s_level) { // call skilllist add front
	SL.addfront(s_temp,s_level);
}

void Character::addback(string s_temp, int s_level) {// call skilllist add back function
	SL.addback(s_temp, s_level);
}

void Character::removefront() { // call skill list remove front function
	SL.removefront();
}

void Character::removeback() { //call skill list remove back function
	SL.removeback();
}

void Character::modify(string temp, string s_name, int s_level) { // call skill list modify function
	SL.modify(temp, s_name, s_level);
}


void Character::find(string s_name) { // call skill list find function
	SL.find(s_name);
}

void Character::read() { // call skill list read function
	SL.read();
}

void Character::PrintFromTail() { // call skill list read from tail function
	SL.PrintFromTail();
}

void Character::PrintFromHead() {// call skill list read from head function
	SL.PrintFromHead();
}