#pragma once

typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;

class ICoffeeMachineRecipe {
public:
	virtual ~ICoffeeMachineRecipe() {}
	virtual bool SetAmericanoRecipe(uint32_t water, uint32_t sugar, uint32_t milk) = 0;
	virtual bool SetLatteRecipe(uint32_t water, uint32_t sugar, uint32_t milk) = 0;
};