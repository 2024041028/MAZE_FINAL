#include "MOC.h"

// ����� �Է� �Լ� (�񵿱� �Է� �� �ǽð� ī��Ʈ�ٿ�)
int InputWithcnt(char* input, int max_length, int timeout) {
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
                input[index] = '\0'; // �Է� ����
                return 1; // ���������� �Է¹���
            }
            else if (ch == '\b') { // Backspace Ű ó��
                if (index > 0) {
                    index--;
                    MoveConsole(23 + index, 12); // ��� ����� ������ x������ �Է�
                    printf(" ");
                    MoveConsole(23 + index, 12);
                }
            }
            else if (index < max_length - 1) { // �߰� �Է� ���� ��
                input[index++] = ch; // �Է� ���ۿ� ���� �߰�
                MoveConsole(23 + index - 1, 12); // ��� ����� ������ x������ �Է�
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time; // ��� �ð� ���
        Sleep(50); // ª�� ��� �ð����� CPU ���� ����
    }

    input[index] = '\0'; // �Է� ����
    return 0; // �ð� �ʰ�
}

// �������� ���� ���� (���̵� ����)
void PlayAscendingGame(int level) {
    int numbers[10], user_input[10];
    char input[50];
    int count = 5, timeout = 30;

    // ���̵� ����
    if (level == 1) { count = 5; timeout = 30; }
    else if (level == 2) { count = 6; timeout = 30; }
    else if (level == 3) { count = 10; timeout = 40; }

    srand(time(NULL));

    CreateOutFrame();

    // ���� ���
    MoveConsole(23, 2);
    printf("�������� ���� ����");
    MoveConsole(23, 3);
    printf("================");
    MoveConsole(23, 5);
    printf("���� ���ڸ� ������������ �����ϼ���:");
    MoveConsole(23, 6);
    for (int i = 0; i < count; i++) {
        numbers[i] = rand() % 100;
        printf("%d ", numbers[i]);
    }

    // ����� �Է�
    MoveConsole(23, 8);
    printf("%d�� �ȿ� ���ĵ� ���ڸ� �Է��ϼ���:", timeout);

    if (!InputWithcnt(input, sizeof(input), timeout)) {
        MoveConsole(23, 10);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }

    // �Էµ� ���� �Ľ�
    char* token = strtok(input, " ");
    for (int i = 0; i < count; i++) {
        if (!token || sscanf(token, "%d", &user_input[i]) != 1) {
            MoveConsole(23, 12);
            printf("�Է� ����! ����!");
            return;
        }
        token = strtok(NULL, " ");
    }

    // ���� Ȯ��
    for (int i = 0; i < count - 1; i++) {
        if (user_input[i] > user_input[i + 1]) {
            MoveConsole(23, 12);
            printf("����! ����!");
            return;
        }
    }

    MoveConsole(23, 12);
    printf("����! �����߽��ϴ�!");
}
