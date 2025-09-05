#include "Factory.h"

MonsterWaveGenerator::~MonsterWaveGenerator()
{
	for (Unit* FindUnit : CreatedUnitList)
	{
		ReturnUnit(FindUnit);
	}

	ObjectPoolByUnitType.clear();
}

void MonsterWaveGenerator::Init()
{
	ObjectPoolByUnitType.emplace(UnitType::WARRIOR, std::make_unique<UnitObjectPool<Warrior>>());
	ObjectPoolByUnitType.emplace(UnitType::ARCHER, std::make_unique<UnitObjectPool<Archer>>());
	ObjectPoolByUnitType.emplace(UnitType::WIZARD, std::make_unique<UnitObjectPool<Wizard>>());
	
	ObjectPoolByUnitType[UnitType::WARRIOR]->Init(3);
	ObjectPoolByUnitType[UnitType::ARCHER]->Init(3);
	ObjectPoolByUnitType[UnitType::WIZARD]->Init(3);
}

Unit* MonsterWaveGenerator::PopUnit(UnitType Type)
{
	if(ObjectPoolByUnitType.count(Type))
	{
		return ObjectPoolByUnitType[Type]->Pop();
	}
	return nullptr;
}

void MonsterWaveGenerator::ReturnUnit(Unit* InUnit)
{
	if (nullptr == InUnit)
	{
		return;
	}
	
	const UnitType Type = InUnit->GetUnitType();
	if (ObjectPoolByUnitType.count(Type))
	{
		CreatedUnitList.erase(InUnit);
		InUnit->Reset();

		ObjectPoolByUnitType[Type]->Return(InUnit);
	}
}

void MonsterWaveGeneratorA::CreateMonsterWave()
{
	CreatedUnitList.emplace(PopUnit(UnitType::WARRIOR));
	CreatedUnitList.emplace(PopUnit(UnitType::WARRIOR));
	CreatedUnitList.emplace(PopUnit(UnitType::WIZARD));
}

void MonsterWaveGeneratorB::CreateMonsterWave()
{
	CreatedUnitList.emplace(PopUnit(UnitType::ARCHER));
	CreatedUnitList.emplace(PopUnit(UnitType::ARCHER));
	CreatedUnitList.emplace(PopUnit(UnitType::ARCHER));
	CreatedUnitList.emplace(PopUnit(UnitType::ARCHER));
}
