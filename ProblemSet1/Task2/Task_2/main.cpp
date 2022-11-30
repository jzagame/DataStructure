#include "Entities.h"
#include "Zealot.h"
#include "Dragoon.h"
#include "Carrier.h"
int main() {

	//Zealot z;
	//Dragoon d;
	//Carrier c;

	//z.setfOwner("Alex");
	//d.setfOwner("Benjamin");
	//c.setfOwner("ZH");

	//z.Print();
	//d.Print();
	//c.Print();

	Entities e;
	string msg;

	e.PintStatus();

	cout << "\n -- Listen function -- " << endl;
	cout << "Message : "; getline(cin,msg);
	e.Listen(msg);
	cout << " -- Tell Function -- " << endl;
	e.Tell();

	cout << "\n -- Firend Opeator Overload Listen Function -- " << endl;
	cin >> e;
	cout << " -- Firend Opeator Overload Tell Function -- " << endl;
	cout << e;

	cout << " \n-- destructor work after all process done -- " << endl;

	return 0;
}