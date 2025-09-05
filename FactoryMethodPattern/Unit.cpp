#include "Unit.h"
#include <iostream>

void Warrior::Attack()
{
	std::cout << "전사 공격" << std::endl;
}

void Warrior::Move()
{
	std::cout << "전사 이동" << std::endl;
}

void Warrior::Reset()
{
	std::cout << "전사 초기화" << std::endl;
}

void Archer::Attack()
{
	std::cout << "궁수 공격" << std::endl;
}

void Archer::Move()
{
	std::cout << "궁수 이동" << std::endl;
}

void Archer::Reset()
{
	std::cout << "궁수 초기화" << std::endl;
}

void Wizard::Attack()
{
	std::cout << "마법사 공격" << std::endl;
}

void Wizard::Move()
{
	std::cout << "마법사 이동" << std::endl;
}

void Wizard::Reset()
{
	std::cout << "마법사 초기화" << std::endl;
}
