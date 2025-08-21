#include <iostream>
#include <deque>
#include <stack>

using namespace std;

// TODO. 전체 작업 과정
// [x] Undo/Redo 구현
// [] Command Pattern 적용
// [] 테스트 케이스. csv 파일로 읽어오기

int main() 
{
	cout << "입력 횟수를 입력하시오.\n";
	int n;
	cin >> n;

	cout << "==입력==\n";
	deque<char> input;
	for (int i = 0; i < n; ++i) 
	{
		string cmd;
		cin >> cmd;
		
		if (cmd == "A" || cmd == "B" || cmd == "C" || cmd == "D" || cmd == "E") 
		{
			input.push_back(cmd[0]);
		}
		else if (cmd == "Undo")
		{
			input.push_back('U');
		}
		else if (cmd == "Redo")
		{
			if (!input.empty() && input.back() == 'U')
			{
				input.pop_back();
			}
		}
		else if (cmd == "Show")
		{
			deque<char> skill;

			while (!input.empty())
			{
				if (input.front() != 'U') 
				{
					skill.push_back(input.front());
					input.pop_front();
				}

				while (!input.empty() && input.front() == 'U')
				{
					skill.pop_back();
					input.pop_front();
				}
			}

			while (!skill.empty()) 
			{
				cout << skill.front() << " ";
				skill.pop_front();
			}
		}
		else 
		{
			cout << i << "\n";
			cout << "잘못된 명령 입니다.\n";
			break;
		}
	}
}