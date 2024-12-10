#include "MOC.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX_QUESTIONS 5 // �� ���� ��
#define TIME_DISPLAY 3  // ���� ǥ�� �ð� (��)

// �ʱ� ���� ����
now_level = 1; // �ʱ� ���� 1

// ���̵��� ���� ���ڿ� ���� ��ȯ
int GetStringLengthForLevel(int level) {
    return 3 + level; // 1����: 4����, 2����: 5����, 3����: 6����
}

// ���� ���ڿ� ���� �Լ� (���ڿ� ���� ���ĺ� ����)
void GenerateRandomString(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        if (rand() % 2 == 0) { // 50% Ȯ���� ���� �Ǵ� ���ĺ� ����
            sequence[i] = '0' + rand() % 10; // 0~9 ����
        }
        else {
            sequence[i] = 'A' + rand() % 26; // A~Z ���ĺ�
        }
    }
    sequence[length] = '\0'; // ���ڿ� ����
}

// ����� �Է� �ޱ� �Լ�
void GetUserInput(char* input, int max_length, int start_x, int start_y) {
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
                    MoveConsole(start_x + index, start_y);
                    printf(" ");
                    MoveConsole(start_x + index, start_y);
                }
            }
            else if (index < max_length - 1) { // �Է� ���� ���� Ȯ��
                input[index++] = ch;
                MoveConsole(start_x + index - 1, start_y);
                printf("%c", ch);
            }
        }
    }
}

// ���� ���� �Լ�
void PlayMemoryGame() {
    system("cls");
    CreateOutFrame(now_color_num); // ���� Ʋ ����
    srand(time(NULL)); // ���� �õ� ����

    int correct_count = 0; // ���� Ƚ��
    char sequence[20], user_input[20];

    // ���� ���̵� ���� ����
    for (int question = 1; question <= MAX_QUESTIONS; question++) {
        int str_length = GetStringLengthForLevel(now_level); // ���� ������ ���� ���ڿ� ����

        // ���� ���ڿ� ����
        GenerateRandomString(sequence, str_length);

        // ȭ�鿡 ���ڿ� ���
        system("cls");
        CreateOutFrame(now_color_num);
        MoveConsole(38,9);
        SetColor(14); // �����
        printf("Level %d - ���� %d", now_level, question);
        MoveConsole(38, 11);
        SetColor(11); // �Ķ���
        printf("����ϼ���: %s", sequence);

        Sleep(TIME_DISPLAY * 1000); // ���ڿ� ǥ�� �ð� ���� ���

        // ���ڿ� �����
        system("cls");
        CreateOutFrame(now_color_num);
        MoveConsole(35, 10);
        SetColor(14); // �����
        printf("���ڿ��� �Է��ϼ���: ");

        // �Է� �ʵ� Ŀ�� ��ġ ����
        int input_start_x = 35 + strlen("���ڿ��� �Է��ϼ���: ");
        int input_start_y = 10;
        MoveConsole(input_start_x, input_start_y);
        SetColor(7); // �⺻ ����
        GetUserInput(user_input, sizeof(user_input), input_start_x, input_start_y);

        // �Է� ��
        if (strcmp(sequence, user_input) == 0) {
            // ������ ���
            correct_count++;
            MoveConsole(42, 12);
            SetColor(10); // �ʷϻ�
            printf("�����Դϴ�!");
        }
        else {
            // ������ ���
            MoveConsole(35, 12);
            SetColor(4); // ������
            printf("�����Դϴ�! ������: %s", sequence);
        }

        MoveConsole(36, 14);
        SetColor(7); // �⺻ ���� ����
        printf("���� ���� ����: %d / %d", correct_count, question);

        Sleep(2000); // 2�� ���
    }

    // ��� ���
    system("cls");
    CreateOutFrame(now_color_num);
    MoveConsole(24, 10);

    if (correct_count >= 3) {
        SetColor(10); // �ʷϻ�
        printf("�����մϴ�! Level %d���� %d���� ������ ������ϴ�!", now_level, correct_count);
    }
    else {
        SetColor(4); // ������
        MoveConsole(32, 10);
        printf("Level %d ����! ���� ����: %d / %d", now_level, correct_count, MAX_QUESTIONS);
    }

    MoveConsole(26, 12);
    SetColor(7); // �⺻ ���� ����
    printf("Press any key to return to the main menu...");
    getchar();
}
