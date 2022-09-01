#pragma once

typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;

#include <string>

struct Recept {
	uint32_t m_milk = 0;
	uint32_t m_sugar = 0;
	uint32_t m_water = 0;
	std::string m_name;
};

class ICoffeeMachineRecipe {
public:
	virtual ~ICoffeeMachineRecipe() = default;
	
	virtual bool SetRecipe(uint32_t milk, uint32_t sugar, uint32_t water, std::string const& name) = 0;
	virtual Recept const* GetRecipe(std::string const& name) const = 0;
};