#pragma once

#include <string>

enum Glasses {
	SMALL = 75,
	MIDD = 125,
	BIG = 175
};

class ICoffeeMachine {
public:
	virtual bool MakeRecept(std::string const& name, Glasses glass) = 0;
	virtual ~ICoffeeMachine() = default;
};
