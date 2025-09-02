#pragma once

#include <deque>
#include "ObjectPool.h"

class BaseCharacter;
class Command;
class MoveLeftCommand;
class MoveRightCommand;
class JumpCommand;
class DashCommand;

// Receiver(������)
class InputHandler
{
private:
	BaseCharacter* SelectedCharacter;

	// Undo ����� ���� ��� �����丮 ����
	const int HistorySize = 10;
	std::deque<Command*> CommandHistory;
	std::deque<Command*> RedoHistory;

	// �����Ҵ��� ���̰��� ������Ʈ Ǯ ���
	const int ObjectPoolSize = 5;
	ObjectPool<MoveLeftCommand> MoveLeftPool;
	ObjectPool<MoveRightCommand> MoveRightPool;
	ObjectPool<JumpCommand> JumpPool;
	ObjectPool<DashCommand> DashPool;

public:
	InputHandler() = default;
	~InputHandler();

	void Init(BaseCharacter* InCharacter);

	BaseCharacter* GetSelectedCharacter() { return SelectedCharacter; }
	
	void HandleInput(char Key);

	void HandleExecuteCommand(char Key, Command* InCommand);

	void HandleUndoCommand();

	void HandleRedoCommand();
	
	void ReturnCommandToPool(Command* InCommand);

	Command* PopCommandFromPool(char Key);
};