#pragma once

class BaseCharacter;

// ¸í·É
class Command_Interface
{
public:
	virtual ~Command_Interface() {}

	virtual void Execute() abstract;
	virtual void Undo() abstract;
};

class Command abstract : public Command_Interface
{
public:
	virtual ~Command() {}

	virtual void Init(BaseCharacter* InCharacter) = 0;
};
