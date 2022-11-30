#include "NPC.h"

NPC::NPC(string temp_order, string name, string script, double hp, double damage) :Character(name,script,hp,damage) {
	order = temp_order;
}


void NPC::setNext(NPC* temp) { // set next NPC
	next = temp;
}

void NPC::setPrev(NPC* temp) { // set prev NPC
	prev = temp;
}

NPC* NPC::getNext() { // get next NPC
	return next;
}

NPC* NPC::getPrev() {// get prev NPC
	return prev;
}

void NPC::Status() { // status of NPC
	characterStatus();
	cout << "Order    : " << order << endl;
}

string NPC::getOrder() { // get order of NPC
	return order;
}

string NPC::getNName() { // get name of npc
	return getName(); // inherit from base class
}