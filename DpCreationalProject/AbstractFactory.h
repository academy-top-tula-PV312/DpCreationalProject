#pragma once
#include <map>

#include "FactoryMethod.h"

class ArmyFactory
{
public:
	virtual InfantryUnit* CreateInfantry() = 0;
	virtual ArcherUnit* CreateArcher() = 0;
	virtual CavalryUnit* CreateCavalry() = 0;
	virtual Unit* CreateSpecial() = 0;
};

class RomeArmyFactory : public ArmyFactory
{
public:
	InfantryUnit* CreateInfantry() override
	{
		return new RomeInfantryUnit();
	}
	
	ArcherUnit* CreateArcher() override
	{
		return new RomeArcherUnit();
	}

	CavalryUnit* CreateCavalry() override
	{
		return new RomeCavalryUnit();
	}

	Unit* CreateSpecial() override
	{
		return new Rome—hariotUnit();
	}
};

class PunicArmyFactory : public ArmyFactory
{
public:
	InfantryUnit* CreateInfantry() override
	{
		return new PunicInfantryUnit();
	}

	ArcherUnit* CreateArcher() override
	{
		return new PunicArcherUnit();
	}

	CavalryUnit* CreateCavalry() override
	{
		return new PunicCavalryUnit();
	}

	Unit* CreateSpecial() override
	{
		return new PunicElephantUnit();
	}
};



class UnitUniversalFactory
{
	std::map<std::string, UnitFactory*> factories;

public:
	void AddFactory(std::string title, UnitFactory* factory)
	{
		factories[title] = factory;
	}

	void RemoveFactory(std::string title)
	{
		if (factories.contains(title))
			factories.erase(title);
	}

	UnitFactory* GetFactory(std::string title)
	{
		if(factories.contains(title))
			return factories[title];

		return nullptr;
	}

	Unit* CreateUnit(std::string title)
	{
		if (factories.contains(title))
			return factories[title]->Create();

		return nullptr;
	}
};

class ArmyUniversalFactory
{
	std::map<std::string, UnitUniversalFactory*> armyFactories;
};


