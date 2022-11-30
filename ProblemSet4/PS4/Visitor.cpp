#include "Visitor.h"


Visitor::Visitor(int temp) {
	damage = temp;
}

void Visitor::Visit(player& p) {
	p.hpDown(damage);
	cout << "Damage Received From Dungeon : " << damage << endl;
	cout << "Current hp : " << p.getHp() << endl;
}