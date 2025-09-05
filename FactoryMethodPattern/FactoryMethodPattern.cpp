#include <iostream>
#include <unordered_map>
#include "Factory.h"

int main()
{
    std::unordered_map<MonsterWaveGeneratorType, MonsterWaveGenerator*> MonsterWaveGeneratorMap{};
    MonsterWaveGeneratorMap.emplace(MonsterWaveGeneratorType::TYPE_A, new MonsterWaveGeneratorA());
    MonsterWaveGeneratorMap.emplace(MonsterWaveGeneratorType::TYPE_B, new MonsterWaveGeneratorB());

    // 몬스터 그룹 생성 후 이동
    for (int i = 0; i < (int)MonsterWaveGeneratorType::MAX; i++)
    {
        MonsterWaveGeneratorType Type = (MonsterWaveGeneratorType)i;
        if (MonsterWaveGeneratorMap.count(Type))
        {
            MonsterWaveGeneratorMap[Type]->Init();
            MonsterWaveGeneratorMap[Type]->CreateMonsterWave();

            std::unordered_set<Unit*> CreatedUnitList{};
            MonsterWaveGeneratorMap[Type]->GetCreatedUnitList(CreatedUnitList);

            for (Unit* FindUnit : CreatedUnitList)
            {
                if (FindUnit)
                {
                    FindUnit->Move();
                }
            }
        }
    }

    // 몬스터 그룹 공격
    for (int i = 0; i < (int)MonsterWaveGeneratorType::MAX; i++)
    {
        MonsterWaveGeneratorType Type = (MonsterWaveGeneratorType)i;

        if (MonsterWaveGeneratorMap.count(Type))
        {
            std::unordered_set<Unit*> CreatedUnitList{};
            MonsterWaveGeneratorMap[Type]->GetCreatedUnitList(CreatedUnitList);
            for (Unit* FindUnit : CreatedUnitList)
            {
                if(FindUnit)
                {
                    FindUnit->Attack();
                }
            }
        }
    }

    // 몬스터 그룹 삭제
    for (int i = 0; i < (int)MonsterWaveGeneratorType::MAX; i++)
    {
        MonsterWaveGeneratorType Type = (MonsterWaveGeneratorType)i;
        
        if (MonsterWaveGeneratorMap.count(Type))
        {
            std::unordered_set<Unit*> CreatedUnitList{};
            MonsterWaveGeneratorMap[Type]->GetCreatedUnitList(CreatedUnitList);
            for (Unit* FindUnit : CreatedUnitList)
            {
                MonsterWaveGeneratorMap[Type]->ReturnUnit(FindUnit);
            }
        }
    }
}
