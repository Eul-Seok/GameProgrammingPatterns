#include "Unit.h"
#include <iostream>

void Warrior::Attack()
{
	std::cout << "���� ����" << std::endl;
}

void Warrior::Move()
{
	std::cout << "���� �̵�" << std::endl;
}

void Warrior::Reset()
{
	std::cout << "���� �ʱ�ȭ" << std::endl;
}

void Archer::Attack()
{
	std::cout << "�ü� ����" << std::endl;
}

void Archer::Move()
{
	std::cout << "�ü� �̵�" << std::endl;
}

void Archer::Reset()
{
	std::cout << "�ü� �ʱ�ȭ" << std::endl;
}

void Wizard::Attack()
{
	std::cout << "������ ����" << std::endl;
}

void Wizard::Move()
{
	std::cout << "������ �̵�" << std::endl;
}

void Wizard::Reset()
{
	std::cout << "������ �ʱ�ȭ" << std::endl;
}
