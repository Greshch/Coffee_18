#include <iostream>
#include "MyCoffeeMachine.h"

int main() {
	MyCoffeeMachine machine;
	machine.Load();
	machine.SetAmericanoRecipe(15, 1, 10);
	machine.MakeAmericano(Glasses::SMALL);
	return 0;
}