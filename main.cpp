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
	std::cout << "Choose recept of recepi: ";
	std::string recept;
	std::cin >> recept;

	std::cout << "Choose size of glass(1 - GlasWgSmall, 2 - GlasWgMiddle, 3 - GlasWgBig): ";
	short size;
	std::cin >> size;
	bool result = false;

	if (size == GlassesType::GlassTypeSmall)
	{
		result = machine.MakeSmallGlassByRecept(recept);
	}
	else if (size == GlassesType::GlassTypeMidd)
	{
		result = machine.MakeMiddleGlassByRecept(recept);
	}
	else if (size == GlassesType::GlassTypeBig)
	{
		result = machine.MakeBigGlassByRecept(recept);
	}
	
	if (result == true)
	{
		machine.Print(recept, static_cast<GlassesType>(size));
	}
	else
	{
		std::cout << "Error make drink..Sorry...\n";
	}
	
	return 0;
}