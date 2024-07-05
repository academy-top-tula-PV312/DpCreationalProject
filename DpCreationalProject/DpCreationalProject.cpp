#include <iostream>
#include "Examples.h"

#include "AbstractFactory.h"

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


int main()
{
    //Examples::FactoryMethod();
        
    Army* romeArmy = Game("Roman Great Army", new RomeArmyFactory());
    Army* punicArmy = Game("Garthaginian Good Army", new PunicArmyFactory());

    romeArmy->PrintInfo();
    punicArmy->PrintInfo();

}


