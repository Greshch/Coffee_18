#include "MyCoffeeMachine.h"
#include <cmath>
#include <iostream>

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

bool MyCoffeeMachine::SetAmericanoRecipe(uint32_t water, uint32_t sugar, uint32_t milk)
{
	if (!IsValidRecepte(water, sugar, milk))
	{
		return false;
	}

	m_americanoWater = water;
	m_americanoMilk = milk;
	m_americanoSugar = sugar;
	return true;
}

bool MyCoffeeMachine::SetLatteRecipe(uint32_t water, uint32_t sugar, uint32_t milk)
{
	if (!IsValidRecepte(water, sugar, milk))
	{
		return false;
	}

	m_lateWater = water;
	m_lateMilk = milk;
	m_lateSugar = sugar;
	return true;
}

bool MyCoffeeMachine::MakeAmericano(Glasses glass)
{
	uint32_t expected = static_cast<uint32_t>(glass);
	uint32_t total = GetTotalVolume();
	uint32_t expectedCoffee = GetExpectedCoffeForGlass(glass);
	uint32_t expectedMilk = GetExpectedMilkForGlass(glass, m_americanoWater, m_americanoSugar,
		m_americanoMilk);

	uint32_t expectedSugar = GetExpectedSugarForGlass(glass, m_americanoWater, m_americanoSugar,
		m_americanoMilk);

	uint32_t expectedWater = GetExpectedWaterForGlass(glass, m_americanoWater, m_americanoSugar,
		m_americanoMilk);
	
	if (expected > total)
	{
		return false;
	}

	if (expectedCoffee > m_coffee)
	{
		return false;
	}

	if (expectedMilk > m_milk)
	{
		return false;
	}

	if (expectedWater > m_water)
	{
		return false;
	}

	m_coffee -= expectedCoffee;
	m_milk -= expectedMilk;
	m_sugar -= expectedSugar;
	m_water -= expectedWater;
	 
	PrintAmericano(glass, expectedCoffee, expectedWater, expectedSugar, expectedMilk);
	return true;
}

bool MyCoffeeMachine::MakeLatte(Glasses)
{
	return false;
}

uint32_t MyCoffeeMachine::GetTotalVolume() const
{
	return m_milk + m_sugar + m_water;
}

void MyCoffeeMachine::PrintAmericano(Glasses glas, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	Print("Americano's", glas, coffee, water, sugar, milk);
}

void MyCoffeeMachine::PrintLatte(Glasses glas, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	Print("Latte's", glas, coffee, water, sugar, milk);
}

uint32_t MyCoffeeMachine::GetExpectedCoffeForGlass(Glasses glass)
{
	switch (glass)
	{
	case SMALL:
		return 1;
		break;

	case MIDD:
		return 2;
		break;

	case BIG:
		return 3;
		break;

	default:
		return 0;
		break;
	}
}

uint32_t MyCoffeeMachine::GetExpectedMilkForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk)
{
	double d_milk = 1.0 * static_cast<double>(glass) * milk / (water + sugar + milk);
	return static_cast<uint32_t>(ceil(d_milk));
}

uint32_t MyCoffeeMachine::GetExpectedSugarForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk)
{
	double d_sugar = 1.0 * static_cast<double>(glass) * sugar / (water + sugar + milk);
	return static_cast<uint32_t>(ceil(d_sugar));
}

uint32_t MyCoffeeMachine::GetExpectedWaterForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk)
{
	double d_water = 1.0 * static_cast<double>(glass) * water / (water + sugar + milk);
	return static_cast<uint32_t>(ceil(d_water));
}

bool MyCoffeeMachine::IsValidRecepte(uint32_t water, uint32_t sugar, uint32_t milk)
{
	if (water > m_water)
	{
		return false;
	}

	if (sugar > m_sugar)
	{
		return false;
	}

	if (milk > m_milk)
	{
		return false;
	}
	return true;
}

void MyCoffeeMachine::Print(uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	using namespace std;
	cout << endl;
	cout << "coffe:\t" << coffee << endl;
	cout << "milk:\t" << milk << endl;
	cout << "sugar:\t" << sugar << endl;
	cout << "water:\t" << water << endl;
	cout << "**********************************************\n";
}

void MyCoffeeMachine::Print(char const* str, Glasses glas, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	using namespace std;
	switch (glas)
	{
	case SMALL:
		cout << "\n\t" << str << " Small glass ingridients\n";
		break;

	case MIDD:
		cout << "\n\t" << str << " Middle glass ingridients\n";
		break;

	case BIG:
		cout << "\n\t Big glass ingridients\n";
		break;

	default:
		break;
	}

	Print(coffee, water, sugar, milk);
}

