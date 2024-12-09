#include "MOC.h"

extern int h; // ��� (�ٸ� ���Ͽ��� ����� ���� ����)
extern char user_name[20]; // ����� �̸� (�ٸ� ���Ͽ��� ����� ���� ����)

// ����� �Է� �Լ� (ī��Ʈ�ٿ� ����)
int InputWithcnt1(char* input, int max_length, int x, int y) {
    int index = 0;

    MoveConsole(x, y);

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') { // Enter Ű �Է� �� ����
                input[index] = '\0';
                return 1; // ���������� �Է¹���
            }
            else if (ch == '\b' && index > 0) { // Backspace ó��
                index--;
                MoveConsole(x + index * 2, y);
                printf("  "); // �������� ����
                MoveConsole(x + index * 2, y);
            }
            else if (index < max_length - 1) { // �Է� ����
                input[index++] = ch; // �Է°� ����
                MoveConsole(x + (index - 1) * 2, y);
                printf("%c", ch);
            }
        }
    }

    return 0; // ���� (���д� ����)
}

// û������ ���������� ����
void PlayGreenFrogRPS(int level) {
    const char* options[] = { "����", "����", "��" };
    char user_input[10] = { 0 };
    char reaction[10] = { 0 };
    int computer_choice;
    int timeout2 = 5;

    // ���̵� ����
    if (level == 1) { timeout2 = 5; }
    else if (level == 2) { timeout2 = 4; }
    else if (level == 3) { timeout2 = 3; }

    // �ʱ�ȭ
    srand(time(NULL));

    CreateOutFrame();

    // ����� ID�� ��� ���
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
    printf("=======================");

    // ù ��° �Է� ��û (ī��Ʈ�ٿ� ����)
    MoveConsole(23, 8);
    printf("����, ����, �� �� �ϳ��� �Է��ϼ���:");
    MoveConsole(23, 10);
    SetColor(14);
    if (!InputWithcnt1(user_input, sizeof(user_input), 23, 12)) {
        SetColor(7);
        MoveConsole(23, 14);
        printf("�Է� ����! ���� ����!");
        return;
    }

    // �Է°� ���
    MoveConsole(23, 12);
    SetColor(14);
    printf("�Է��� ��: %s", user_input);
    SetColor(7);

    // ��ǻ�� ���� ���
    MoveConsole(23, 14);
    printf("��ǻ���� ����: ");
    computer_choice = rand() % 3; // ��ǻ�� ���� ����
    SetColor(14);
    printf("%s", options[computer_choice]);
    SetColor(7);

    // �� ��° �Է� ��û (ī��Ʈ�ٿ� ����)
    MoveConsole(23, 16);
    printf("����� ���� ������ �Է��ϼ���");
    MoveConsole(23, 17);
    printf("('�̰��', '����', '����'): ");
    MoveConsole(23, 19);
    SetColor(14);
    if (!InputWithcnt1(reaction, sizeof(reaction), timeout2, 23, 20)) {
        SetColor(7);
        MoveConsole(23, 22);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }
    SetColor(7);

    // ��� Ȯ��
    int user_choice = -1;
    if (strcmp(user_input, "����") == 0) user_choice = 0;
    else if (strcmp(user_input, "����") == 0) user_choice = 1;
    else if (strcmp(user_input, "��") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 22);
        SetColor(14);
        printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.");
        SetColor(7);
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    // ���� ��� ���
    MoveConsole(23, 22);
    SetColor(14);
    if ((result == 0 && strcmp(reaction, "����") == 0) ||
        (result == 1 && strcmp(reaction, "����") == 0) ||
        (result == 2 && strcmp(reaction, "�̰��") == 0)) {
        printf("����! ����!");
    }
    else {
        printf("Ʋ�Ƚ��ϴ�. ����!");
    }
    SetColor(7);
}