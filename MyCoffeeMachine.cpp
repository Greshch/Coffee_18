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
	return AddComponent(m_coffee, coffee, coffeeTankVol);
}

bool MyCoffeeMachine::AddMilk(uint32_t milk)
{
	return AddComponent(m_milk, milk, milkTankVol);
}

bool MyCoffeeMachine::AddSugar(uint32_t sugar)
{
	return AddComponent(m_sugar, sugar, sugarTankVol);
}

bool MyCoffeeMachine::AddWater(uint32_t water)
{
	return AddComponent(m_water, water, waterTankVol);
}

uint32_t MyCoffeeMachine::GetTotalVolume() const
{
	return m_milk + m_sugar + m_water;
}

void MyCoffeeMachine::PrintRecipes() const
{
	for (auto const& r : m_recepts)
	{
		std::cout << r.m_name << "\n";
	}
}

void MyCoffeeMachine::Print(std::string const& recept, GlassesType glas) const
{
	Recept const* curRec = GetRecipe(recept);
	GlassesWeights weig = GlassesWeights::GlasWgInvalid;
	if (glas == GlassesType::GlassTypeSmall)
	{
		weig = GlassesWeights::GlasWgSmall;
	}
	else if (glas == GlassesType::GlassTypeMidd)
	{
		weig = GlassesWeights::GlasWgMidd;
	}
	else if (glas == GlassesType::GlassTypeBig)
	{
		weig = GlassesWeights::GlasWgBig;
	}
	Print(curRec, weig);
}

bool MyCoffeeMachine::MakeSmallGlassByRecept(std::string const& name)
{
	return MakeRecept(name, GlassesWeights::GlasWgSmall);
}

bool MyCoffeeMachine::MakeMiddleGlassByRecept(std::string const& name)
{
	return MakeRecept(name, GlassesWeights::GlasWgMidd);
}

bool MyCoffeeMachine::MakeBigGlassByRecept(std::string const& name)
{
	return MakeRecept(name, GlassesWeights::GlasWgBig);
}

bool MyCoffeeMachine::SetRecipe(uint32_t milk, uint32_t sugar, uint32_t water, std::string const& name)
{
	if (!IsValidRecepte(water, sugar, milk))
	{
		return false;
	}

	m_recepts.push_back({ milk, sugar, water, name });
	return true;
}

bool MyCoffeeMachine::MakeRecept(std::string const& name, GlassesWeights glass)
{
	Recept const* recept = GetRecipe(name);
	if (recept == nullptr)
	{
		return false;
	}
	uint32_t expected = static_cast<uint32_t>(glass);
	uint32_t total = GetTotalVolume();
	uint32_t expectedCoffee = GetExpectedCoffeForGlass(glass);
	uint32_t expectedMilk = GetExpectedMilkForGlass(glass, recept->m_water, recept->m_sugar,
		recept->m_milk);

	uint32_t expectedSugar = GetExpectedSugarForGlass(glass, recept->m_water, recept->m_sugar,
		recept->m_milk);

	uint32_t expectedWater = GetExpectedWaterForGlass(glass, recept->m_water, recept->m_sugar,
		recept->m_milk);

	if (expected > total)
	{
		return false;
	}

	if (!IsValid(expectedCoffee, expectedWater, expectedSugar, expectedMilk))
	{
		return false;
	}

	m_coffee -= expectedCoffee;
	m_milk -= expectedMilk;
	m_sugar -= expectedSugar;
	m_water -= expectedWater;
	return true;
}

Recept const* MyCoffeeMachine::GetRecipe(std::string const& name) const
{
	for (auto & recipe : m_recepts)
	{
		if (recipe.m_name == name)
		{
			return &recipe;
		}
	}
	return nullptr;
}

uint32_t MyCoffeeMachine::GetExpectedCoffeForGlass(GlassesWeights glass) const
{
	switch (glass)
	{
	case GlasWgSmall:
		return 1;
		break;

	case GlasWgMidd:
		return 2;
		break;

	case GlasWgBig:
		return 3;
		break;

	default:
		return 0;
		break;
	}
}

uint32_t MyCoffeeMachine::GetExpectedMilkForGlass(GlassesWeights glass, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	double d_milk = GetExpextedComponent(glass, milk, water, sugar);
	return static_cast<uint32_t>(ceil(d_milk));
}

uint32_t MyCoffeeMachine::GetExpectedSugarForGlass(GlassesWeights glass, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	double d_sugar = GetExpextedComponent(glass, sugar, water, milk);
	return static_cast<uint32_t>(ceil(d_sugar));
}

uint32_t MyCoffeeMachine::GetExpectedWaterForGlass(GlassesWeights glass, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	double d_water = GetExpextedComponent(glass, water, sugar, milk);
	return static_cast<uint32_t>(ceil(d_water));
}

bool MyCoffeeMachine::IsValidRecepte(uint32_t water, uint32_t sugar, uint32_t milk) const
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

bool MyCoffeeMachine::IsValid(uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	if (coffee > m_coffee)
	{
		return false;
	}

	if (milk > m_milk)
	{
		return false;
	}

	if (water > m_water)
	{
		return false;
	}

	if (sugar > m_sugar)
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

void MyCoffeeMachine::Print(Recept const* r, GlassesWeights glas) const
{
	uint32_t curCoffee = GetExpectedCoffeForGlass(glas);
	uint32_t curWater = GetExpectedWaterForGlass(glas, r->m_water, r->m_sugar, r->m_milk);
	uint32_t curSugar = GetExpectedSugarForGlass(glas, r->m_water, r->m_sugar, r->m_milk);
	uint32_t curMilk = GetExpectedMilkForGlass(glas, r->m_water, r->m_sugar, r->m_milk);

	Print(r->m_name,
		glas, 
		curCoffee, 
		curWater, 
		curSugar, 
		curMilk);
}

void MyCoffeeMachine::Print(std::string const& name, GlassesWeights glas, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const
{
	using namespace std;
	switch (glas)
	{
	case GlasWgSmall:
		cout << "\n\t" << name << " GlasWgSmall's glass ingridients\n";
		break;

	case GlasWgMidd:
		cout << "\n\t" << name << " GlasWgMiddle's glass ingridients\n";
		break;

	case GlasWgBig:
		cout << "\n\t" << name << " GlasWgBig's glass ingridients\n";
		break;

	default:
		break;
	}

	Print(coffee, water, sugar, milk);
}

double MyCoffeeMachine::GetExpextedComponent(GlassesWeights glass, uint32_t comp, uint32_t second, uint32_t third) const
{
	return static_cast<double>(glass) * comp / (1.0 *comp + second + third);
}

bool MyCoffeeMachine::AddComponent(uint32_t& comp, uint32_t value, uint32_t max)
{
	if (comp + value > max)
	{
		return false;
	}
	comp += value;
	return true;
}

