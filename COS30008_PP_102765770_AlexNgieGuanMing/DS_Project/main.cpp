#pragma once
#include "NPCList.h"
#include "Player.h"
#include "Inventory.h"
#include "Ingredient.h"
#include <queue>
#include "FoodList.h"
#include <sstream>  
#include <stdlib.h>
#include "MonsterList.h"
#include <SFML/Audio.hpp>

static string GameMenu();
string InGame();
string CustomerServe(NPCList &nl, FoodList* fl,Player& pl);	
FoodList* createFood();
MonsterList* createMonster(MonsterList* mm);
string AdventureMenu(MonsterList* mm);

int main() {
	sf::SoundBuffer buffer;
	buffer.loadFromFile("song.wav");
	sf::Sound sound(buffer);
	sound.play();
	sound.setLoop(true);

	static FoodList* fl = createFood();
	
	Player* player = nullptr;
	Ingredient ingredient;
	
	MonsterList* monsterList = new MonsterList();
	queue<string> upgrade;
	string s1, s2,s3,s2_3;
	while (s1 != "4") {
		s1 = GameMenu();
		s2 = "";
		system("CLS");
		NPCList nl = NPCList();
		nl.GenerateNPC(fl);
		if (s1 == "1") {
			player = new Player("Alex", "This is Easy Mode", 200, 10, 1000);
		}
		else if (s1 == "2") {
			player = new Player("Alex", "This is Normal Mode", 150, 10, 500);
		}
		else if (s1 == "3") {
			player = new Player("Alex", "This is Hard Mode", 100, 10, 200);
		}
		while (s2 != "6") {
			s2 = InGame();
			if (s2 == "1") {
				s3 = "";
				while (s3 != "4") {
					s3 = CustomerServe(nl,fl, *player);
				}
			}
			else if (s2 == "2") {
				player->MyInventory();
			}
			else if (s2 == "3") {
				s2_3 = "";
				bool flag = false;
				monsterList = new MonsterList();
				monsterList = createMonster(monsterList);
				while (s2_3 != "exit") {
					s2_3 = AdventureMenu(monsterList);
					bool flag = false;
					if (s2_3 != "exit") {
						flag = player->attackMonster(&monsterList->find(s2_3));
						if (flag) {
							player->BackToRestaurant(0,0);
							s2_3 = "exit";

							if (player->getChance().empty() == 1) {
								s2 = "6";
							}
						}
					}
					else if (s2_3 == "exit") {
						player->BackToRestaurant("Back to Resturant");

					}
				}
			}
			else if (s2 == "4") {
				string t1 = "";
				while (t1 != "3") {
					cout << "\n---Status---" << endl;
					cout << "1.Upgrade Status" << endl;
					cout << "2.Check Status" << endl;
					cout << "3.exit" << endl;
					cout << "Selection (Enter Number) : "; getline(cin, t1); 
					if (t1 == "1") {
						string t2,t3;
						cout << "\n----Upgrade Status[100 per upgrade]----" << endl;
						cout << "1.Running [Max HP + 10]" << endl;
						cout << "2.Push Up [Damage + 5]" << endl;
						cout << "3.exit" << endl;
						cout << "Selection (1,2,1,2,1)(3 for exit) : "; getline(cin,t2); // enter selection "1,2,2,1,2,2"
						if (t2 == "3") { // if 3 == exit
							t1 = "3"; //  set t1 to 3 and quit
						}
						else {
							stringstream X(t2); // convert input into stringstream
							while (getline(X, t3, ',')) { // split 1 by 1 by delimeter ","
								upgrade.push(t3); // push into queue
							}
							player->StatusUpgrade(upgrade); //pass into statusUpgrade()
						}
					}else if (t1 == "2") {
						player->status();
						
					}
				}
			}
			else if (s2 == "5") {
				cout << "\n------Ingredient List-------" << endl;
				fl->PrintAll();
			}
			else if (s2 == "6") {
				s1 = "";
			}
		}
	}
	return 0;
}

string AdventureMenu(MonsterList* mm) {
	string temp;
	cout << "\n------Move And Attack------" << endl;
	mm->printAll();
	cout << "[exit] for quit" << endl;
	cout << "Enter Monster Name:"; getline(cin, temp);
	return temp;
}

