#include "MoveRightCommand.h"
#include "../BaseCharacter.h"

void MoveRightCommand::Init(BaseCharacter* InCharacter)
{
	Character = InCharacter;

	if (Character)
	{
		PrevX = Character->GetCoordinateX();
		PrevY = Character->GetCoordinateY();
	}
}

void MoveRightCommand::Execute()
{
	if (Character)
	{
		Character->Move(1, 0);
	}
}

void MoveRightCommand::Undo()
{
	if (Character)
	{
		Character->MoveTo(PrevX, PrevY);
	}
}