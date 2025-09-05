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
 * @brief ���� ���̺긦 �����ϴ� ���丮 �޼��� ���� �����Դϴ�.
 *
 * MonsterWaveGenerator�� ������ �����ϴ� ����� �����ϴ� �߻����� 'Creator' ������ �մϴ�.
 * �ڽ� Ŭ������ MonsterWaveGeneratorA, MonsterWaveGeneratorB�� 'CreateMonsterWave'���
 * ���丮 �޼��带 �������̵��Ͽ�, ���� �ٸ� ������ ���� ���̺�(Product)�� �����մϴ�.
 * Ŭ���̾�Ʈ�� MonsterWaveGenerator�� ��ü���� Ÿ���� ���� CreateMonsterWave()�� ȣ���Ͽ�
 * ���ϴ� ������� ���� �� �ֽ��ϴ�.
 *
 * --- ���� Ȯ�� ���� ---
 * 1. ������ ��� ����:
 *    ���� �� CreateMonsterWave �Լ� ���ο� �ϵ��ڵ��� ���̺� ���� ������,
 *    �ܺ� ������ ���̺�(JSON, CSV ��)���� '���̺� ���'�� �о�� ó���ϵ��� �����ϸ�
 *    �ڵ带 ������������ �ʰ� ���ο� ���̺긦 ���� �߰��� �� �ֽ��ϴ�.
 *
 * 2. ���� ����(Strategy Pattern)�� ����:
 *    ���͸� '���' ��������(��: �� ���� ����, �ð����� �ΰ� ����, ���� ������ ���� ��)��
 *    ���� ��ü�� ĸ��ȭ�ϰ�, CreateMonsterWave�� �� ������ �����Ͽ� ����ϵ��� �����
 *    �ܼ��� ������ ������ĸ� �Ѿ�, ����� ��ı��� �������� ������ �� �ִ�
 *    �ξ� ������ �ý����� ������ �� �ֽ��ϴ�.
 */
class MonsterWaveGenerator_Interface
{
public:
	MonsterWaveGenerator_Interface() = default;
	virtual ~MonsterWaveGenerator_Interface() {}

	// NOTE: ���丮 �޼���
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