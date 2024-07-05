#pragma once
#include <iostream>

class Unit
{
	std::string name;
	int speed;
	int attack;
	int defense;
public:
	Unit(std::string name)
		: name{ name },
		speed{},
		attack{},
		defense{} {}

	Unit(std::string name, int speed, int attack, int defense)
		: name{ name },
		speed{ speed },
		attack{ attack },
		defense{ defense } {}

	std::string& Name() { return name; }
	int& Speed() { return speed; }
	int& Attack() { return attack; }
	int& Defense() { return defense; }

	virtual ~Unit() {}
};

class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry", 1, 3, 5) {};
};

class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer", 1, 5, 3) {};
};

class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry", 5, 7, 4) {};
};


// ROME UNITS
class RomeInfantryUnit : public InfantryUnit
{
public:
	RomeInfantryUnit()
	{
		this->Name() += " Rome";
		this->Attack()++;
		this->Defense()--;
	}
};

class RomeArcherUnit : public ArcherUnit
{
public:
	RomeArcherUnit()
	{
		this->Name() += " Rome";
	}
};

class RomeCavalryUnit : public CavalryUnit
{
public:
	RomeCavalryUnit()
	{
		this->Name() += " Rome";
	}
};

class RomeÑhariotUnit : public Unit
{
public:
	RomeÑhariotUnit() : Unit("Chariot Rome", 7, 8, 5) {}
};


// CARTHAGINIAN == Punic
class PunicInfantryUnit : public InfantryUnit
{
public:
	PunicInfantryUnit()
	{
		this->Name() += " Punic";
		this->Defense()++;
		this->Attack()--;
	}
};

class PunicArcherUnit : public ArcherUnit
{
public:
	PunicArcherUnit()
	{
		this->Name() += " Punic";
	}
};

class PunicCavalryUnit : public CavalryUnit
{
public:
	PunicCavalryUnit()
	{
		this->Name() += " Punic";
	}
};

class PunicElephantUnit : public Unit
{
public:
	PunicElephantUnit() : Unit("Elephant Punic", 4, 10, 6) {}
};
