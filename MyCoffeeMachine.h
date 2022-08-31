#pragma once

#include "ICoffeeMachine.h"
#include "ICoffeeMachineRecipe.h"

class MyCoffeeMachine : public ICoffeeMachine,
						public ICoffeeMachineRecipe
{
private:
	uint32_t m_water = 0;
	uint32_t m_coffee= 0;
	uint32_t m_sugar = 0;
	uint32_t m_milk = 0;

	// for set proportions for Americano
	uint32_t m_americanoWater = 0;
	uint32_t m_americanoSugar = 0;
	uint32_t m_americanoMilk = 0;

	// for set proportions for Late
	uint32_t m_lateWater = 0;
	uint32_t m_lateCoffee = 0;
	uint32_t m_lateSugar = 0;
	uint32_t m_lateMilk = 0;

	static const uint32_t waterTankVol = 2500;
	static const uint32_t milkTankVol = 1000;
	static const uint32_t coffeeTankVol = 250;
	static const uint32_t sugarTankVol = 250;

public:
	MyCoffeeMachine() = default;
	void Load();
	bool AddCoffee(uint32_t coffee);
	bool AddMilk(uint32_t milk);
	bool AddSugar(uint32_t sugar);
	bool AddWater(uint32_t water);

	bool SetAmericanoRecipe(uint32_t water, uint32_t sugar, uint32_t milk) override;
	bool SetLatteRecipe(uint32_t water, uint32_t sugar, uint32_t milk) override;

	bool MakeAmericano(Glasses) override;
	virtual bool MakeLatte(Glasses) override;

	uint32_t GetTotalVolume() const;

	void PrintAmericano(Glasses glas, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;
	void PrintLatte(Glasses glas, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;

private:
	uint32_t GetExpectedCoffeForGlass(Glasses glass);
	uint32_t GetExpectedMilkForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk);
	uint32_t GetExpectedSugarForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk);
	uint32_t GetExpectedWaterForGlass(Glasses glass, uint32_t water, uint32_t sugar, uint32_t milk);

	bool IsValidRecepte(uint32_t water, uint32_t sugar, uint32_t milk);
	bool IsValid(uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk);

	void Print(uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;
	void Print(char const* str, Glasses glass, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;
};

