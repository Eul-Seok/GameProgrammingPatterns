#pragma once

enum class UnitType
{
	Warrior,
	Archer,
	Wizard
};

class Unit
{
public:
	Unit() = default;
	virtual ~Unit() {}

	virtual UnitType GetUnitType() const = 0;

	virtual void Move() = 0;

	virtual void Reset() = 0;
};

class Warrior : public Unit
{
	virtual UnitType GetUnitType() const { return UnitType::Warrior; }

	virtual void Move() override;

	virtual void Reset() override
	{
		//�ʱ�ȭ
	}
};

class Archer : public Unit
{
	virtual UnitType GetUnitType() const { return UnitType::Archer; }

	virtual void Move() override;

	virtual void Reset() override
	{
		//�ʱ�ȭ
	}
};

class Wizard : public Unit
{
	virtual UnitType GetUnitType() const { return UnitType::Wizard; }

	virtual void Move() override;

	virtual void Reset() override
	{
		//�ʱ�ȭ
	}
};