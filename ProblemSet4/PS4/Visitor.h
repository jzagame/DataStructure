#pragma once
#include <iostream>
#include <string>
#include "player.h"
#include "item.h"
using namespace std;

class player;
class item;


class Visitor {
private:
	int damage;
public:
	Visitor(int temp);
	virtual void Visit(player& p);
};
