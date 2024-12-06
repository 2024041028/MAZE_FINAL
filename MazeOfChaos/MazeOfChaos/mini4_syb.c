#include "MOC.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h> // Sleep �Լ�

#define MAX_LEVEL 3 // �ִ� ���̵�
#define TIME_DISPLAY 3 // ���ĺ� ǥ�� �ð� (��)

// ���̵��� ���� ���ĺ� ���� ����
int GetAlphabetCount(int level) {
    return 3 + (level - 1) * 2; // ���̵� 1: 3��, ���̵� 2: 5��, ���̵� 3: 7��
}

// ���� ���ĺ� ���� �Լ�
void GenerateRandomAlphabets(char* sequence, int count) {
    for (int i = 0; i < count; i++) {
        sequence[i] = 'A' + rand() % 26; // A���� Z���� ���� ���ĺ� ����
    }
    sequence[count] = '\0'; // ���ڿ� ���� ���� �߰�
}

// ����� �Է� �ޱ� �Լ�
void GetUserInput(char* input, int max_length) {
    int index = 0;
    char ch;

    while (1) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == '\r') { // Enter Ű�� �Է� ����
                input[index] = '\0';
                break;
            }
            else if (ch == '\b') { // Backspace ó��
                if (index > 0) {
                    index--;
                    MoveConsole(50 + index, 16);
                    printf(" ");
                    MoveConsole(50 + index, 16);
                }
            }
            else if (index < max_length - 1) { // �Է� ���� ���� Ȯ��
                input[index++] = ch;
                MoveConsole(50 + index - 1, 16);
                printf("%c", ch);
            }
        }
    }
}

// ���� ���� �Լ�
void PlayMemoryGame() {
    system("cls");
    CreateOutFrame(); // ���� Ʋ ����

    srand(time(NULL)); // ���� �õ� ����

    int level = 1;
    char sequence[20], user_input[20];

    // ���̵� ����
    while (level <= MAX_LEVEL) {
        int alphabet_count = GetAlphabetCount(level); // ���� ���̵��� ���� ���ĺ� ����

        // ���� ���ĺ� ����
        GenerateRandomAlphabets(sequence, alphabet_count);

        // ȭ�鿡 ���ĺ� ���
        system("cls");
        CreateOutFrame();
        MoveConsole(36, 8);
        SetColor(14); // �����
        printf("Level %d", level);
        MoveConsole(36, 10);
        SetColor(11); // �Ķ���
        printf("����ϼ���: %s", sequence);

        Sleep(TIME_DISPLAY * 1000); // ���ĺ� ǥ�� �ð� ���� ���

        // ���ĺ� �����
        system("cls");
        CreateOutFrame();
        MoveConsole(36, 10);
        SetColor(14); // �����
        printf("���ĺ��� �Է��ϼ���:");

        // ����� �Է� �ޱ�
        MoveConsole(50, 16); // �Է� ��ġ ����
        SetColor(7); // �⺻ ����
        GetUserInput(user_input, sizeof(user_input));

        // �Է� ��
        if (strcmp(sequence, user_input) == 0) {
            // ������ ���
            MoveConsole(36, 12);
            SetColor(10); // �ʷϻ�
            printf("�����Դϴ�! ���� ������ �Ѿ�ϴ�!");
            level++;
            Sleep(2000); // 2�� ��� �� ���� ������
        }
        else {
            // ������ ���
            MoveConsole(36, 12);
            SetColor(4); // ������
            printf("�����Դϴ�! ������: %s", sequence);
            MoveConsole(36, 14);
            printf("Press any key to return to the main menu...");
            getchar();
            return;
        }
    }

    // ���� Ŭ����
    system("cls");
    CreateOutFrame();
    MoveConsole(36, 10);
    SetColor(10); // �ʷϻ�
    printf("�����մϴ�! ��� ������ Ŭ�����߽��ϴ�!");
    MoveConsole(36, 12);
    SetColor(7); // �⺻ ���� ����
    printf("Press any key to return to the main menu...");
    getchar();
}
