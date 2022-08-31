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
	uint32_t m_americanoCoffee = 0;
	uint32_t m_americanoSugar = 0;
	uint32_t m_americanoMilk = 0;

	// for set proportions for Late
	uint32_t m_lateWater = 0;
	uint32_t m_lateCoffee = 0;
	uint32_t m_lateSugar = 0;
	uint32_t m_lateMilk = 0;

	static const uint32_t one_glass = 125;
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
};

