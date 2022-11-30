#pragma once
#include <iostream>
#include <string>
#include "player.h"
#include "dungeon.h"
#include "Visitor.h"
#include "item.h"

using namespace std;


dungeon* createDungeon() {
	item* ia = new item("itema", 2);
	item* ib = new item("itemb", 1);
	item* ic = new item("itemc", 3);
	item* id = new item("itemd", 4);
	item* ie = new item("iteme", 2);
	item* ig = new item("itemf", 3);
	item* ih = new item("itemh", 2);
	item* i_i = new item("itemi", 2);
	dungeon* a = new dungeon("dungeona",ia,0);
	dungeon* b = new dungeon("dungeonb", ib,2);
	dungeon* c = new dungeon("dungeonc", ic,0);
	dungeon* d = new dungeon("dungeond", id,2);
	dungeon* e = new dungeon("dungeone", ie,1);
	dungeon* f = new dungeon("dungeonf", ig,3);
	dungeon* g = new dungeon("dungeong", ih,0);
	dungeon* h = new dungeon("dungeonh", i_i, 2);
	a->setLeft(b);
	a->setRight(c);
	c->setLeft(f);
	b->setLeft(d);
	d->setLeft(h);
	d->setRight(e);
	e->setLeft(g);
	return a;
}

int main() {

	string s,s1,s2;
	player* p = nullptr;
	dungeon* d = nullptr;
	Visitor* v = nullptr;

	while (s != "exit") {
		
		s1 = "";
		cout << "1. Start New Game " << endl;
		cout << "Selection [exit to quit] : "; getline(cin, s);
		if (s == "1") {
			p =new player("Alex", 20);
			p->generateQuest();
			while (s1 != "exit") {
				s2 = "";
				cout << "\nWelcome To the Game!" << endl;
				cout << "1.Go Dungeon" << endl;
				cout << "2.Check Quest" << endl;
				cout << "Selection[exit to quit] : "; getline(cin, s1);
				if (s1 == "1") {
					d = createDungeon();
					//d->inorderTraversal(d);
					dungeon* dd = d;
					cout << "\nYou are in " << dd->getName() << endl;
					v = new Visitor(dd->getDmg());
					p->accept(*v);
					v = nullptr;
					p->completeQuest(dd->getItem());
					while (s2 != "exit") {
						cout << "\n----In dungeon ing------" << endl;
						cout << "1.Move left" << endl;
						cout << "2.Move Right" << endl;
						cout << "Selection [exit to quit] : "; getline(cin, s2);
						if (s2 == "1") {
							if (dd->getLeft() != nullptr) {
								dd = dd->getLeft(); // get left node of current node
								cout << "\nYou are in " << dd->getName() << endl;
								v = new Visitor(dd->getDmg());
								p->accept(*v);
								v = nullptr;
								p->completeQuest(dd->getItem());
								if (p->completed() == "exit") {
									cout << "\n|--------------------------|" << endl;
									cout << "|Congratz you won the game!|" << endl;
									cout << "\--------------------------|\n" << endl;
									s2 = "exit";
									s1 = "exit";
								}
								if (p->getHp() <= 0) {
									s2 = "exit";
									s1 = "exit";
									cout << "\n|--------------------|" << endl;
									cout << "|No More HP, Game End|" << endl;
									cout << "|--------------------|\n" << endl;
								}
							}
							else {
								cout << "\n|--------------------------------|" << endl;
								cout << "|No More Way to go. quit dungeon!|" << endl;
								cout << "|--------------------------------|\n" << endl;
								s2 = "exit";
							}
						}
						else if (s2 == "2") {
							if (dd->getRight() != nullptr) {
								dd = dd->getRight(); // get rightD node of current node
								cout << "\nYou are in " << dd->getName() << endl;
								v = new Visitor(dd->getDmg());
								p->accept(*v);
								v = nullptr;
								p->completeQuest(dd->getItem());
								if (p->completed() == "exit") {
									cout << "\n|--------------------------|" << endl;
									cout << "\Congratz you won the game!|" << endl;
									cout << "\--------------------------|\n" << endl;
									s2 = "exit";
									s1 = "exit";
								}
								if (p->getHp() <= 0) {
									s2 = "exit";
									s1 = "exit";
									cout << "\n|--------------------|" << endl;
									cout << "|No More HP, Game End|" << endl;
									cout << "|--------------------|\n" << endl;
								}
							}
							else {
								cout << "\n|--------------------------------|" << endl;
								cout << "|No More Way to go. quit dungeon!|" << endl;
								cout << "|--------------------------------|\n" << endl;
								s2 = "exit";
							}
						}
					}
				}
				else if (s1 == "2") {
					p->checkQuest();
				}

			}
		}
	}
	return 0;
}



