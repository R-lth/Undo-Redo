#include <iostream>
#include <deque>

#include "Command.h"

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
	Input* input = new Input();
	InputCmd* inputCmd = new InputCmd(input);

	for (int i = 0; i < n; ++i) 
	{
		inputCmd->execute();
	}

	cin.get();
}