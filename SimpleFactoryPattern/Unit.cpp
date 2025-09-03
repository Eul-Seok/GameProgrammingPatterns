#include "Unit.h"
#include <iostream>

void Warrior::Move()
{
	 std::cout << "전사 이동" << std::endl;
}

void Archer::Move()
{
	std::cout << "궁수 이동" << std::endl;
}

void Wizard::Move()
{
	std::cout << "마법사 이동" << std::endl;
}
