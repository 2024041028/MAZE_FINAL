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
    printf("���� ����:");
    MoveConsole(22, 5);
    printf("�� �̷� ���� ���� �� ���� Ȯ���� �̴ϰ��� ����");
    MoveConsole(22, 7);
    printf("�� ����, ����, �� �� �ϳ��� ����");
    MoveConsole(22, 9);
    printf("�� ��ǻ�Ͱ� ��Ÿ�� ����, ����, ���� ���� ����� �ݴ�� ����");
    MoveConsole(22, 11);
    printf("�� �̱�� '����'�� �Է�, ���� '�̰��'�� �Է�, ���� '����'�� �Է�");

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
        printf("   ��ŵ�� ����ϱ�");
        MoveConsole(20, 11);
        printf("   ���� �����ϱ�");

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
        printf("��ŵ�� ����ϱ� ���õ�. ���� ����.");
        exit(0); // Exit the program
    }
    else {
        MoveConsole(20, 13);
        printf("���� �����ϱ� ���õ�. ������ �����մϴ�.");
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
        printf("������ ���۵Ǿ����ϴ�!"); // Placeholder for actual game logic
    }
}
