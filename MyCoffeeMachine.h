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
	
	static const uint32_t waterTankVol = 2500;
	static const uint32_t milkTankVol = 1000;
	static const uint32_t coffeeTankVol = 250;
	static const uint32_t sugarTankVol = 250;

public:
	MyCoffeeMachine() = default;

	bool MakeSmallGlassByRecept(std::string const& name) override;
	bool MakeMiddleGlassByRecept(std::string const& name) override;
	bool MakeBigGlassByRecept(std::string const& name) override;

	bool SetRecipe(uint32_t water, uint32_t sugar, uint32_t milk, std::string const& name) override;
	Recept const* GetRecipe(std::string const& name) const override;

	void Load();
	bool AddCoffee(uint32_t coffee);
	bool AddMilk(uint32_t milk);
	bool AddSugar(uint32_t sugar);
	bool AddWater(uint32_t water);

	uint32_t GetTotalVolume() const;
	void PrintRecipes() const;
	void Print(std::string const& recept, GlassesType glas) const;

private:
	uint32_t GetExpectedCoffeForGlass(GlassesWeights glass) const;
	uint32_t GetExpectedMilkForGlass(GlassesWeights glass, uint32_t water, uint32_t sugar, uint32_t milk) const;
	uint32_t GetExpectedSugarForGlass(GlassesWeights glass, uint32_t water, uint32_t sugar, uint32_t milk) const;
	uint32_t GetExpectedWaterForGlass(GlassesWeights glass, uint32_t water, uint32_t sugar, uint32_t milk) const;

	bool IsValidRecepte(uint32_t water, uint32_t sugar, uint32_t milk) const;
	bool IsValid(uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;

	void Print(uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;
	void Print(std::string const& name, GlassesWeights glass, uint32_t coffee, uint32_t water, uint32_t sugar, uint32_t milk) const;
	void Print(Recept const* r, GlassesWeights glas) const;
	double GetExpextedComponent(GlassesWeights glass, uint32_t comp, uint32_t second, uint32_t third) const;
	bool AddComponent(uint32_t& comp, uint32_t addValue, uint32_t max);
	bool MakeRecept(std::string const& name, GlassesWeights glas);
};

