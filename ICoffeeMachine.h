#pragma once

#include <string>

enum GlassesWeights {
	GlasWgInvalid = 0,
	GlasWgSmall = 75,
	GlasWgMidd = 125,
	GlasWgBig = 175
};

enum GlassesType {
	GlassTypeInvalid,
	GlassTypeSmall,
	GlassTypeMidd,
	GlassTypeBig
};



class ICoffeeMachine {
public:
	virtual bool MakeSmallGlassByRecept(std::string const& name) = 0;
	virtual bool MakeMiddleGlassByRecept(std::string const& name) = 0;
	virtual bool MakeBigGlassByRecept(std::string const& name) = 0;
	virtual ~ICoffeeMachine() = default;
};
