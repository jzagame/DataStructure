#pragma once
#include <iostream>
#include <string>

using namespace std;

class Iterator2D {
private:
	string *item;
	int size;
	int index;
public:
	Iterator2D(string *temp_item,int temp_size);
	~Iterator2D();
	string& operator*();
	Iterator2D& operator++();
	Iterator2D& operator--();
	bool operator==(Iterator2D& temp);
	void initialize();
	void setItem(string temp_s);
};