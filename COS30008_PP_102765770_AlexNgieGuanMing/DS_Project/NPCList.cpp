#include "NPCList.h";

NPCList::NPCList() {
	npclist = nullptr;
	head = nullptr;
	tail = nullptr;
	remark = 0;
}
void NPCList::remove(string order,FoodList* ing,string cmd) {
	NPC* temp = head;
	bool flag = false;
	while (temp != nullptr) {
		if (temp->getNName() == order) {
			flag = true;
			break;
		}
		if (temp->getNext() == nullptr) {
			break;
		}
		temp = temp->getNext();
	}
	if (flag) {
		if (temp->getNext() != nullptr && temp->getPrev() != nullptr) {
			temp->getNext()->setPrev(temp->getPrev());
			temp->getPrev()->setNext(temp->getNext());
			head = temp->getPrev();
			tail = temp->getNext();
		}
		else {
			if (temp->getNext() == nullptr) {
				temp->getPrev()->setNext(nullptr);
				tail = temp->getPrev();
			}
			if (temp->getPrev() == nullptr) {
				temp->getNext()->setPrev(nullptr);
				head = temp->getNext();
			}
		}
		cout << temp->getNName() + " successfully " + cmd << endl; // cmd ="rejected" cmd = " served"
		NPC* temp1 = new NPC(ing->getFood()->getName(), "c" + to_string(remark), "Im " + to_string(remark) + " Customer", 100, 0);
		add(temp1);
		remark++;
	}
	else {
		cout << "No such Customer found" << endl;
	}
}


void NPCList::GenerateNPC(FoodList* ing) {
	for (int i = 0; i < 3; i++) {
		NPC* temp = new NPC(ing->getFood()->getName(), "c" + to_string(remark), "Im " + to_string(remark) + " Customer", 100, 0);
		add(temp);
		//cout << i << ing->getFood()->getName() << endl;
		remark++;
	}
}

void NPCList::add(NPC* temp) {
	NPC* npc = npclist;
	if (npc == nullptr) {
		npclist = temp;
		head = npclist;
		tail = npclist;
	}
	else {
		head->setPrev(temp);
		temp->setNext(head);
		head = temp;
		npclist = temp;
	}
}

void NPCList::AllNPC() {
	NPC* npc = head;
	cout << "\n----Customer List-----" << endl;
	while (npc != nullptr) {
		npc->Status();
		if (npc->getNext() == nullptr) {
			break;
		}
		npc = npc->getNext();
	}
}

bool NPCList::Serve(string name, Player* player,FoodList* fl) {
	bool x = false;
	NPC* temp = npclist;
	while (temp != nullptr) {
		if (temp->getNName() == name) {
			x = true;
			break;
		}
		if (temp->getNext() == nullptr) {
			break;
		}
		temp = temp->getNext();
	}
	if (x) {
		bool ok = true;
		char separator = '-';
		Food* f = fl->searchIng(temp->getOrder()); // get the information of food
		string temp_ing = f->getII(); // get it ingredient list "asdsa-asda-asd-asdsa-asds"
		split(temp_ing, separator); // split ingredient list to array
		for (int i = 0; i < 8; i++) {
			if (strings[i].empty() == false) { 
				bool fff = player->validOfUse(strings[i], 1); // check player inventory
				if (fff == false) { // inventory no exists item is false
					ok = false;
					cout << strings[i] << " no enuf, please check inventory" << endl;
				}
			}
			else {
				break;
			}
		}
		if (ok) { // process cooking 
			for (int i = 0; i < 8; i++) {
				if (strings[i].empty() == false) {
					player->readyToUse(strings[i], 1);
				}
				else {
					break;
				}
			}
			player->addMoney(f->getCost()); // get food cost
			cout << "Earned " << f->getCost() << endl; //show earn cost
			remove(temp->getNName(), fl," served"); // show info customer
		}
	}
	return x;
}

int NPCList::len(string str){
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		length++;

	}
	return length;
}

void NPCList::split(string str, char seperator) {
	int currIndex = 0, i = 0;
	int startIndex = 0, endIndex = 0;
	while (i <= len(str))
	{
		if (str[i] == seperator || i == len(str))
		{
			endIndex = i;
			string subStr = "";
			subStr.append(str, startIndex, endIndex - startIndex);
			strings[currIndex] = subStr;
			currIndex += 1;
			startIndex = endIndex + 1;
		}
		i++;
	}
}

void NPCList::CheckOneByOne(string temp) {
	if (temp == "prev") { // if input is prev
		if (npclist->getPrev() != nullptr) { // if prev is not a null pointer
			npclist = npclist->getPrev(); // get prev pointer
		}
		else { // if empty prev pointer
			cout << "\nthis is the first customer in list" << endl; // display messsage
		}
	}
	else if (temp == "next") { // if input is next
		if (npclist->getNext() != nullptr) { // if next is not a null pointer
			npclist = npclist->getNext(); // get next pointer
		}
		else { // if next is null pointer
			cout << "\nthis is the last customer in list" << endl; // display messsage
		}
	}
}

void NPCList::displayData() {
	npclist->Status();
}