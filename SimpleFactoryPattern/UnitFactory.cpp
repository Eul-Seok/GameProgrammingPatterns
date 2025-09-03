#include "UnitFactory.h"
#include <iostream>

std::shared_ptr<Unit> UnitFactory::PopUnit(UnitType Type)
{
	std::shared_ptr<Unit> NewUnit{};

	if (false == ObjectPools[Type].empty())
	{
		NewUnit = ObjectPools[Type].front();
		ObjectPools[Type].pop();
	}
	else
	{
		switch (Type) 
		{
			case UnitType::Warrior:
			{
				NewUnit = std::make_shared<Warrior>();
				break;
			}
			case UnitType::Archer:
			{
				NewUnit = std::make_shared<Archer>();
				break;
			}
			case UnitType::Wizard:
			{
				NewUnit = std::make_shared<Wizard>();
				break;
			}
			default:
			{
				std::cerr << "알 수 없는 UnitType " << static_cast<int>(Type) << std::endl;
				break;
			}
		}
	}

	return NewUnit;
};

void UnitFactory::ReturnUnit(std::shared_ptr<Unit> InUnit)
{
	if (nullptr == InUnit)
	{
		return;
	}

	InUnit->Reset();
	ObjectPools[InUnit->GetUnitType()].push(InUnit);
}

void UnitFactory::Clear()
{
	for (std::pair<const UnitType, std::queue <std::shared_ptr<Unit>>>& Pair : ObjectPools)
	{
		while (!Pair.second.empty())
		{
			Pair.second.pop();
		}
	}
}
