#include "MOC.h"

// ����� �Է� �Լ� (�ð� ���� ����)
int InputWithcnt2(char* input, int max_length, int timeout) {
    int start_time = clock(); // ���� �ð�
    int elapsed_time = 0;
    int index = 0;

    MoveConsole(23, 12);

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ī��Ʈ�ٿ� ������ ��ܿ� ���
        MoveConsole(65, 1);
        printf("���� �ð�: %2d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') { // Enter Ű �Է� �� ����
                input[index] = '\0';
                return 1; // �Է� ����
            }
            else if (ch == '\b' && index > 0) { // Backspace ó��
                index--;
                MoveConsole(23 + index, 12);
                printf(" ");
                MoveConsole(23 + index, 12);
            }
            else if (index < max_length - 1) { // �Է� ����
                input[index++] = ch;
                MoveConsole(23 + index - 1, 12);
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time;
    }

    input[index] = '\0'; // �Է� ����
    return 0; // �ð� �ʰ�
}
// ȭ��ǥ ���� (���̵� ����)
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

    CreateOutFrame();

    // ȭ��ǥ ���
    MoveConsole(23, 2);
    printf("ȭ��ǥ ����");
    MoveConsole(23, 3);
    printf("================");
    MoveConsole(23, 5);
    printf("���� ȭ��ǥ�� ���� ���� ��ǥ�� �����ϼ���:");
    MoveConsole(23, 6);

    for (int i = 0; i < arrow_count; i++) {
        int arrow_index = rand() % 4;
        printf("%s ", arrows[arrow_index]);
        x += dx[arrow_index];
        y += dy[arrow_index];
    }

    MoveConsole(23, 8);
    printf("%d�� �ȿ� ���� ��ǥ�� �Է��ϼ��� (��: (x, y)):", timeout);

    if (!InputWithTimeout(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 10);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }

    if (sscanf(user_input, "(%d, %d)", &user_x, &user_y) != 2) {
        MoveConsole(23, 10);
        printf("�Է� ������ �߸��Ǿ����ϴ�. (��: (2, 3))");
        return;
    }

    if (user_x == x && user_y == y) {
        MoveConsole(23, 10);
        printf("����! �����߽��ϴ�!");
    }
    else {
        MoveConsole(23, 10);
        printf("����! ������ (%d, %d)�Դϴ�.", x, y);
    }
}
