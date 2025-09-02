#include <iostream>
#include <vector>
#include <Windows.h>

#include "../BaseCharacter.h"
#include "../InputHandler.h"

void DrawMap(const BaseCharacter* Character, int mapW, int mapH) {
    
    // 콘솔 화면 지우기
    system("cls"); 
    
    for (int y = mapH; y >= 0; y--)
    {
        for (int x = 0; x < mapW; x++)
        {
            if (x == Character->GetCoordinateX() && y == Character->GetCoordinateY())
            {
                // 플레이어 위치
                std::cout << "P";
            }
            else
            {
                std::cout << "_";
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << "========================================" << std::endl;
    std::cout << "이동: a(좌), d(우) / 점프: w / 대쉬: s / 되돌리기: z / 다시실행: x" << std::endl;
}


int main()
{
    // 원본 맵 사이즈와 거의 동일하게 설정
    const int MAP_WIDTH = 20;
    const int MAP_HEIGHT = 20; // 원본처럼 20x20 맵을 가정

    BaseCharacter Character{};
    Character.Init(10, 10);

    InputHandler Handler{};
    Handler.Init(&Character);

    while (true)
    {
        DrawMap(&Character, MAP_WIDTH, MAP_HEIGHT);

        char Input = 0;
        std::cin >> Input;
        Handler.HandleInput(Input);

        Sleep(50);
    }

    return 0;
}