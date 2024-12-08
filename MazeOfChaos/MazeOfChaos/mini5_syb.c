#include "MOC.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define TIME_LIMIT 2.0 // '����!' ���� ���� �ð� (��)
#define MAX_LEVEL 5    // �ִ� ���̵�
#define BASE_SPEED 1000 // ���� ǥ�� �⺻ �ӵ� (�и���)

// ȥ�� ���� �迭
const char* CONFUSING_TEXTS[] = { "����!", "�ڱ�", "����", "����", "�ӱ�" };
const int NUM_CONFUSING_TEXTS = 5;

// ���� ���� ���� �Լ�
const char* GenerateRandomText(int is_now) {
    if (is_now) {
        return "����!"; // �ùٸ� ����
    }
    else {
        return CONFUSING_TEXTS[rand() % NUM_CONFUSING_TEXTS]; // ȥ�� ����
    }
}

// ���� �ӵ� ���� �� �Է� �ޱ�
int GetReactionTime(double* reaction_time) {
    clock_t start_time = clock();
    clock_t elapsed_time;
    int success = 0;

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'p' || ch == 'P') {
                elapsed_time = clock() - start_time;
                *reaction_time = (double)elapsed_time / CLOCKS_PER_SEC;
                success = 1;
                break;
            }
        }

        elapsed_time = clock() - start_time;
        if ((double)elapsed_time / CLOCKS_PER_SEC > TIME_LIMIT) {
            *reaction_time = -1; // �ð� �ʰ�
            break;
        }
    }
    return success;
}

// ���߷� ���� �Լ�
void PlayReactionGame() {
    system("cls");
    CreateOutFrame(); // ���� Ʋ ����

    srand(time(NULL)); // ���� �õ� ����

    int level = 1;
    double reaction_time;

    // ���̵� ����
    while (level <= MAX_LEVEL) {
        int display_speed = BASE_SPEED - (level - 1) * 200; // ���̵��� ���� �ӵ� ����
        int correct_trigger = rand() % 5 + 3; // '����!' ��� Ÿ�̹�
        int rounds = 0;

        // ���ڿ� ���� ��� ����
        while (rounds++ < correct_trigger) {
            system("cls");
            CreateOutFrame();

            // ���� ���
            int random_number = rand() % 1000;
            MoveConsole(36, 8);
            SetColor(11); // �Ķ���
            printf("%d", random_number);

            // ���� ���� ���
            const char* random_text = GenerateRandomText(rounds == correct_trigger);
            MoveConsole(36, 10);
            SetColor(14); // �����
            printf("%s", random_text);

            if (rounds == correct_trigger) {
                // '����!'�� �� ���� Ȯ��
                if (GetReactionTime(&reaction_time)) {
                    // ����
                    MoveConsole(36, 12);
                    SetColor(10); // �ʷϻ�
                    printf("����! ���� �ð�: %.3f��", reaction_time);
                    Sleep(2000);
                    level++;
                    break;
                }
                else {
                    // ����
                    MoveConsole(36, 12);
                    SetColor(4); // ������
                    printf("����! �ð� �ʰ�!");
                    MoveConsole(36, 14);
                    printf("Press any key to return to the main menu...");
                    getchar();
                    return;
                }
            }

            Sleep(display_speed); // ���� ���� ��� �� ���
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
