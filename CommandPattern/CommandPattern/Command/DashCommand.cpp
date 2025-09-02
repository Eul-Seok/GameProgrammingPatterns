#include "DashCommand.h"
#include "../BaseCharacter.h"

void DashCommand::Init(BaseCharacter* InCharacter)
{
	Character = InCharacter;

	if (Character)
	{
		PrevX = Character->GetCoordinateX();
		PrevY = Character->GetCoordinateY();
	}
}

void DashCommand::Execute()
{
	if (Character)
	{
		Character->Dash();
	}
}

void DashCommand::Undo()
{
	if (Character)
	{
		Character->MoveTo(PrevX, PrevY);
	}
}
