#include "MOC.h"

// Function to show the game instructions and menu options together
void ShowInstructionsAndMenu(int gameType) {
    int cursorPosition = 0; // 0 for "skip" and 1 for "gamestart"
    char key;

    // Define fixed position for instructions
    int instructionX = 23;
    int instructionY = 6;

    // Display the game instructions within the box
    SetColor(14); // Set text color to yellow
    MoveConsole(instructionX, instructionY);
    printf("게임 설명");

    SetColor(7); // Reset text color to white

    // Display game-specific instructions
    if (gameType == 0) {  // PlayGreenFrogRPS
        MoveConsole(instructionX, instructionY + 2);
        printf("● 가위, 바위, 보 중 하나를 선택");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 컴퓨터의 가위, 바위, 보 결과 반대로 선택");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 이기면 '졌다', 지면 '이겼다', 비기면 '개굴' 입력");
    }
    else if (gameType == 1) {  // PlayAscendingGame
        MoveConsole(instructionX, instructionY + 2);
        printf("● 주어진 숫자를 오름차순으로 정렬");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 제한 시간 내에 숫자를 입력하여 정렬");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 정확한 순서로 입력하면 성공");
    }

    else if (gameType == 2) {  // PlayTriviaQuizGame
        MoveConsole(instructionX, instructionY + 2);
        printf("● 주어진 질문에 올바른 정답을 입력");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 제한 시간 내에 정답을 맞추세요!");
    }


    // Menu selection loop
    while (1) {
        // Display the menu options inside the box
        MoveConsole(instructionX, instructionY + 9);
        SetColor(14); // Set text color to yellow
        printf("%s skip        %s game start",
            cursorPosition == 0 ? "->" : "  ",
            cursorPosition == 1 ? "->" : "  ");
        SetColor(7); // Reset text color to white

        // Wait for user input
        key = _getch();
        if (key == 75) { // Arrow left
            cursorPosition = (cursorPosition - 1 + 2) % 2; // Cycle left
        }
        else if (key == 77) { // Arrow right
            cursorPosition = (cursorPosition + 1) % 2; // Cycle right
        }
        else if (key == 13) { // Enter key
            break;
        }
    }

    // Handle the selection
    if (cursorPosition == 0) {
        MoveConsole(instructionX, instructionY + 11);
        printf("스킵권 사용하기 선택됨. 게임 종료.");
    }
    else {
        MoveConsole(instructionX, instructionY + 11);
        printf("게임 시작하기 선택됨. 게임을 시작합니다.");
        Sleep(2000);

        // Clear only the area used for instructions and menu, keeping the frame intact
        for (int i = instructionY; i <= instructionY + 11; i++) {
            MoveConsole(instructionX, i);
            printf("                                           ");
        }

        //// Start the selected mini-game based on gameType
        //if (gameType == 0) {
        //    PlayGreenFrogRPS(1);  // Example level set to 1
        //}
        //else if (gameType == 1) {
        //    PlayAscendingGame(1);  // Example level set to 1
        //}
        //else if (gameType == 2) {
        //    PlayTriviaQuizGame(1);  // Example level set to 1
        //}
    }
}
