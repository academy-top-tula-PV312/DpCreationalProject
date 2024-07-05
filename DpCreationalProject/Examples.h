#pragma once
#include <vector>
#include "FactoryMethod.h"
#include "SpearmanUnit.h"

enum UnitType
{
    Infantry,
    Archer,
    Cavalry
};

static class Examples
{
public:
    static Unit* NonPatternsUnitCreator(UnitType type)
    {
        Unit* unit;
        switch (type)
        {
        case Infantry:
            unit = new InfantryUnit();
            break;
        case Archer:
            unit = new ArcherUnit();
            break;
        case Cavalry:
            unit = new CavalryUnit();
            break;
        default:
            unit = nullptr;
            break;
        }

        return unit;
    }

	static void FactoryMethod()
	{
        std::vector<UnitFactory*> factories;
        factories.push_back(new InfantryFactory());
        factories.push_back(new ArcherFactory());
        factories.push_back(new CavalryFactory());
        factories.push_back(new SpearmenFactory());

        std::vector<Unit*> armyRome;
        for (int i{}; i < 10; i++)
        {
            int randIndex = rand() % factories.size();
            auto factory = factories[randIndex];
            auto unit = factory->Create();
            armyRome.push_back(unit);
        }

        for (auto unit : armyRome)
            std::cout << unit->Name() << "\n";
	}
};

