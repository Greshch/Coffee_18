#include <iostream>
#include "MyCoffeeMachine.h"

int main() {
	MyCoffeeMachine machine;
	machine.Load();

	if (!machine.SetRecipe(15, 1, 10, "Americano"))
	{
		std::cout << "Set recept error!!..\n";
	}

	if (!machine.SetRecipe(10, 1, 15, "Latte"))
	{
		std::cout << "Set recept error!!..\n";
	}

	machine.PrintRecipes();
	std::cout << "Choose name of recepi: ";
	std::string name;
	std::cin >> name;
	if (machine.MakeRecept(name, Glasses::SMALL))
	{
		Recept* recipe = machine.GetRecipe(name);
		machine.Print(recipe, Glasses::SMALL);
	}
	return 0;
}