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
            // \"A, A, A"\을 A로 인식
            if (!str.empty())
            {
                // 앞뒤 따옴표 제거
                //if (str.front() == '\"') str.erase(0, 1);
                //if (str.back() == '\"') str.pop_back();

                // 앞뒤 따옴표 제거
                str.erase(remove(str.begin(), str.end(), '"'), str.end());

                // 문자 입력
                if (str.length() == 1) 
                {
                    inputCmd->execute(str[0]);
                }
            }
        }

        SafeDelete(inputCmd);
    }

    file.close();
#pragma endregion


    std::cin.get();
    return 0;
}