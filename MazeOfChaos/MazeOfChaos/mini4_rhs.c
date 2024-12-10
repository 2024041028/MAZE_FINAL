#include "MOC.h"

// ����� ���� ����
extern int h; // ��� (�ٸ� ���Ͽ��� ����� ���� ����)
extern char user_name[20]; // ����� �̸� (�ٸ� ���Ͽ��� ����� ���� ����)
// ����� �̸��� ��� ��� �Լ�
void DisplayUserInfo() {
    MoveConsole(23, 2); // ����� �̸� ��� ��ġ
    printf("ID: %s", user_name); // ����� �̸� ���

    MoveConsole(23, 3); // ��� ��� ��ġ
    printf("��� : ");
    SetColor(4); // ������ ��Ʈ
    for (int i = 0; i < h; i++) {
        printf("��");
    }
    SetColor(7); // �⺻��
    for (int i = h; i < 3; i++) {
        printf("��");
    }
}

// ����� �Է� �Լ� (�񵿱� �Է� �� �ǽð� ī��Ʈ�ٿ�)
int InputWithcnt3(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        MoveConsole(60, 2); // ī��Ʈ�ٿ� ��ġ (������ ���, �簢�� ��)
        printf("�ð�: %2d��  ", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') {
                input[index] = '\0';
                return 1;
            }
            else if (ch == '\b' && index > 0) {
                index--;
                MoveConsole(23 + index, 13);
                printf(" ");
                MoveConsole(23 + index, 13);
            }
            else if (index < max_length - 1) {
                SetColor(14); // �Է°� ���� ���� (�����)
                input[index++] = ch;
                MoveConsole(23 + index - 1, 13);
                printf("%c", ch);
                SetColor(7); // �⺻������ ����
            }
        }
        elapsed_time = clock() - start_time;
    }

    input[index] = '\0';
    return 0;
}

// ȭ��ǥ ����
void PlayArrowGame(int level) {
    char* arrows[] = { "��", "��", "��", "��" };
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { 1, -1, 0, 0 };
    int arrow_count = 4, timeout = 30;
    int x = 0, y = 0;
    char user_input[50];
    int user_x, user_y;

    // ���̵� ����
    if (level == 1) { arrow_count = 4; timeout = 30; }
    else if (level == 2) { arrow_count = 5; timeout = 20; }
    else if (level == 3) { arrow_count = 7; timeout = 15; }

    srand(time(NULL));

    CreateOutFrame(); // �簢�� Ʋ ����
    DisplayUserInfo(); // ����� ���� ���

    // ȭ��ǥ ���
    MoveConsole(23, 5);
    printf("ȭ��ǥ ����");
    MoveConsole(23, 6);
    printf("================");
    MoveConsole(23, 8);
    printf("���� ȭ��ǥ�� ���� ���� ��ǥ�� �����ϼ���:");
    MoveConsole(23, 9);

    for (int i = 0; i < arrow_count; i++) {
        int arrow_index = rand() % 4;
        printf("%s ", arrows[arrow_index]);
        x += dx[arrow_index];
        y += dy[arrow_index];
    }

    // �Է� �ȳ� �޽����� �� �� ����
    MoveConsole(23, 11);
    printf("%d�� �ȿ� ���� ��ǥ�� �Է��ϼ��� (��: (x, y)):", timeout);
    MoveConsole(23, 13); // �Է� ��ġ �� �� ����

    if (!InputWithcnt3(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 15);
        SetColor(14); // ����� ���
        printf("�ð� �ʰ�! ����!");
        SetColor(7); // �⺻�� ����
        return;
    }

    if (sscanf(user_input, "(%d, %d)", &user_x, &user_y) != 2) {
        MoveConsole(23, 15);
        SetColor(14); // ����� ���
        printf("�Է� ������ �߸��Ǿ����ϴ�!");
        SetColor(7); // �⺻�� ����
        return;
    }

    if (user_x == x && user_y == y) {
        MoveConsole(23, 15);
        SetColor(14); // ����� ���
        printf("����! �����߽��ϴ�!");
    }
    else {
        MoveConsole(23, 15);
        SetColor(14); // ����� ���
        printf("����! ������ (%d, %d)�Դϴ�.", x, y);
    }
    SetColor(7); // �⺻�� ����
}