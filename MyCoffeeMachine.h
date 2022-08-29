#pragma once

#include "ICoffeeMachine.h"
#include "ICoffeeMachineRecipe.h"

class MyCoffeeMachine : public ICoffeeMachine,
						public ICoffeeMachineRecipe
{

};

