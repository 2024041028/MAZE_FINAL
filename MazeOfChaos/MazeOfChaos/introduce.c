#include "MOC.h"

// Function to show the game instructions and menu options together
int ShowInstructionsAndMenu(int gameType, int skip) {
 
    int cursorPosition = 0; // 0 for "skip" and 1 for "gamestart"
    char key;
    int use_coin = 0;

    // Define fixed position for instructions
    int instructionX = 23;
    int instructionY = 6;

    // Display the game instructions within the box
    SetColor(14); // Set text color to yellow
    MoveConsole(instructionX, instructionY);
    printf("게임 설명");

    SetColor(7); // Reset text color to white

    // Display game-specific instructions
    if (gameType == 5) {  // PlayGreenFrogRPS
        MoveConsole(instructionX, instructionY + 2);
        printf("● 가위, 바위, 보 중 하나를 선택");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 컴퓨터의 가위, 바위, 보 결과 반대로 선택");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 이기면 '졌다', 지면 '이겼다', 비기면 '개굴' 입력");
    }
    else if (gameType == 6) {  // PlayAscendingGame
        MoveConsole(instructionX, instructionY + 2);
        printf("● 주어진 숫자를 오름차순으로 정렬");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 제한 시간 내에 숫자를 입력하여 정렬");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 정확한 순서로 입력하면 성공");
    }

    else if (gameType == 7) {  // PlayTriviaQuizGame
        MoveConsole(instructionX, instructionY + 2);
        printf("● 주어진 질문에 올바른 정답을 입력");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 제한 시간 내에 정답을 맞추세요!");
    }
    else if (gameType == 8) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("● 화면에 나타나는 화살표를 확인하세요");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 화살표방향이 가리키는 좌표를 계산하세요");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 제한시간 내에 최종좌표를 입력하세요!");
    }
    else if (gameType == 9) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("● 랜덤숫자를 추측하세요");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 입력 숫자에 따라 업, 다운 힌트를 드립니다");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 제한횟수 안에서 정답을 맞추세요");
    }
    else if (gameType == 1) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("● 제시된 단어를 추측하여 알파벳 입력하세요");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 틀린 횟수가 누적되면 행맨이 완성됩니다");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 제한횟수 안에서 정답을 맞추세요");
    }
    else if (gameType == 2) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("● 화면에 주어진 산수문제를 풀어보세요");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 정답을 입력하면 다음문제가 나옵니다");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 제한시간 내에 최대한 많은 정답을 맞추세요");
    }
    else if (gameType == 3) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("● 화면에 나타나는 숫자나 글자를 기억하세요");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 일정시간 후 사라집니다");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 제한시간 내에 정답을 맞추세요");
    }
    else if (gameType == 4) {  //
        MoveConsole(instructionX, instructionY + 2);
        printf("● 랜덤한 숫자가 출력됩니다");
        MoveConsole(instructionX, instructionY + 3);
        printf("● 숫자 사이에 '지금'이 출력되면 p를 누르세요");
        MoveConsole(instructionX, instructionY + 4);
        printf("● 비슷한 오타들이 나오니 주의하세요");
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
        if (skip > 0) {
            MoveConsole(instructionX, instructionY + 11);
            printf("스킵권 사용하기 선택됨. 게임 종료.");
            return 1;
        }
        else {
            MoveConsole(instructionX, instructionY + 11);
            printf("스킵권이 없습니다. 구매하시겠습니까?");
            MoveConsole(instructionX, instructionY + 12);
            printf("가격:코인5개");
            while (1) {
                MoveConsole(instructionX, instructionY + 13);
                SetColor(14);
                printf("%s use coin        %s play minigame",
                    use_coin == 0 ? "->" : "  ",
                    use_coin == 1 ? "->" : "  ");
                SetColor(7);

                key = _getch();
                if (key == 75) {
                    use_coin = (use_coin - 1 + 2) % 2;
                }
                else if (key == 77) { 
                    use_coin = (use_coin + 1) % 2;
                }
                else if (key == 13) {
                    break;
                }
            }
            if (user_coin >= 5 && use_coin == 0) {
                MoveConsole(instructionX, instructionY + 14);
                printf("코인을 사용하여 게임을 스킵합니다.");
                user_coin -= 5;
                Sleep(2000);
                return 2;
            }
            else if (use_coin == 1) {
                MoveConsole(instructionX, instructionY + 14);
                printf("코인을 사용하지 않고 미니게임을 시작합니다.");
                Sleep(2000);
                return 0;
            }
            else {
                MoveConsole(instructionX, instructionY + 14);
                printf("코인이 부족합니다. 게임을 실행합니다.");
                Sleep(2000);
                return 0;
            }
        }
    }
    else {
        MoveConsole(instructionX, instructionY + 11);
        printf("게임 시작하기 선택됨. 게임을 시작합니다.");
        Sleep(2000);
        return 0;

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
