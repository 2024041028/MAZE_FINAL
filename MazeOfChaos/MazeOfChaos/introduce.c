#include "MOC.h"

// Function to show the game instructions and menu options together
void ShowInstructionsAndMenu(int x) {
    int cursorPosition = 0; // 0 for "Skip" and 1 for "Start Game"
    char key;
    int instructionX = 22;
    int instructionY = 2;
    // Display the game instructions
    if (x == 9) {
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
    }
    else if (x == 1) {
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
    }
    else if (x == 2) {
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
    }
    else if (x == 3) {
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
    }
    else if (x == 4) {
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
    }
    else if (x == 5) {
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
    }
    else if (x == 6) {
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
    }
    else if (x == 7) {
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
    }
    else if (x == 8) {
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
    }

    // Menu selection loop
    while (1) {
        // Display the menu options inside the box
        MoveConsole(instructionX, instructionY + 7);
        SetColor(14); // Set text color to yellow
        printf("%s skip   %s gamestart",
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
        MoveConsole(instructionX, instructionY + 9);
        printf("��ŵ�� ����ϱ� ���õ�. ���� ����.");
        exit(0); // Exit the program
    }
    else {
        MoveConsole(instructionX, instructionY + 9);
        printf("���� �����ϱ� ���õ�. ������ �����մϴ�.");
        Sleep(2000);

        // Clear the instructions and menu area for the game to start
        for (int i = instructionY; i <= instructionY + 9; i++) {
            MoveConsole(instructionX - 2, i);
            printf("                                                     ");
        }

        // Placeholder for the game logic
        MoveConsole(instructionX, instructionY + 3);
        printf("������ ���۵Ǿ����ϴ�!");
    }
}
