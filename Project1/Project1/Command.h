#pragma once

#include "Input.h"

class ICommand
{
public:
	virtual void execute() = 0;
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
	virtual void execute() override
	{
		string cmd;
		cin >> cmd;

		if (cmd == "A" || cmd == "B" || cmd == "C" || cmd == "D" || cmd == "E")
		{
			input->pushInput(cmd[0]);
		}
		else if (cmd == "Undo")
		{
			input->pushUndo();
		}
		else if (cmd == "Redo")
		{
			input->redo();
		}
		else if (cmd == "Show")
		{
			// TODO. �ʱ�ȭ ����ϱ�
			//input->getSkillDB().clear();

			while (!input->getInputDB().empty())
			{
				input->pushSkill();
				undo();
			}

			input->print();
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�.\n";
		}
	}

	virtual void undo() override 
	{
		input->undo();
	}

private:
	Input* input = nullptr;
};