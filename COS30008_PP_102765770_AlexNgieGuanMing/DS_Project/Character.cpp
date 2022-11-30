#include "Character.h"

Character::Character(string s_name,string s_script,double t_hp,double t_dmg) {
	name = s_name;
	script = s_script;
	maxHp = t_hp;
	currentHp = t_hp;
	damage = t_dmg;
}

string Character::getName() {
	return name;
}

string Character::getScript() {
	return script;
}

double Character::getMaxHp() {
	return maxHp;
}

double& Character::getCurrentHp() {
	return currentHp;
}

void Character::hpDecrease(double temp) {
	currentHp -= temp;
}

void Character::setPosition(double x, double y) { // set position of character
	pos.x = x;
	pos.y = y;
}

void Character::characterStatus() {
	cout << "\n----------Status-----------" << endl;
	cout << "Name     : " << name << endl;
	cout << "MaxHP/HP : " << maxHp << "/" << currentHp << endl;
	cout << "Damage   : " << damage << endl;
}

void Character::increaseMaxHp(double temp) {
	maxHp += temp;
	currentHp = maxHp;
}

void Character::increaseDamage(double temp) {
	damage += temp;
}

double Character::getDamage() {
	return damage;
}

Position& Character::getPos() { // return position of character
	return pos;
}
