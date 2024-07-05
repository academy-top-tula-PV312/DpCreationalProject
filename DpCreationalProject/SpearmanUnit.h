#pragma once
#include "FactoryMethod.h"

class SpearmenUnit : public Unit
{
public:
	SpearmenUnit() : Unit("Spearmen", 1, 4, 3) {};
};

class SpearmenFactory : public UnitFactory
{
public:
	Unit* Create() override
	{
		return new SpearmenUnit();
	}
};