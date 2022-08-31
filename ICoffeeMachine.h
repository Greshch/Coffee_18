#pragma once

enum Glasses {
	SMALL = 75,
	MIDD = 125,
	BIG = 175
};

class ICoffeeMachine {
public:
	virtual bool MakeAmericano(Glasses) = 0;
	virtual bool MakeLatte(Glasses) = 0;
	virtual ~ICoffeeMachine() {}
};
