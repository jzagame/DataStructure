#pragma once
#include "NPC.h"
#include "FoodList.h"
#include "Player.h"


class NPCList {
private:
	NPC* npclist;
	NPC* head;
	NPC* tail;
	string strings[8];
	int remark; // record number of customer generated
public:
	NPCList();
	void add(NPC* temp);
	void remove(string order, FoodList* ing,string cmd);
	void GenerateNPC(FoodList* ing);
	void AllNPC();
	void CheckOneByOne(string temp);
	void displayData();
	bool Serve(string name,Player* player,FoodList *fl);
	int len(string str);
	void split(string str, char seperator);
	
};