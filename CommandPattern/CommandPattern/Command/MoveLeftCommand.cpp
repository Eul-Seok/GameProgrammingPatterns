#include "MoveLeftCommand.h"
#include "../BaseCharacter.h"

void MoveLeftCommand::Init(BaseCharacter* InCharacter)
{
	Character = InCharacter;

	if (Character)
	{
		PrevX = Character->GetCoordinateX();
		PrevY = Character->GetCoordinateY();
	}
}

void MoveLeftCommand::Execute()
{
	if(Character)
	{
		Character->Move(-1, 0);
	}
}

void MoveLeftCommand::Undo()
{
	if (Character)
	{
		Character->MoveTo(PrevX, PrevY);
	}
}
