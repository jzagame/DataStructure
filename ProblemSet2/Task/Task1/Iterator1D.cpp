#include "Iterator1D.h"

Iterator1D::Iterator1D( string temp_arr[],  int temp_size) :item(temp_arr), size(temp_size) {
	index = 0;
};

Iterator1D::~Iterator1D(){};

string& Iterator1D::operator*()  { //this deference operator will return the current positioned item.
	return item[index];
}

Iterator1D& Iterator1D::operator++() { // increment operator will back to the first index once the index is out of bound
	index++;
	return *this;
}

Iterator1D& Iterator1D::operator--() { // decrement operator will stop decrease the index once the position of index at 0
	index--;
	return *this;
}

bool Iterator1D::operator==( Iterator1D& temp)  { // 
	//bool x = (index == temp.index) && (item == temp.item);
	//if (x == 1) {
		//cout << "Same item in both array" << endl;
	//}
	//else {
		//cout << "Different item in both array" << endl;
	//}
	return (temp.index >= 0) && (temp.index < size);
}

void Iterator1D::setItem(string temp_s) {
	*(item + index) = temp_s;
}

void Iterator1D::initialize() {
	index = 0;
}