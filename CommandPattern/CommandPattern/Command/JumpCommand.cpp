#include "JumpCommand.h"
#include "../BaseCharacter.h"

void JumpCommand::Init(BaseCharacter* InCharacter)
{
	Character = InCharacter;

	if (Character)
	{
		PrevX = Character->GetCoordinateX();
		PrevY = Character->GetCoordinateY();
	}
}

void JumpCommand::Execute()
{
	if (Character)
	{
		Character->Jump();
	}
}

void JumpCommand::Undo()
{
	if (Character)
	{
		Character->MoveTo(PrevX, PrevY);
	}
}
