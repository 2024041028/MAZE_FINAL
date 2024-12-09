#include "MOC.h"
#include <stdbool.h>
#include <windows.h>

extern int h; // ��� (�ٸ� ���Ͽ��� ����� ���� ����)
extern char user_name[20]; // ����� �̸� (�ٸ� ���Ͽ��� ����� ���� ����)

// �ܼ� ���ڵ� ����
void SetupConsoleEncoding2() {
    SetConsoleOutputCP(CP_ACP);
    SetConsoleCP(CP_ACP);
}

// ����� �Է� �Լ� (�ð� ���� ����, �Է°� ����� ǥ��, ī��Ʈ�ٿ�)
bool InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ī��Ʈ�ٿ� ������ ��ܿ� ���
        MoveConsole(55, 2);
        printf("            ");
        MoveConsole(55, 2);
        printf("���� �ð�: %d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // Ű �Է� Ȯ��
            char ch = _getch();
            if (ch == '\r') { // Enter Ű
                input[index] = '\0';
                return true; // �Է� �Ϸ�
            }
            else if (ch == '\b' && index > 0) { // Backspace ó��
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

        elapsed_time = clock() - start_time;
        Sleep(50); // ȭ�� ������Ʈ�� ���� ����
    }

    input[index] = '\0';
    return false; // �ð� �ʰ�
}

// û������ ���������� ����
void PlayGreenFrogRPS(int level) {
    SetupConsoleEncoding2();

    const char* options[] = { "����", "����", "��" };
    char user_input[20];
    char reaction[20];
    int computer_choice;
    int timeout = 10;

    // ���̵� ����
    if (level == 1) timeout = 10;  // ����: 10��
    else if (level == 2) timeout = 7;  // ����: 7��
    else if (level == 3) timeout = 5;  // �����: 5��

    srand(time(NULL));
    CreateOutFrame();

    // ����� ID �� ��� ���
    MoveConsole(23, 2);
    printf("ID : %s", user_name);
    MoveConsole(23, 3);
    printf("��� : ");
    SetColor(4);
    for (int i = 0; i < h; i++) printf("��");
    for (int i = h; i < 3; i++) printf("��");
    SetColor(7);

    // ���� �ȳ� ���
    MoveConsole(23, 5);
    printf("û������ ���������� ����");
    MoveConsole(23, 6);
    printf("======================");

    // ù ��° �Է� ��û
    MoveConsole(23, 8);
    printf("����, ����, �� �� �ϳ��� �Է��ϼ���:");
    MoveConsole(23, 10);

    if (!InputWithTimeout(user_input, sizeof(user_input), 20)) { // ù ��° �Է�
        MoveConsole(23, 12);
        printf("�ð� �ʰ�! ���� ����.");
        return;
    }

    // �Է°� ���
    MoveConsole(23, 12);
    SetColor(14);
    printf("�Է°�: %s", user_input);
    SetColor(7);

    // ��ǻ�� ���� ���
    computer_choice = rand() % 3;
    MoveConsole(23, 14);
    printf("��ǻ�� ����: %s", options[computer_choice]);

    // ��� ���
    int user_choice = -1;
    if (strcmp(user_input, "����") == 0) user_choice = 0;
    else if (strcmp(user_input, "����") == 0) user_choice = 1;
    else if (strcmp(user_input, "��") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 16);
        printf("�߸��� �Է��Դϴ�. ���� ����.");
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    // �� ��° �Է� ��û (���� �Է�)
    MoveConsole(23, 16);
    printf("����� ���� ������ �Է��ϼ��� (�̰��, ����, ����):");
    MoveConsole(23, 18);

    if (!InputWithTimeout(reaction, sizeof(reaction), timeout)) { // �� ��° �Է�
        MoveConsole(23, 20);
        SetColor(14);
        printf("�ð� �ʰ�! ���� ����!");
        SetColor(7);
        return;
    }

    // ���� Ȯ��
    bool success = false;
    if (result == 0 && strcmp(reaction, "����") == 0) success = true;
    else if (result == 1 && strcmp(reaction, "����") == 0) success = true;
    else if (result == 2 && strcmp(reaction, "�̰��") == 0) success = true;

    // ���� ��� ���
    MoveConsole(23, 20);
    if (success) {
        SetColor(14);
        printf("����! �����߽��ϴ�!");
        SetColor(7);
    }
    else {
        SetColor(14);
        printf("Ʋ�Ƚ��ϴ�. ����!");
        SetColor(7);
    }
}
