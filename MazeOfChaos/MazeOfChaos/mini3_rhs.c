#include "MOC.h"
#include <stdbool.h>
#include <windows.h>

extern int h; // ���
extern char user_name[20]; // ����� �̸�

// �ܼ� ���ڵ� ����
void SetupConsoleEncoding() {
    SetConsoleOutputCP(CP_ACP);
    SetConsoleCP(CP_ACP);
}

// �ؽ�Ʈ �ٳѱ� ó�� �Լ�
void PrintWrappedText(const char* text, int x, int y, int width) {
    int len = strlen(text);
    int line_start = 0;

    while (line_start < len) {
        MoveConsole(x, y++);
        for (int i = 0; i < width && (line_start + i) < len; i++) {
            printf("%c", text[line_start + i]);
        }
        line_start += width;
    }
}

// ����� �Է� �Լ� (ī��Ʈ�ٿ� ����, �Է°� ����� ǥ��, �ٳѱ� ó��)
bool InputWithTimeoutTrivia(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ī��Ʈ�ٿ� ������ ��ܿ� ��� (�簢�� Ʋ �ȿ��� ����)
        MoveConsole(55, 2);
        printf("          "); // �ܿ� �� �����
        MoveConsole(55, 2);
        printf("���� �ð�: %2d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        // Ű �Է� Ȯ��
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') { // Enter Ű
                input[index] = '\0';
                return true; // �Է� �Ϸ�
            }
            else if (ch == '\b' && index > 0) { // Backspace
                index--;
                MoveConsole(23 + index, 14);
                printf(" ");
                MoveConsole(23 + index, 14);
            }
            else if (index < max_length - 1) { // �Է� ������ ���
                input[index++] = ch;
                SetColor(14);
                MoveConsole(23 + index - 1, 14);
                printf("%c", ch);
                SetColor(7);
            }
        }

        // ��� �ð� ���
        elapsed_time = clock() - start_time;

        // ȭ�� ������Ʈ�� ���� ����
        Sleep(50);
    }

    input[index] = '\0';
    return false; // �ð� �ʰ�
}

// ��� ���� ����
int PlayTriviaQuizGame(int level) {

    ShowInstructionsAndMenu(2);
    SetupConsoleEncoding();

    char* questions[] = {
        "���ѹα��� ������ ����ΰ���?",
        "�������� ���� ���� ���� �����ΰ���?",
        "�¾�迡�� ���� ū �༺�� �����ΰ���?",
        "��Ÿ��� ������ �����ﰢ���� ������ �����ϳ���?",
        "��ǻ�Ϳ��� ���Ǵ� �⺻���� 0�� 1�� ������ �����̶�� �ϳ���?",
        "���� ��� ��ü�� �Ǵ� �µ��� ���� �� ���ΰ���?",
        "������ �߸��� ���� ������ ���� �����ΰ���?",
        "���ѹα����� ���� �� ���� �����ΰ���?",
        "�η��� ���ʷ� �޿� ������ �ش� �����ΰ���?",
        "���迡�� ���� ���� ���Ǵ� ���� �����ΰ���?"
    };

    char* answers[] = { "����", "��������Ʈ", "��", "����", "��Ʈ", "0��", "����", "�Ѱ�", "1969��", "�߱���" };
    char user_input[50];
    int num_questions = 10;
    int timeout = 10;

    // ���̵� ����
    if (level == 1) timeout = 10;
    else if (level == 2) timeout = 7;
    else if (level == 3) timeout = 5;

    srand(time(NULL));
    int random_index = rand() % num_questions;


    // ����� ID �� ��� ���
    MoveConsole(23, 2);
    printf("ID : %s", user_name);
    MoveConsole(23, 3);
    printf("��� : ");
    SetColor(4);
    for (int i = 0; i < h; i++) printf("��");
    for (int i = h; i < 3; i++) printf("��");
    SetColor(7);

    // ���� ���
    MoveConsole(23, 5);
    printf("��� ���� ����");
    MoveConsole(23, 6);
    printf("================");
    PrintWrappedText(questions[random_index], 23, 8, 40); // �ٳѱ� ó���� ���� ���

    MoveConsole(23, 12);
    printf("%d�� �ȿ� ������ �Է��ϼ���:", timeout);
    MoveConsole(23, 14);
    if (!InputWithTimeoutTrivia(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 16);
        SetColor(14);
        printf("�ð� �ʰ�! ���� ����!");
        SetColor(7);
        return;
    }

    MoveConsole(23, 14);
    SetColor(14);
    printf("�Է°�: %s", user_input); // �Է��� �� ���
    SetColor(7);

    if (strcmp(user_input, answers[random_index]) == 0) {
        MoveConsole(23, 16);
        SetColor(14);
        printf("����! �����߽��ϴ�!");
        SetColor(7);
        return 1;
    }
    else {
        MoveConsole(23, 16);
        SetColor(14);
        printf("����! ������ '%s'�Դϴ�.", answers[random_index]);
        SetColor(7);
        return 0;
    }
}
