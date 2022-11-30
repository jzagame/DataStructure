#pragma once
#include <iostream>
#include <string>

using namespace std;

class Iterator1D {
private:
	string* item;
	int size;
	int index;
public:
	Iterator1D( string temp_arr[], int temp_size);
	~Iterator1D();
	string& operator*();
	Iterator1D& operator++();
	Iterator1D& operator--();
	void initialize();
	void setItem(string temp_s);
	bool operator==( Iterator1D& temp);
};