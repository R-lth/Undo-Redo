#pragma once

#include "Input.h"

class ICommand
{
public:
	virtual void execute(char cmd) = 0;
	virtual void undo() = 0;
};

class InputCmd : public ICommand
{
public:
	InputCmd(Input* input) 
		: input(input)
	{
	}

	~InputCmd() 
	{
		if (input != nullptr) 
		{
			delete input;
			input = nullptr;
		}
	}

public:
	virtual void execute(char cmd) override
	{
		if (cmd == 'A' || cmd == 'B' || cmd == 'C' || cmd == 'D' || cmd == 'E')
		{
			input->pushInput(cmd);
		}
		else if (cmd == 'U')
		{
			input->pushUndo();
		}
		else if (cmd == 'R')
		{
			input->redo();
		}
		else if (cmd == 'S')
		{
			while (!input->getInputDB().empty())
			{
				input->pushSkill();
				undo();
			}

			input->print();
		}
		else
		{
			cout << "잘못된 입력입니다.\n";
		}
	}

	virtual void undo() override 
	{
		input->undo();
	}

private:
	Input* input = nullptr;
};