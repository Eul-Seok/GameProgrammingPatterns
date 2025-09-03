#pragma once

#include <map>
#include <queue>
#include <memory>
#include "Unit.h"


class UnitFactory
{
private:
    std::map<UnitType, std::queue<std::shared_ptr<Unit>>> ObjectPools;

public:
    UnitFactory() = default;
    ~UnitFactory() { Clear(); }

public:
    std::shared_ptr<Unit> PopUnit(UnitType Type);

    void ReturnUnit(std::shared_ptr<Unit> InUnit);

    void Clear();
};