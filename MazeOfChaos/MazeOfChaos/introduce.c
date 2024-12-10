#include <stdio.h>
#include <conio.h> // For _getch()
#include <windows.h> // For Sleep()


// Function to show the game instructions
void ShowGameInstructions() {
    // Clear the area where instructions will be displayed
    for (int i = 1; i <= 23; i++) {
        MoveConsole(21, i);
        printf("                                                        ");
    }

    // Display the game instructions
    MoveConsole(22, 3);
    printf("게임 설명:");
    MoveConsole(22, 5);
    printf("● 미로 게임 진행 중 일정 확률로 미니게임 시작");
    MoveConsole(22, 7);
    printf("● 가위, 바위, 보 중 하나를 선택");
    MoveConsole(22, 9);
    printf("● 컴퓨터가 나타낸 가위, 바위, 보를 보고 결과를 반대로 선택");
    MoveConsole(22, 11);
    printf("● 이기면 '졌다'를 입력, 지면 '이겼다'를 입력, 비기면 '개굴'을 입력");

    // Wait for 5 seconds
    Sleep(5000);

    // Clear the instructions from the screen
    for (int i = 1; i <= 23; i++) {
        MoveConsole(21, i);
        printf("                                                        ");
    }
}

// Function to display the menu and handle the selection
void MenuSelection() {
    int cursorPosition = 0; // 0 for "Skip" and 1 for "Start Game"
    char key;

    while (1) {
        // Display the menu options
        MoveConsole(20, 10);
        printf("   스킵권 사용하기");
        MoveConsole(20, 11);
        printf("   게임 시작하기");

        // Adjust the cursor position indicator
        MoveConsole(18, 10);
        printf(cursorPosition == 0 ? "->" : "  ");
        MoveConsole(18, 11);
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
        MoveConsole(20, 13);
        printf("스킵권 사용하기 선택됨. 게임 종료.");
        exit(0); // Exit the program
    }
    else {
        MoveConsole(20, 13);
        printf("게임 시작하기 선택됨. 게임을 시작합니다.");
        Sleep(2000);

        // Clear the menu area
        for (int i = 10; i <= 13; i++) {
            MoveConsole(18, i);
            printf("                                 ");
        }

        // Show game instructions
        ShowGameInstructions();

        // Continue with the main game logic here
        MoveConsole(22, 5);
        printf("게임이 시작되었습니다!"); // Placeholder for actual game logic
    }
}
