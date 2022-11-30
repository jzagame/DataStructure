#include "Iterator2D.h"

Iterator2D::Iterator2D(string *temp_item,int temp_size) :item(temp_item), size(temp_size) {
	index = 0;
}

Iterator2D::~Iterator2D() {};

 string& Iterator2D::operator*()  { //this deference operator will return the current positioned item.
	return *(item + index); 
}

Iterator2D& Iterator2D::operator++() { // increment operator will back to the first index once the index is out of bound
	index++;
	//if (index >= size) {
		//cout << "Last index in array, cannot increment anymore : ";
		//index = size - 1;
	//}
	return *this;
}

Iterator2D& Iterator2D::operator--() { // decrement operator will stop decrease the index once the position of index at 0
	index--;
	return *this;
}

bool Iterator2D::operator==( Iterator2D& temp)  { // 
	//bool x = (index == temp.index) && (*(item + index) == *(temp.item + index));
	//if (x == 1) {
		//cout << "Same item in both array" << endl;
	//}
	//else {
	//	cout << "Different item in both array" << endl;
	//}
	return (temp.index >= 0) && (temp.index < size);
}

void Iterator2D::setItem(string temp_s) {
	*(item + index) = temp_s;
}

void Iterator2D::initialize() {
	index = 0;
}