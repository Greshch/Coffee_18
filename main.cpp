#include <iostream>
#include "MyCoffeeMachine.h"

int main() {
	MyCoffeeMachine machine;
	machine.Load();
	machine.SetAmericanoRecipe(15, 1, 10);
	machine.SetLatteRecipe(10, 1, 15);
	machine.MakeAmericano(Glasses::MIDD);
	machine.MakeLatte(Glasses::SMALL);

	return 0;
}