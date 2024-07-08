#pragma once
#include "Unit.h"

template <typename T>
class Builder
{
public:
	virtual T* Create() = 0;
};

class UnitBuilder : public Builder<Unit>
{
	EquipUnit* unit = nullptr;
public:
	UnitBuilder(std::string name, EquipUnit* unit = nullptr)
	{
		if (!unit)
			this->unit = new EquipUnit(name);
	}

	UnitBuilder* Reset(std::string name)
	{
		this->unit = new EquipUnit(name);
		return this;
	}

	UnitBuilder* AddHorse() 
	{ 
		unit->Horse() = true; 
		unit->Speed() += 3;
		return this; 
	}

	UnitBuilder* AddBow()
	{
		unit->Bow() = true;
		unit->Attack() += 2;
		return this;
	}

	UnitBuilder* AddSword()
	{
		unit->Sword() = true;
		unit->Attack() += 3;
		return this;
	}

	UnitBuilder* AddShield()
	{
		unit->Shield() = true;
		unit->Defense() += 3;
		return this;
	}

	UnitBuilder* AddSpear()
	{
		unit->Spear() = true;
		unit->Attack() += 1;
		unit->Defense() += 2;
		return this;
	}

	UnitBuilder* AddEquip(std::string equip)
	{
		//unit->AddEquip(equip);
		unit->Equips().push_back(equip);
		return this;
	}

	UnitBuilder* SetSpeed(int speed)
	{
		unit->Speed() = speed;
		return this;
	}

	UnitBuilder* SetAttack(int attack)
	{
		unit->Attack() = attack;
		return this;
	}

	UnitBuilder* SetDefense(int defense)
	{
		unit->Defense() = defense;
		return this;
	}

	EquipUnit* Create() override
	{
		return unit;
	}
};

class UnitDirector
{
	UnitBuilder* builder;
public:
	EquipUnit* GetInfantry()
	{
		builder = new UnitBuilder("Infantry");
		return builder
				->SetSpeed(1)
				->SetAttack(3)
				->SetDefense(5)
				->AddSword()
				->AddShield()
				->Create();
	}

};