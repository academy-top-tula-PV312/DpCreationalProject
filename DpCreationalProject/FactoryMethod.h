#pragma once
#include "Unit.h"

class UnitFactory
{
public:
	virtual Unit* Create() = 0;
	virtual ~UnitFactory() {}
};

class InfantryFactory : public UnitFactory
{
public:
	Unit* Create() override
	{
		return new InfantryUnit();
	}
};

class ArcherFactory : public UnitFactory
{
public:
	Unit* Create() override
	{
		return new ArcherUnit();
	}
};

class CavalryFactory : public UnitFactory
{
public:
	Unit* Create() override
	{
		return new CavalryUnit();
	}
};

