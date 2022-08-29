#pragma once

class ICoffeeMachine {
public:
	virtual bool MakeAmericano() = 0;
	virtual bool MakeLatte() = 0;
	virtual ~ICoffeeMachine() {}
};
