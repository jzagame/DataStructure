#include "Zealot.h"

Zealot::Zealot() {
	belief = "Jesus";
	elements = "light";
}

void Zealot::Print() {
	cout << "Zealot of " << belief << " (" << elements << ")\n" << endl;
}