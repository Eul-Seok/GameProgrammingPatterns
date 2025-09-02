#include "InputHandler.h"
#include "BaseCharacter.h"

#include "Command/Command.h"
#include "Command/MoveLeftCommand.h"
#include "Command/MoveRightCommand.h"
#include "Command/JumpCommand.h"
#include "Command/DashCommand.h"

InputHandler::~InputHandler()
{
	while (!CommandHistory.empty()) {
		Command* CMD = CommandHistory.front();
		CommandHistory.pop_front();
		ReturnCommandToPool(CMD);
	}

	while (!RedoHistory.empty()) {
		Command* CMD = RedoHistory.front();
		RedoHistory.pop_front();
		ReturnCommandToPool(CMD);
	}
}

void InputHandler::Init(BaseCharacter* InCharacter)
{
	SelectedCharacter = InCharacter;
	
	MoveLeftPool.Init(ObjectPoolSize);
	MoveRightPool.Init(ObjectPoolSize);
	JumpPool.Init(ObjectPoolSize);
	DashPool.Init(ObjectPoolSize);
}

void InputHandler::HandleInput(char Key)
{
	Command* HandleCommand{};
	
	switch (Key)
	{
		case 'a':
		case 'd':
		case 'w':
		case 's':
		{
			HandleCommand = PopCommandFromPool(Key);
			if (HandleCommand)
			{
				HandleExecuteCommand(Key, HandleCommand);
			}
			break;
		}
	
		case 'z':
		{
			HandleUndoCommand();
			break;
		}
		case 'x':
		{
			HandleRedoCommand();
			break;
		}
		default: break;
	}
}

void InputHandler::HandleExecuteCommand(char Key, Command* InCommand)
{
	if (nullptr == InCommand)
	{
		return;
	}

	InCommand->Init(SelectedCharacter);
	InCommand->Execute();

	// 새로운 명령이 실행되면 Redo 기록은 유효하지 않게 됨
	while (!RedoHistory.empty()) {
		ReturnCommandToPool(RedoHistory.front());
		RedoHistory.pop_front();
	}

	CommandHistory.push_back(InCommand);

	// 오래된 명령 제거
	if (CommandHistory.size() > HistorySize) {
		ReturnCommandToPool(CommandHistory.front());
		CommandHistory.pop_front();
	}
}

Command* InputHandler::PopCommandFromPool(char Key)
{
	Command* PopCommand{};
	switch (Key)
	{
		case 'a':
		{
			PopCommand = MoveLeftPool.Pop();
			break;
		}
		case 'd':
		{
			PopCommand = MoveRightPool.Pop();
			break;
		}
		case 'w':
		{
			PopCommand = JumpPool.Pop();
			break;
		}
		case 's':
		{
			PopCommand = DashPool.Pop();
			break;
		}
	}
	return PopCommand;
}

void InputHandler::HandleUndoCommand()
{
	if (false == CommandHistory.empty())
	{
		Command* UndoCommand = CommandHistory.back();
		CommandHistory.pop_back();
		UndoCommand->Undo();
		RedoHistory.push_back(UndoCommand);
	}
}

void InputHandler::HandleRedoCommand()
{
	if (!RedoHistory.empty())
	{
		Command* RedoCommand = RedoHistory.back();
		RedoHistory.pop_back();
		RedoCommand->Execute();
		CommandHistory.push_back(RedoCommand);
	}
}

void InputHandler::ReturnCommandToPool(Command* InCommand)
{
	if (nullptr == InCommand)
	{
		return;
	}

	if (MoveLeftCommand* MLC = dynamic_cast<MoveLeftCommand*>(InCommand))
	{
		MoveLeftPool.Return(MLC);
	}
	else if (MoveRightCommand* MRC = dynamic_cast<MoveRightCommand*>(InCommand))
	{
		MoveRightPool.Return(MRC);
	}
	else if (JumpCommand* JC = dynamic_cast<JumpCommand*>(InCommand))
	{
		JumpPool.Return(JC);
	}
	else if (DashCommand* DC = dynamic_cast<DashCommand*>(InCommand))
	{
		DashPool.Return(DC);
	}
	else
	{
		// 알 수 없는 Command 타입이 들어온 경우 (오류 처리)
	}
}