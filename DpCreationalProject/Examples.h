#pragma once
#include <vector>
#include "FactoryMethod.h"
#include "SpearmanUnit.h"
#include "AbstractFactory.h"
#include "Builder.h"

enum UnitType
{
    Infantry,
    Archer,
    Cavalry
};

class Army
{
public:
    std::string Title;
    Army(std::string title) : Title{ title } {};


    std::vector<InfantryUnit*> Infantries;
    std::vector<ArcherUnit*> Archers;
    std::vector<CavalryUnit*> Cavalries;
    std::vector<Unit*> Specials;

    ~Army()
    {
        for (int i{}; i < Infantries.size(); i++) delete Infantries[i];
        for (int i{}; i < Archers.size(); i++) delete Archers[i];
        for (int i{}; i < Cavalries.size(); i++) delete Cavalries[i];
        for (int i{}; i < Specials.size(); i++) delete Specials[i];
    }

    void PrintInfo()
    {
        std::cout << "Army: " << Title << "\n";
        std::cout << std::string(6 + Title.length(), '-') << "\n";

        for (auto u : Infantries)
            std::cout << "\t" << u->Name() << "\n";
        for (auto u : Archers)
            std::cout << "\t" << u->Name() << "\n";
        for (auto u : Cavalries)
            std::cout << "\t" << u->Name() << "\n";
        for (auto u : Specials)
            std::cout << "\t" << u->Name() << "\n";
        std::cout << "\n\n";
    }
};

Army* Game(std::string title, ArmyFactory* factory)
{
    Army* army = new Army(title);

    for (int i{}; i < 10; i++)
        army->Infantries.push_back(factory->CreateInfantry());
    for (int i{}; i < 5; i++)
        army->Archers.push_back(factory->CreateArcher());
    for (int i{}; i < 5; i++)
        army->Cavalries.push_back(factory->CreateCavalry());
    for (int i{}; i < 3; i++)
        army->Specials.push_back(factory->CreateSpecial());

    return army;
}


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

    static void AbstractFactory()
    {
        Army* romeArmy = Game("Roman Great Army", new RomeArmyFactory());
        Army* punicArmy = Game("Garthaginian Good Army", new PunicArmyFactory());

        romeArmy->PrintInfo();
        punicArmy->PrintInfo();
    }

    static void Builder()
    {
        UnitBuilder* builder = new UnitBuilder("SuperUnit");

        EquipUnit* unit = builder->SetSpeed(10)
            ->SetAttack(10)
            ->SetDefense(10)
            ->AddHorse()
            ->AddBow()
            ->AddSpear()
            ->AddShield()
            ->AddSword()
            ->Create();

        std::cout << unit->ToString();

        builder->Reset("Infantry")
            ->SetSpeed(1)
            ->SetAttack(3)
            ->SetDefense(5)
            ->AddSword()
            ->AddShield();

        EquipUnit* unit2 = (new UnitDirector())->GetInfantry();
        std::cout << unit2->ToString() << "\n";
    }
};

