#pragma once
#include "Entities.h"

#include "Iterator1D.h"
#include "Iterator2D.h"

int main() {

	//Task 1
	//Entities e;
	//string name;
	//cout << "Player Name : "; getline(cin,name);
	//e.setfName(name);
	//while (e.getfMessage().compare("EXIT")) { // checking user input is exit or command
		//cin >> e; //input by friend operator
		//if (e.getfMessage().compare("EXIT") == 0) { // if input is exit
		//	cout << "\nProblem Set 2 Task 1 Exiting......" << endl; //showing quiting state
		//}
		//else {  // if input is command
		//	cout << "Current HP : " << e.getfCurrentHP() << endl; // showing current hp
		//}
	//}

	//Task 3
	//-----------------
	Entities p1;
	Entities p2;
	string name;
	string item[] = {"book","knife","drink","tent","gift","Potion","Poweder","Meat","Vegetable","Fruit","empty"};
	string item2[][4] = {
		{"a","b","c","d"},
		{"e","f","g","h"},
		{"i","j","empty"}
	};
	Iterator1D i(item,11);
	Iterator2D i2(*item2, 11);
	cout << "Player 1 Name : "; getline(cin,name);
	p1.setfName(name);
	p1.grab(i);

	cout << "Plyear 2 Name : "; getline(cin,name);
	p2.setfName(name);
	p2.grab(i2);
	
	
	string input;
	while (input.compare("exit")) {
		string input_item;
		cout << "\nSelect Role " << endl;
		cout << "1. " << p1.getfName() << " transfer to " << p2.getfName() << endl;
		cout << "2. " << p2.getfName() << " trasnfer to " << p1.getfName() << endl;
		cout << "Select : "; getline(cin,input);
		while (input_item.compare("5")) {
			cout << "\nSelect item transfer " << endl;
			cout << "1. Previous " << endl;
			cout << "2. Next " << endl;
			cout << "3. Transfer " << endl;
			cout << "4. Check bag" << endl;
			cout << "5. exit " << endl;
			if (input.compare("1") == 0) {
				cout << "Current Item : " << p1.InventoryGet(1) << endl;;
				cout << "Enter : ";  getline(cin, input_item);
				if (input_item.compare("1") == 0) {
					p1.InventoryPrev(i);
				}
				else if (input_item.compare("2") == 0) {
					p1.InventoryNext(i);
				}
				else if (input_item.compare("3") == 0) {
					p2.ReceiveItem(p1,i2);
					p1.RemoveItem(i);
				}
				else if (input_item.compare("4") == 0) {
					cout << "\nIterator 1D bag (Alex): "; p1.Print(i);
					cout << "Iterator 2D bag (ben): "; p2.Print(i2);
				}
			}
			else if(input.compare("2") == 0) {
				cout << "Current Item : " << p2.InventoryGet(2) << endl;
				cout << "Enter : ";  getline(cin, input_item);
				if (input_item.compare("1") == 0) {
					p2.InventoryPrev(i2);
				}
				else if (input_item.compare("2") == 0) {
					p2.InventoryNext(i2);
				}
				else if (input_item.compare("3") == 0) {
					p1.ReceiveItem(p2,i);
					p2.RemoveItem(i2);
				}
				else if (input_item.compare("4") == 0) {
					cout << "\nIterator 1D bag (Alex): "; p1.Print(i);
					cout << "Iterator 2D bag (ben): "; p2.Print(i2);
				}
			}
		}
	}

	//-----------------------
	//Task 2
	//string item[] = {"book","knife","drink","tent","gift","Potion","Poweder","Meat","Vegetable","Fruit"};
	//string item2[][4] = {
		//{"book","knife","drink","tent"},
		//{"gift","Potion","Poweder","Meat"},
		//{"Vegetable","Fruit"} 
	//};

	//Iterator1D i(item,10);
	//Iterator1D i_comp(item, 10);
	//Iterator2D i2(*item2, 10);
	//Iterator2D i2_comp(*item2,10);

	//cout << "String in 1D Array " << endl;
	//for (int j = 0; j < 10; j++) {
		//if (j == 0) {
			//cout << i.operator*() << " -> ";
		//}
		//else {
		//	cout << i.operator++().operator*() << " -> ";
		//}
	//}
	//cout << " End" << endl;

	//cout << "\nCurrent index of string in 1D Array" << endl;
	//cout << i.operator*();
	
	//cout << "\n\nIncrement of index in 1D Array" << endl;
	//cout << i.operator++().operator*();

	//cout << "\n\nDecrement of index in 1D Array" << endl;
	//cout << i.operator--().operator*();

	//cout << "\n\nCompare 1D array in main and class iterator 1D" << endl;
	//i.operator==(i_comp);


	//cout << "\n\nString in 2D Array " << endl;
	//for (int j = 0; j < 10 ; j++) {
		//if (j == 0) {
		//	cout << i2.operator*() << " -> ";
		//}
		//else {
		//	cout << i2.operator++().operator*() << " -> ";
		//}
	//}
	//cout << " End" << endl;

	//cout << "\nCurrent Position : " << i2.operator*() << endl;
	//cout << "\nFordward 1 position : " << i2.operator--().operator*() << endl;
	//cout << "\nFordward 1 position : " << i2.operator--().operator*() << endl;
	//cout << "\nToward 1 position : " << i2.operator++().operator*() << endl;

	//cout << "\n\nCompare another 2D array in main and class iterator 2D" << endl;
	//i2.operator==(i2_comp);

	return 0;
}