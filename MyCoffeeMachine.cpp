#include "MyCoffeeMachine.h"

void MyCoffeeMachine::Load()
{
	m_coffee= coffeeTankVol;
	m_milk = milkTankVol;
	m_sugar = sugarTankVol;
	m_water = waterTankVol;
}

bool MyCoffeeMachine::AddCoffee(uint32_t coffee)
{
	if (coffee + m_coffee> coffeeTankVol)
	{
		return false;
	}
	m_coffee+= coffee;
	return true;
}

bool MyCoffeeMachine::AddMilk(uint32_t milk)
{
	if (milk + m_milk > milkTankVol)
	{
		return false;
	}
	m_milk += milk;
	return true;
}

bool MyCoffeeMachine::AddSugar(uint32_t sugar)
{
	if (sugar + m_sugar > sugarTankVol)
	{
		return false;
	}
	m_sugar += sugar;
	return true;
}

bool MyCoffeeMachine::AddWater(uint32_t water)
{
	if (water + m_water > waterTankVol)
	{
		return false;
	}
	m_water += water;
	return true;
}
