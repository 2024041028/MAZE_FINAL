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
    printf("���� ����");

    SetColor(7); // Reset text color to white

    // Display game-specific instructions
    if (gameType == 5) {  // PlayGreenFrogRPS
        MoveConsole(instructionX, instructionY + 2);
        printf("�� ����, ����, �� �� �ϳ��� ����");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� ��ǻ���� ����, ����, �� ��� �ݴ�� ����");
        MoveConsole(instructionX, instructionY + 4);
        printf("�� �̱�� '����', ���� '�̰��', ���� '����' �Է�");
    }
    else if (gameType == 6) {  // PlayAscendingGame
        MoveConsole(instructionX, instructionY + 2);
        printf("�� �־��� ���ڸ� ������������ ����");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� ���� �ð� ���� ���ڸ� �Է��Ͽ� ����");
        MoveConsole(instructionX, instructionY + 4);
        printf("�� ��Ȯ�� ������ �Է��ϸ� ����");
    }

    else if (gameType == 7) {  // PlayTriviaQuizGame
        MoveConsole(instructionX, instructionY + 2);
        printf("�� �־��� ������ �ùٸ� ������ �Է�");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� ���� �ð� ���� ������ ���߼���!");
    }
    else if (gameType == 8) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("�� ȭ�鿡 ��Ÿ���� ȭ��ǥ�� Ȯ���ϼ���");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� ȭ��ǥ������ ����Ű�� ��ǥ�� ����ϼ���");
        MoveConsole(instructionX, instructionY + 4);
        printf("�� ���ѽð� ���� ������ǥ�� �Է��ϼ���!");
    }
    else if (gameType == 9) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("�� �������ڸ� �����ϼ���");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� �Է� ���ڿ� ���� ��, �ٿ� ��Ʈ�� �帳�ϴ�");
        MoveConsole(instructionX, instructionY + 4);
        printf("�� ����Ƚ�� �ȿ��� ������ ���߼���");
    }
    else if (gameType == 1) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("�� ���õ� �ܾ �����Ͽ� ���ĺ� �Է��ϼ���");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� Ʋ�� Ƚ���� �����Ǹ� ����� �ϼ��˴ϴ�");
        MoveConsole(instructionX, instructionY + 4);
        printf("�� ����Ƚ�� �ȿ��� ������ ���߼���");
    }
    else if (gameType == 2) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("�� ȭ�鿡 �־��� ��������� Ǯ�����");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� ������ �Է��ϸ� ���������� ���ɴϴ�");
        MoveConsole(instructionX, instructionY + 4);
        printf("�� ���ѽð� ���� �ִ��� ���� ������ ���߼���");
    }
    else if (gameType == 3) {  // 
        MoveConsole(instructionX, instructionY + 2);
        printf("�� ȭ�鿡 ��Ÿ���� ���ڳ� ���ڸ� ����ϼ���");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� �����ð� �� ������ϴ�");
        MoveConsole(instructionX, instructionY + 4);
        printf("�� ���ѽð� ���� ������ ���߼���");
    }
    else if (gameType == 4) {  //
        MoveConsole(instructionX, instructionY + 2);
        printf("�� ������ ���ڰ� ��µ˴ϴ�");
        MoveConsole(instructionX, instructionY + 3);
        printf("�� ���� ���̿� '����'�� ��µǸ� p�� ��������");
        MoveConsole(instructionX, instructionY + 4);
        printf("�� ����� ��Ÿ���� ������ �����ϼ���");
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
            printf("��ŵ�� ����ϱ� ���õ�. ���� ����.");
            return 1;
        }
        else {
            MoveConsole(instructionX, instructionY + 11);
            printf("��ŵ���� �����ϴ�. �����Ͻðڽ��ϱ�?");
            MoveConsole(instructionX, instructionY + 12);
            printf("����:����5��");
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
                printf("������ ����Ͽ� ������ ��ŵ�մϴ�.");
                user_coin -= 5;
                Sleep(2000);
                return 2;
            }
            else if (use_coin == 1) {
                MoveConsole(instructionX, instructionY + 14);
                printf("������ ������� �ʰ� �̴ϰ����� �����մϴ�.");
                Sleep(2000);
                return 0;
            }
            else {
                MoveConsole(instructionX, instructionY + 14);
                printf("������ �����մϴ�. ������ �����մϴ�.");
                Sleep(2000);
                return 0;
            }
        }
    }
    else {
        MoveConsole(instructionX, instructionY + 11);
        printf("���� �����ϱ� ���õ�. ������ �����մϴ�.");
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
