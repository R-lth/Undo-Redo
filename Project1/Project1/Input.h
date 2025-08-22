#pragma once
#include <deque>
#include <iostream>

using namespace std;

class Input 
{
public:
	Input() = default;
	~Input() = default;

public:
	deque<char> getInputDB() 
	{
		return inputDB;
	}

	deque<char> getSkillDB()
	{
		return skillDB;
	}

	void pushInput(char ch) 
	{
		inputDB.push_back(ch);
	}

	void pushUndo() 
	{
		inputDB.push_back('U');
	}

	void pushSkill() 
	{
		if (inputDB.front() != 'U')
		{
			skillDB.push_back(inputDB.front());
			inputDB.pop_front();
		}
	}

	void undo() 
	{
		while (!inputDB.empty() && !skillDB.empty() && inputDB.front() == 'U')
		{
			skillDB.pop_back();
			inputDB.pop_front();
		}
	}

	void redo() 
	{
		if (!inputDB.empty() && inputDB.back() == 'U')
		{
			inputDB.pop_back();
		}
	}

	void print() 
	{
		while (!skillDB.empty())
		{
			cout << skillDB.front() << " ";
			skillDB.pop_front();
		}
	}

private:
	deque<char> inputDB;
	deque<char> skillDB;
};