MonsterList* createMonster(MonsterList* mm) {
	Monster* monsterA = new Monster("monstera", "Im Monster A", 100, 10, 50, 50);
	monsterA->add("meat");
	monsterA->add("vegetable");
	monsterA->add("tomato");
	monsterA->add("noodles");
	Monster* monsterB = new Monster("monsterb", "Im Monster B", 100, 10, 100, 200);
	monsterB->add("rice");
	monsterB->add("oil");
	monsterB->add("salt");
	monsterB->add("sugar");
	Monster* monsterC = new Monster("monsterc", "Im Monster C", 100, 10, 300, 450);
	monsterC->add("chili");
	monsterC->add("milk");
	monsterC->add("water");
	monsterC->add("pork");
	Monster* monsterD = new Monster("monsterd", "Im Monster D", 100, 10, 250, 350);
	monsterD->add("egg");
	monsterD->add("soy sauce");
	monsterD->add("fish");
	monsterD->add("cucumber");
	Monster* monsterE = new Monster("monstere", "Im Monster E", 100, 10, 500, 650);
	monsterE->add("strawberry");
	monsterE->add("pumpkin");
	monsterE->add("apple");
	monsterE->add("orange");
	mm->add(monsterA);
	mm->add(monsterB);
	mm->add(monsterC);
	mm->add(monsterD);
	mm->add(monsterE);
	return mm;
}

string GameMenu() {
	string temp;
	cout << "\n-----Select Mode-----" << endl;
	cout << "1.Easy" << endl;
	cout << "2.Normal" << endl;
	cout << "3.Hard" << endl;
	cout << "4.exit" << endl;
	cout << "selection (Enter Number): "; getline(cin, temp);
	
	return temp;
}

string InGame() {
	string temp;
	cout << "\n-----Select Action-----" << endl;
	cout << "1.Serve Customer" << endl;
	cout << "2.Inventory" << endl;
	cout << "3.Adventure" << endl;
	cout << "4.Status" << endl;
	cout << "5.Check Ingredient" << endl;
	cout << "6.exit" << endl;
	cout << "Selection (Enter Numeber) : "; getline(cin, temp);
	return temp;
}

string CustomerServe(NPCList &nl,FoodList* fl,Player& pl) {
	string temp;
	cout << "\n----Customer Serve----" << endl;
	cout << "1.Customer List" << endl;
	cout << "2.Serve Customer" << endl;
	cout << "3.Remove	" << endl;
	cout << "4.Exit" << endl;
	cout << "Selection (Enter Number) : "; getline(cin, temp);
	if (temp == "1") {
		nl.AllNPC();
	}
	else if (temp == "2") {
		string x; bool flag = false;
		while (x != "exit") {
			nl.displayData();
			cout << "Enter Name of Customer (prev | next | exit) : "; getline(cin, x);
			if (x == "prev" || x == "next") {
				nl.CheckOneByOne(x);
			}
			else {
				nl.Serve(x, &pl, fl);
			}
		}
	}
	else if (temp == "3") {
		string x;
		cout << "----Remove Customer----" << endl;
		nl.AllNPC();
		cout << "Enter Name of Customer : "; getline(cin, x);
		nl.remove(x,fl,"rejected");
	}
	return temp;
}

FoodList* createFood() {
	FoodList* fl = new FoodList();
	Ingredient i;
	string temp = i[7] + "-" + i[9] +"-" + i[19];
	Food* orangejuice = new Food("Orange Juice", 20,temp);
	fl->add(orangejuice);
	string temp1 = i[7] + "-" + i[9] + "-" + i[18];
	Food* applejuice = new Food("Apple Juice", 30, temp1);
	fl->add(applejuice);
	string temp2 = i[7] + "-" + i[9]+ "-" + i[15];
	Food* pumpkinjuice = new Food("Cucumber Juice", 25, temp2);
	fl->add(pumpkinjuice);
	string temp3 =  i[4] + "-" + i[5] + "-" + i[6] + "-" + i[8] + "-" + i[11] ;
	Food* riceA = new Food("riceA", 100, temp3);
	string temp4 =  i[4] + "-" + i[5] + "-" + i[6] + "-" + i[8] + "-" + i[12] + "-" + i[14];
	Food* riceB = new Food("riceB", 100, temp4);
	fl->add(riceB);
	string temp5 =  i[3] + "-" + i[5] + "-" + i[6] + "-" + i[12] + "-" + i[13] ;
	Food* noodleA = new Food("noodleA", 100, temp5);
	fl->add(noodleA);
	string temp6 =  i[0] + "-" + i[1] + "-" + i[3] + "-" + i[11] + "-" + i[13] ;
	Food* noodleB = new Food("noodleB", 100, temp6);
	fl->add(noodleB);
	string temp7 =  i[1] + "-" + i[2] + "-" + i[10] + "-" + i[16] + "-" + i[17] ;
	Food* desertA = new Food("desertA", 100, temp7);
	fl->add(desertA);
	return fl;
}


