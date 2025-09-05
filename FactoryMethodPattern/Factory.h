#pragma once

#include <map>
#include <unordered_set>
#include <memory>
#include "Unit.h"
#include "ObjectPool.h"

enum class MonsterWaveGeneratorType
{
	TYPE_A,
	TYPE_B,
	MAX,
};

/**
 * @brief 몬스터 웨이브를 생성하는 팩토리 메서드 패턴 예제입니다.
 *
 * MonsterWaveGenerator는 유닛을 생성하는 기능을 제공하는 추상적인 'Creator' 역할을 합니다.
 * 자식 클래스인 MonsterWaveGeneratorA, MonsterWaveGeneratorB는 'CreateMonsterWave'라는
 * 팩토리 메서드를 오버라이드하여, 각자 다른 구성의 몬스터 웨이브(Product)를 생성합니다.
 * 클라이언트는 MonsterWaveGenerator의 구체적인 타입을 몰라도 CreateMonsterWave()를 호출하여
 * 원하는 결과물을 얻을 수 있습니다.
 *
 * --- 향후 확장 방향 ---
 * 1. 데이터 기반 설계:
 *    현재 각 CreateMonsterWave 함수 내부에 하드코딩된 웨이브 구성 로직을,
 *    외부 데이터 테이블(JSON, CSV 등)에서 '웨이브 목록'을 읽어와 처리하도록 개선하면
 *    코드를 재컴파일하지 않고도 새로운 웨이브를 쉽게 추가할 수 있습니다.
 *
 * 2. 전략 패턴(Strategy Pattern)과 연계:
 *    몬스터를 '어떻게' 생성할지(예: 한 번에 생성, 시간차를 두고 생성, 랜덤 순서로 생성 등)를
 *    전략 객체로 캡슐화하고, CreateMonsterWave가 이 전략을 선택하여 사용하도록 만들면
 *    단순히 무엇을 만드느냐를 넘어, 만드는 방식까지 동적으로 변경할 수 있는
 *    훨씬 유연한 시스템을 구축할 수 있습니다.
 */
class MonsterWaveGenerator_Interface
{
public:
	MonsterWaveGenerator_Interface() = default;
	virtual ~MonsterWaveGenerator_Interface() {}

	// NOTE: 팩토리 메서드
	virtual void CreateMonsterWave() abstract;
};

class MonsterWaveGenerator abstract : public MonsterWaveGenerator_Interface
{
public:
	MonsterWaveGenerator() = default;
	virtual ~MonsterWaveGenerator();


protected:
	std::map<UnitType, std::unique_ptr<UnitObjectPool_Interface>> ObjectPoolByUnitType;

	std::unordered_set<Unit*> CreatedUnitList;


public:
	void Init();

	void GetCreatedUnitList(std::unordered_set<Unit*>& OutCreatedUnitList) const { OutCreatedUnitList = CreatedUnitList; }

	void ReturnUnit(Unit* InUnit);


protected:
	Unit* PopUnit(UnitType Type);
};


class MonsterWaveGeneratorA : public MonsterWaveGenerator
{
public:
	virtual void CreateMonsterWave() override;
};

class MonsterWaveGeneratorB : public MonsterWaveGenerator
{
public:

	virtual void CreateMonsterWave() override;
};