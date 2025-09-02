#pragma once

#include "Command.h"

class BaseCharacter;

class MoveLeftCommand : public Command
{
private:
	BaseCharacter* Character;

	int PrevX;

	int PrevY;

public:
	virtual void Init(BaseCharacter* InCharacter) override;

	virtual void Execute() override;
	virtual void Undo() override;
};
