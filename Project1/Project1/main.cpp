#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Command.h"

template <typename T>
void SafeDelete(T*& t) 
{
    if (t != nullptr) 
    {
        delete t;
        t = nullptr;
    }
}

char getChar(string str) 
{
    // skill
    if ((str == "\"A") || (str == "A") || (str == "A\"")) return 'A';
    else if ((str == "\"B") || (str == "B") || (str == "B\"")) return 'B';
    else if ((str == "\"C") || (str == "C") || (str == "C\"")) return 'C';
    else if ((str == "\"D") || (str == "D") || (str == "D\"")) return 'D';
    else if ((str == "\"E") || (str == "E") || (str == "E\"")) return 'E';
    // cmd
    else if ((str == "\"U") || (str == "U") || (str == "U\"")) return 'U';
    else if ((str == "\"R") || (str == "R") || (str == "R\"")) return 'R';
    else if ((str == "\"S") || (str == "S") || (str == "S\"")) return 'S';
}

int main()
{
#pragma region 파일 가져오기
    // cvs 파일 설정. UTF-8(쉼표로 분리)
    string filePath = "../Test/test_cases.csv";
    ifstream file;
    file.open(filePath);

    if (!file.is_open())
    {
        std::cout << "Failed to open file: " << filePath << std::endl;
    }
#pragma endregion

#pragma region 파일 읽기
    string part;
    getline(file, part);

    int i = 0;
    string row;
    while (getline(file, row))
    {
        cout << "\n== " << ++i << ". 테스트 케이스 == \n";
        Input* input = new Input();
        InputCmd* inputCmd = new InputCmd(input);

        stringstream ss(row);
        string str;

        while (getline(ss, str, ','))
        {
            char ch = getChar(str);
            inputCmd->execute(ch);
        }

        SafeDelete(inputCmd);
    }

    file.close();
#pragma endregion


    std::cin.get();
    return 0;
}