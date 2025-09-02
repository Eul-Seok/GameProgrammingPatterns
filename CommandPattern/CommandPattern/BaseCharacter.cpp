#include "BaseCharacter.h"

void BaseCharacter::Init(int StartX, int StartY)
{
	CoordinateX = StartX;
	CoordinateY = StartY;
}

void BaseCharacter::MoveTo(int NewX, int NewY)
{
	CoordinateX = NewX;
	CoordinateY = NewY;
}

void BaseCharacter::Move(int DeltaX, int DelataY)
{
	CoordinateX += DeltaX;
	CoordinateY += DelataY;
}

void BaseCharacter::Jump()
{
	CoordinateY += 1;
}

void BaseCharacter::Dash()
{
	CoordinateX += 2;
}
