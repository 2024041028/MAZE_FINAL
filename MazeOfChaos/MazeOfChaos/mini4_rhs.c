#include "MOC.h"

// ����� ���� ����
extern int h; // ��� (�ٸ� ���Ͽ��� ����� ���� ����)
extern char user_name[20]; // ����� �̸� (�ٸ� ���Ͽ��� ����� ���� ����)


// ����� �Է� �Լ� (�ð� ���� ����)
int InputWithCnt3(char* input, int max_length, int timeout) {
    int start_time = clock(); // ���� �ð�
    int elapsed_time = 0;
    int index = 0;

    MoveConsole(23, 15);

    while (elapsed_time < timeout * CLOCKS_PER_SEC) { // ���� �ð� �� �ݺ�
        // ī��Ʈ�ٿ� ��� (�簢�� Ʋ ������ ���)
        MoveConsole(55, 2);
        printf("���� �ð�: %2d��   ", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // Ű �Է� ����
            char ch = _getch(); // �Էµ� Ű �б�
            if (ch == '\r') { // Enter Ű �Է� �� ����
                input[index] = '\0'; // null-terminate
                return 1; // �Է� ����
            }
            else if (ch == '\b' && index > 0) { // Backspace ó��
                index--;
                MoveConsole(23 + index, 15); // ��� ��ġ ����
                printf(" ");
                MoveConsole(23 + index, 15);
            }
            else if (index < max_length - 1) { // �߰� �Է� ���� ��
                input[index++] = ch; // �Է� ���ۿ� ���� �߰�
                MoveConsole(23 + index - 1, 15); // ��� ��ġ ����
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time; // ��� �ð� ���
    }

    input[index] = '\0'; // �Է� ����
    return 0; // �ð� �ʰ�
}

// ȭ��ǥ ����
void PlayArrowGame(int level) {
    char* arrows[] = { "��", "��", "��", "��" };
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { 1, -1, 0, 0 };
    int arrow_count = 4, timeout = 30;
    int x = 0, y = 0;
    char user_input[50] = { 0 }; // �ʱ�ȭ
    int user_x = 0, user_y = 0;

    // ���̵� ����
    if (level == 1) { arrow_count = 4; timeout = 30; }
    else if (level == 2) { arrow_count = 5; timeout = 20; }
    else if (level == 3) { arrow_count = 7; timeout = 15; }

    srand((unsigned)time(NULL));

    CreateOutFrame();

    // ����� ���� ��� (x ��ǥ �����ϰ� ����)
    MoveConsole(23, 1);
    printf("����� ���̵�: %s", user_name);
    MoveConsole(23, 2);
    printf("���: %d", h);

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

    MoveConsole(23, 11);
    printf("���� ��ǥ�� �Է��ϼ��� (��: (x, y)):");

    if (!InputWithCnt3(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 13);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }

    if (sscanf(user_input, "(%d, %d)", &user_x, &user_y) != 2) {
        MoveConsole(23, 13);
        printf("�Է� ������ �߸��Ǿ����ϴ�. (��: (2, 3))");
        return;
    }

    if (user_x == x && user_y == y) {
        MoveConsole(23, 13);
        printf("����! �����߽��ϴ�!");
    }
    else {
        MoveConsole(23, 13);
        printf("����! ������ (%d, %d)�Դϴ�.", x, y);
    }
}
