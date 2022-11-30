#include "IngredientList.h"

IngredientList::IngredientList() {
	ing = NULL;
}

void IngredientList::add(string temp_name, double temp_rare) {
	Ingredient* temp_i = ing;
	if (temp_i == nullptr) {
		ingredient.ing_name = temp_name;
		ingredient.rare = temp_rare;
	}
}

void IngredientList::getDetail(string temp_name) {
	
}

