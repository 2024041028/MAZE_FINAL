#include "MOC.h"


// Function to show the game instructions and menu options together
void ShowInstructionsAndMenu() {
    int cursorPosition = 0; // 0 for "Skip" and 1 for "Start Game"
    char key;

    // Display the game instructions
    MoveConsole(22, 2);
    printf("���� ����:");
    MoveConsole(22, 4);
    printf("�� �̷� ���� ���� �� ���� Ȯ���� �̴ϰ��� ����");
    MoveConsole(22, 6);
    printf("�� ����, ����, �� �� �ϳ��� ����");
    MoveConsole(22, 8);
    printf("�� ��ǻ�Ͱ� ��Ÿ�� ����, ����, ���� ���� ����� �ݴ�� ����");
    MoveConsole(22, 10);
    printf("�� �̱�� '����'�� �Է�, ���� '�̰��'�� �Է�, ���� '����'�� �Է�");

    // Menu selection loop
    while (1) {
        // Display the menu options
        MoveConsole(22, 14);
        printf("   ��ŵ�� ����ϱ�");
        MoveConsole(22, 15);
        printf("   ���� �����ϱ�");

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
        printf("��ŵ�� ����ϱ� ���õ�. ���� ����.");
        exit(0); // Exit the program
    }
    else {
        MoveConsole(22, 17);
        printf("���� �����ϱ� ���õ�. ������ �����մϴ�.");
        Sleep(2000);

        // Clear the instructions and menu area for the game to start
        for (int i = 2; i <= 17; i++) {
            MoveConsole(20, i);
            printf("                                                     ");
        }

        // Placeholder for the game logic
        MoveConsole(22, 5);
        printf("������ ���۵Ǿ����ϴ�!");
    }
}
