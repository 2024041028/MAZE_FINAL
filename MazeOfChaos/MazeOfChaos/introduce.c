#include "MOC.h"


// Function to show the game instructions and menu options together
void ShowInstructionsAndMenu() {
    int cursorPosition = 0; // 0 for "Skip" and 1 for "Start Game"
    char key;

    // Display the game instructions
    MoveConsole(22, 2);
    printf("게임 설명:");
    MoveConsole(22, 4);
    printf("● 미로 게임 진행 중 일정 확률로 미니게임 시작");
    MoveConsole(22, 6);
    printf("● 가위, 바위, 보 중 하나를 선택");
    MoveConsole(22, 8);
    printf("● 컴퓨터가 나타낸 가위, 바위, 보를 보고 결과를 반대로 선택");
    MoveConsole(22, 10);
    printf("● 이기면 '졌다'를 입력, 지면 '이겼다'를 입력, 비기면 '개굴'을 입력");

    // Menu selection loop
    while (1) {
        // Display the menu options
        MoveConsole(22, 14);
        printf("   스킵권 사용하기");
        MoveConsole(22, 15);
        printf("   게임 시작하기");

        // Adjust the cursor position indicator
        MoveConsole(20, 14);
        printf(cursorPosition == 0 ? "->" : "  ");
        MoveConsole(20, 15);
        printf(cursorPosition == 1 ? "->" : "  ");

        // Wait for user input
        key = _getch();
        if (key == 72) { // Arrow up
            cursorPosition = (cursorPosition - 1 + 2) % 2; // Cycle up
        }
        else if (key == 80) { // Arrow down
            cursorPosition = (cursorPosition + 1) % 2; // Cycle down
        }
        else if (key == 13) { // Enter key
            break;
        }
    }

    // Handle the selection
    if (cursorPosition == 0) {
        MoveConsole(22, 17);
        printf("스킵권 사용하기 선택됨. 게임 종료.");
        exit(0); // Exit the program
    }
    else {
        MoveConsole(22, 17);
        printf("게임 시작하기 선택됨. 게임을 시작합니다.");
        Sleep(2000);

        // Clear the instructions and menu area for the game to start
        for (int i = 2; i <= 17; i++) {
            MoveConsole(20, i);
            printf("                                                     ");
        }

        // Placeholder for the game logic
        MoveConsole(22, 5);
        printf("게임이 시작되었습니다!");
    }
}
