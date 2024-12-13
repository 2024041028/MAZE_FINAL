#include "MOC.h"

#define MAX_QUESTIONS 5    // ���� ��
#define TIME_LIMIT 15      // ���� �ð� (��)
#define PASS_SCORE 3       // ��� ����

// ����� �Է��� �޴� �Լ� (ī��Ʈ�ٿ� ����)
int Countdown(char* input, int max_length, int timeout) {
    int start_time = clock(); // ���� �ð�
    int elapsed_time = 0;
    int index = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) { // ���� �ð� �� �ݺ�
        // ī��Ʈ�ٿ� ������ ��ܿ� ���
        MoveConsole(55, 1);
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
                    MoveConsole(54 + index, 12); // �Է� ��ġ ����
                    printf(" "); // �����
                    MoveConsole(54 + index, 12); // �ٽ� �Է� ��ġ�� �̵�
                }
            }
            else if (index < max_length - 1) { // �߰� �Է� ���� ��
                input[index++] = ch;
                MoveConsole(54 + index - 1, 12); // �Է� ��ġ ����
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time; // ��� �ð� ������Ʈ
    }

    input[index] = '\0'; // �Է� ����
    return 0; // �ð� �ʰ�
}

// ���� ��� ���� ���� �Լ�
void GenerateMathProblem(int* a, int* b, char* op, int* answer, int now_level) {
    int max_range;
    if (now_level == 1) {
        max_range = 50; // 1�ܰ�: 1���� 50
    }
    else if (now_level == 2) {
        max_range = 100; // 2�ܰ�: 1���� 100
    }
    else {
        max_range = 200; // 3�ܰ�: 1���� 200
    }

    *a = rand() % max_range + 1; // 1���� max_range ������ ����
    *b = rand() % max_range + 1;
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
int PlayMathGame() {
    ShowInstructionsAndMenu(6);
    system("cls");
    CreateOutFrame(now_color_num); // ���� Ʋ ����

    srand(time(NULL)); // ���� �õ� ����

    int score = 0; // ���� ���� ��
    int a, b, userAnswer, correctAnswer;
    char op; // ������ ���� ���� �߰�
    int now_level = 1; // �ʱ� ���� ����

    
    SetColor(7); // �⺻ ���� ����
    Sleep(1000); // ������ �޽��� ��� �� 1�� ���

    for (int i = 1; i <= MAX_QUESTIONS; i++) {
        // ���� ����
        GenerateMathProblem(&a, &b, &op, &correctAnswer, now_level);

        // ���� ���
        system("cls");
        CreateOutFrame(now_color_num);
        MoveConsole(36, 8);
        SetColor(11); // �Ķ���
        printf("���� %d�� %d %c %d = ?", i, a, op, b);

        // ����� �Է� ��û (ī��Ʈ�ٿ� ����)
        MoveConsole(36, 10);
        SetColor(14); // �����
        printf("���� �ð�: %d��\n", TIME_LIMIT);
        MoveConsole(36, 12);
        SetColor(7); // �⺻ ��
        printf("���� �Է��ϼ���: "); // �Է� ��û ���
        MoveConsole(64, 12); // �Է� ��ġ�� 4ĭ ���������� ����

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
    CreateOutFrame(now_color_num);
    MoveConsole(34, 10);

    if (score >= PASS_SCORE) { // ��� ���ؿ� ���� �Ǵ�
        SetColor(10); // �ʷϻ�
        printf("�����մϴ�! ����ϼ̽��ϴ�!");
        return 1;
    }
    else {
        SetColor(4); // ������
        printf("���� ����! ���� ����: %d/%d\n", score, MAX_QUESTIONS);
        MoveConsole(36, 11);
        printf("���ӿ� �����ϼ̽��ϴ�");
        return 0;
    }

    MoveConsole(26, 12);
    SetColor(7); // �⺻ ���� ����
    printf("Press any key to return to the main menu...");
    getchar();
}
