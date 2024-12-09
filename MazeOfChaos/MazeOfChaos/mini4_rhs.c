#include "MOC.h"
// ����� �Է� �Լ� (�񵿱� �Է� �� �ǽð� ī��Ʈ�ٿ�)
int InputWithCountdown2(char* input, int max_length, int timeout) {
    int start_time = clock(); // ���� �ð�
    int elapsed_time = 0;
    int index = 0;

    // Ŀ���� �Է� ��ġ�� �̵�
    MoveConsole(23, 12);

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
                input[index++] = ch; // �Է� ���ۿ� ���� �߰�
                MoveConsole(23 + index - 1, 12);
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time;
    }

    input[index] = '\0'; // �Է� ����
    return 0; // �ð� �ʰ�
}

// ȭ��ǥ ����
void PlayArrowGame() {
    char* arrows[] = { "��", "��", "��", "��" };
    int dx[] = { 0, 0, -1, 1 }; // x ��ȭ��
    int dy[] = { 1, -1, 0, 0 }; // y ��ȭ��

    int x = 0, y = 0; // ���� ��ǥ
    char user_input[50];
    int user_x, user_y;

    // ���� ����
    srand(time(NULL));

    // Ʋ ���
    CreateOutFrame();

    // ���� �ȳ� ���
    MoveConsole(23, 2);
    printf("ȭ��ǥ ����");
    MoveConsole(23, 3);
    printf("================");

    // ȭ��ǥ ��� �� ��ǥ ���
    MoveConsole(23, 5);
    printf("���� ȭ��ǥ�� ���� ���� ��ǥ�� �����ϼ���:");
    MoveConsole(23, 6);

    for (int i = 0; i < 5; i++) {
        int arrow_index = rand() % 4; // ���� ȭ��ǥ ����
        printf("%s ", arrows[arrow_index]); // ȭ��ǥ ���
        x += dx[arrow_index]; // x ��ǥ ����
        y += dy[arrow_index]; // y ��ǥ ����
    }

    // ����� �Է� ��û
    MoveConsole(23, 8);
    printf("30�� �ȿ� ���� ��ǥ�� �Է��ϼ��� (��: (x, y)):");

    if (!InputWithCountdown2(user_input, sizeof(user_input), 30)) {
        MoveConsole(23, 14);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }

    // �Էµ� ��ǥ�� ���ڷ� ��ȯ
    if (sscanf(user_input, "(%d, %d)", &user_x, &user_y) != 2) {
        MoveConsole(23, 14);
        printf("�Է� ������ �߸��Ǿ����ϴ�. (��: (2, 3))");
        return;
    }

    // ���� Ȯ��
    if (user_x == x && user_y == y) {
        MoveConsole(23, 14);
        printf("����! �����߽��ϴ�.");
    }
    else {
        MoveConsole(23, 14);
        printf("����! ������ (%d, %d)�Դϴ�.", x, y);
    }
}