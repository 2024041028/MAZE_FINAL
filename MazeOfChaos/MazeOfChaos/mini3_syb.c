#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "MOC.h"

#define MAX_QUESTIONS 5    // ���� ��
#define TIME_LIMIT 10      // ���� �ð� (��)

// Ÿ�̸� �Լ�
int StartTimer(int timeLimit) {
    clock_t startTime = clock(); // ���� �ð� ����
    while (1) {
        clock_t currentTime = clock();
        double elapsed = (double)(currentTime - startTime) / CLOCKS_PER_SEC;
        if (elapsed > timeLimit) {
            return 0; // �ð� �ʰ�
        }

        if (_kbhit()) { // Ű �Է��� ������
            return 1; // ���� ����
        }
    }
}

// ���� ��� ���� ���� �Լ�
void GenerateMathProblem(int* a, int* b, char* op, int* answer) {
    *a = rand() % 50 + 1; // 1���� 50 ������ ����
    *b = rand() % 50 + 1;
    *op = (rand() % 2 == 0) ? '+' : '-'; // �������� '+' �Ǵ� '-' ����

    // ���� ���
    if (*op == '+') {
        *answer = *a + *b;
    }
    else {
        *answer = *a - *b;
    }
}

// ����� �Է��� �޾� ������ ��ȯ�ϴ� �Լ�
int GetUserInput() {
    int number = 0;
    char ch;

    while (1) {
        if (_kbhit()) { // Ű �Է� Ȯ��
            ch = _getch(); // Ű �Է� �ޱ�

            if (ch == 13) { // Enter Ű�� ������ �Է� ����
                break;
            }
            else if (ch >= '0' && ch <= '9') { // ���� �Է��� ���
                number = number * 10 + (ch - '0'); // �Էµ� ���ڸ� ������ ��ȯ
                printf("%c", ch); // �Էµ� ���� ���
            }
        }
    }

    printf("\n"); // �Է� ���� �� �� �ٲ�
    return number;
}

// ��� ���� �Լ�
void PlayMathGame() {
    system("cls");
    CreateOutFrame(); // ���� Ʋ ����

    srand(time(NULL)); // ���� �õ� ����

    int score = 0; // ���� ���� ��
    int a, b, userAnswer, correctAnswer;
    char op;

    for (int i = 1; i <= MAX_QUESTIONS; i++) {
        // ���� ����
        GenerateMathProblem(&a, &b, &op, &correctAnswer);

        // ���� ���
        system("cls");
        CreateOutFrame();
        MoveConsole(36, 8);
        SetColor(11); // �Ķ���
        printf("���� %d: %d %c %d = ?", i, a, op, b);

        // Ÿ�̸� ����
        MoveConsole(36, 10);
        SetColor(14); // �����
        printf("���� �ð�: %d��", TIME_LIMIT);

        MoveConsole(36, 12);
        SetColor(7); // �⺻ ��
        printf("���� �Է��ϼ���: ");

        if (!StartTimer(TIME_LIMIT)) { // �ð� �ʰ� Ȯ��
            MoveConsole(36, 14);
            SetColor(4); // ������
            printf("�ð� �ʰ�! ���� ����!");
            MoveConsole(36, 16);
            printf("Press any key to return to the main menu...");
            getchar();
            return;
        }

        // ����� �Է� �ޱ�
        userAnswer = GetUserInput();

        // ���� Ȯ��
        if (userAnswer == correctAnswer) {
            MoveConsole(36, 14);
            SetColor(10); // �ʷϻ�
            printf("�����Դϴ�!");
            score++;
        }
        else {
            MoveConsole(36, 14);
            SetColor(4); // ������
            printf("�����Դϴ�! ������ %d�Դϴ�.", correctAnswer);
        }
        getchar(); // ���� ������ �����ϱ� ���� ���
    }

    // ���� ���
    system("cls");
    CreateOutFrame();
    MoveConsole(36, 10);

    if (score == MAX_QUESTIONS) {
        SetColor(10); // �ʷϻ�
        printf("�����մϴ�! ��� ������ ������ϴ�!");
    }
    else {
        SetColor(4); // ������
        printf("���� ����! ���� ����: %d/%d", score, MAX_QUESTIONS);
    }

    MoveConsole(36, 12);
    SetColor(7); // �⺻ ���� ����
    printf("Press any key to return to the main menu...");
    getchar();
}
