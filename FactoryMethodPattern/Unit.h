#pragma once

enum class UnitType
{
	WARRIOR,
	ARCHER,
	WIZARD,
	MAX
};

class Unit
{
public:
	Unit() = default;
	virtual ~Unit() {}

public:
	virtual UnitType GetUnitType() const = 0;

	virtual void Attack() = 0;

	virtual void Move() = 0;

	virtual void Reset() = 0;
};

class Warrior : public Unit
{
public:
	virtual UnitType GetUnitType() const { return UnitType::WARRIOR; }

	virtual void Attack() override;

	virtual void Move() override;

	virtual void Reset() override;
};

class Archer : public Unit
{
public:
	virtual UnitType GetUnitType() const { return UnitType::ARCHER; }

	virtual void Attack() override;

	virtual void Move() override;

	virtual void Reset() override;
};

class Wizard : public Unit
{
public:
	virtual UnitType GetUnitType() const { return UnitType::WIZARD; }

	virtual void Attack() override;

	virtual void Move() override;

	virtual void Reset() override;
};