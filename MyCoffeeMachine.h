#pragma once

#include "ICoffeeMachine.h"
#include "ICoffeeMachineRecipe.h"
#include <string>
#include <vector>

class MyCoffeeMachine : public ICoffeeMachine,
						public ICoffeeMachineRecipe
{
private:
	uint32_t m_water = 0;
	uint32_t m_coffee= 0;
	uint32_t m_sugar = 0;
	uint32_t m_milk = 0;

	std::vector<Recept> m_recepts;
	
	uint32_t m_americanoWater = 0;
	uint32_t m_americanoSugar = 0;
	uint32_t m_americanoMilk = 0;

	uint32_t m_lateWater = 0;
	uint32_t m_lateSugar = 0;
	uint32_t m_lateMilk = 0;

	static const uint32_t waterTankVol = 2500;
	static const uint32_t milkTankVol = 1000;
	static const uint32_t coffeeTankVol = 250;
	static const uint32_t sugarTankVol = 250;

public:
	MyCoffeeMachine() = default;

	bool SetRecipe(uint32_t water, uint32_t sugar, uint32_t milk, std::string const& name) override;
	bool MakeRecept(std::string const& name, Glasses glas) override;
	Recept* GetRecipe(std::string const& name) override;

	void Load();
	bool AddCoffee(uint32_t coffee);
	bool AddMilk(uint32_t milk);
	bool AddSugar(uint32_t sugar);
	bool AddWater(uint32_t water);

	uint32_t GetTotalVolume() const;
	void PrintRecipes() const;
	void Print(Recept const* r, Glasses glas) const;

private:
	uint32_t GetExpectedCoffeForGlass(Glasses glass) const;
	uint32_t GetExpectedMilkForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk) const;
	uint32_t GetExpectedSugarForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk) const;
	uint32_t GetExpectedWaterForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk) const;

	bool IsValidRecepte(uint32_t water, uint32_t sugar, uint32_t milk) const;
	bool IsValid(uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;

	void Print(uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;
	void Print(std::string const& name, Glasses glass, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;
	double GetExpextedComponent(Glasses glass, uint32_t comp, uint32_t second, uint32_t third) const;
	bool AddComponent(uint32_t& comp, uint32_t addValue, uint32_t max);
};

