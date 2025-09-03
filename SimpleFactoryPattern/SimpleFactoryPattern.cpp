
#include <iostream>
#include <vector>
#include "Unit.h"
#include "UnitFactory.h"

// 여러개의 자식 오브젝트들을 하나의 함수로 생성하기 위해 사용하는 패턴
int main()
{
    UnitFactory MyUnitFactory{};
    std::vector<std::shared_ptr<Unit>> CreatedUnits{};

    // 유닛 생성
    CreatedUnits.push_back(MyUnitFactory.PopUnit(UnitType::Warrior));
    CreatedUnits.push_back(MyUnitFactory.PopUnit(UnitType::Archer));
    CreatedUnits.push_back(MyUnitFactory.PopUnit(UnitType::Wizard));

    // 유닛 이동
    for (std::shared_ptr<Unit>& Unit : CreatedUnits)
    {
        if (Unit)
        {
            Unit->Move();
        }
    }
    
    // 유닛 삭제
    for (std::shared_ptr<Unit>& Unit : CreatedUnits)
    {
        MyUnitFactory.ReturnUnit(Unit);
    }
    CreatedUnits.clear();

    std::cout << "\n--------\n" << std::endl;

    // 새로운 유닛 생성
    CreatedUnits.push_back(MyUnitFactory.PopUnit(UnitType::Archer));
    CreatedUnits.push_back(MyUnitFactory.PopUnit(UnitType::Wizard));
    CreatedUnits.push_back(MyUnitFactory.PopUnit(UnitType::Archer));
    CreatedUnits.push_back(MyUnitFactory.PopUnit(UnitType::Warrior));

    // 유닛 이동
    for (std::shared_ptr<Unit>& Unit : CreatedUnits)
    {
        if (Unit)
        {
            Unit->Move();
        }
    }

    // 유닛 삭제
    for (std::shared_ptr<Unit>& Unit : CreatedUnits)
    {
        MyUnitFactory.ReturnUnit(Unit);
    }
    CreatedUnits.clear();

    return 0;
}
