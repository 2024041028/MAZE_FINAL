#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "MOC.h"

#define MAX_QUESTIONS 5    // ���� ��
#define TIME_LIMIT 30      // ���� �ð� (��)

// ����� �Է��� �޴� �Լ� (ī��Ʈ�ٿ� ����)
int Countdown(char* input, int max_length, int timeout) {
    int start_time = clock(); // ���� �ð�
    int elapsed_time = 0;
    int index = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) { // ���� �ð� �� �ݺ�
        // ī��Ʈ�ٿ� ������ ��ܿ� ���
        MoveConsole(65, 1);
        printf("���� �ð�: %2d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // Ű �Է� ����
            char ch = _getch(); // Ű �Է��� ����
            if (ch == '\r') { // Enter Ű �Է� �� ����
                input[index] = '\0';
                return 1; // ���������� �Է¹���
            }
            else if (ch == '\b') { // Backspace Ű ó��
                if (index > 0) {
                    index--;
                    MoveConsole(23 + index, 12);
                    printf(" ");
                    MoveConsole(23 + index, 12);
                }
            }
            else if (index < max_length - 1) { // �߰� �Է� ���� ��
                input[index++] = ch;
                MoveConsole(23 + index - 1, 12);
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time; // ��� �ð� ������Ʈ
    }

    input[index] = '\0'; // �Է� ����
    return 0; // �ð� �ʰ�
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

// ��� ���� �Լ�
void PlayMathGame() {
    system("cls");
    CreateOutFrame(); // ���� Ʋ ����

    srand(time(NULL)); // ���� �õ� ����

    int score = 0; // ���� ���� ��
    int a, b, userAnswer, correctAnswer;
    char op; // ������ ���� ���� �߰�

    // ���� �ȳ� �޽���
    MoveConsole(36, 5);
    SetColor(14); // �����
    printf("��� ���ӿ� ���� ���� ȯ���մϴ�!");
    MoveConsole(36, 6);
    printf("30�� �ȿ� ���� ���纸����!");
    SetColor(7); // �⺻ ���� ����

    for (int i = 1; i <= MAX_QUESTIONS; i++) {
        // ���� ����
        GenerateMathProblem(&a, &b, &op, &correctAnswer);

        // ���� ���
        system("cls");
        CreateOutFrame();
        MoveConsole(36, 8);
        SetColor(11); // �Ķ���
        printf("���� %d: %d %c %d = ?", i, a, op, b);

        // ����� �Է� ��û (ī��Ʈ�ٿ� ����)
        MoveConsole(36, 10);
        SetColor(14); // �����
        printf("���� �ð�: %d��\n", TIME_LIMIT);
        MoveConsole(36, 12);
        SetColor(7); // �⺻ ��
        printf("���� �Է��ϼ���: "); // �Է� ��û ���
        MoveConsole(50, 12); // �Է� ��ġ ���� (���������� �̵�)

        char user_input[100]; // ����� �Է��� ���� �迭

        // ����� �Է� �ޱ� (Ÿ�̸� ����)
        if (!Countdown(user_input, sizeof(user_input), TIME_LIMIT)) {
            MoveConsole(36, 14);
            SetColor(4); // ������
            printf("�ð� �ʰ�! ���� ����!");
            MoveConsole(36, 16);
            printf("Press any key to return to the main menu...");
            getchar();
            return;
        }

        // �Է°��� ������ ��ȯ
        userAnswer = atoi(user_input);

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

        // ���� ���� ���� ���
        MoveConsole(36, 16);
        SetColor(7); // �⺻ ���� ����
        printf("���� ����: %d / %d", score, i);
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