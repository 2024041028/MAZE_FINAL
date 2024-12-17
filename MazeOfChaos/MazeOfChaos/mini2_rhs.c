#include "MOC.h"

extern int h; // ��� (�ٸ� ���Ͽ��� ����� ���� ����)
extern char user_name[20];

// ����� �Է� �Լ� (�ð� ���� ����, �Է°� ����� ǥ��)
int InputWithTimeoutAscending(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ī��Ʈ�ٿ� ������ ��ܿ� ���
        MoveConsole(55, 2);
        printf("���� �ð�: %2d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') {
                input[index] = '\0';
                return 1; // �Է� ����
            }
            else if (ch == '\b' && index > 0) {
                index--;
                MoveConsole(23 + index, 14);
                printf(" ");
                MoveConsole(23 + index, 14);
            }
            else if (index < max_length - 1) {
                input[index++] = ch;
                SetColor(14);
                MoveConsole(23 + index - 1, 14);
                printf("%c", ch);
                SetColor(7);
            }
        }

        elapsed_time = clock() - start_time;
    }

    input[index] = '\0';
    return 0; // �ð� �ʰ�
}

// �������� ���� ���� (������ Ʋ ����)
int PlayAscendingGame(int level)

{ 
   

    int numbers[10], user_input[10];
    char input[50];
    int count = 5, timeout = 30;

    // ���̵� ����
    if (level == 1) { count = 5; timeout = 30; }
    else if (level == 2) { count = 6; timeout = 30; }
    else if (level == 3) { count = 10; timeout = 40; }

    srand(time(NULL));



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
    printf("�������� ���� ����");
    MoveConsole(23, 6);
    printf("================");
    MoveConsole(23, 8);
    printf("���� ���ڸ� ������������ �����ϼ���:");
    MoveConsole(23, 9);
    for (int i = 0; i < count; i++) {
        numbers[i] = rand() % 100;
        printf("%d ", numbers[i]);
    }

    // ����� �Է� ��û
    MoveConsole(23, 11);
    printf("%d�� �ȿ� ���ĵ� ���ڸ� �Է��ϼ���:", timeout);
    MoveConsole(23, 14);
    if (!InputWithTimeoutAscending(input, sizeof(input), timeout)) {
        MoveConsole(23, 16);
        SetColor(14);
        printf("�ð� �ʰ�! ���� ����!");
        SetColor(7);
        return 0;
    }

    // �Էµ� ���� �Ľ�
    char* token = strtok(input, " ");
    for (int i = 0; i < count; i++) {
        if (!token || sscanf(token, "%d", &user_input[i]) != 1) {
            MoveConsole(23, 16);
            SetColor(14);
            printf("�Է� ����! ����!");
            SetColor(7);
            return;
        }
        token = strtok(NULL, " ");
    }

    // ���� Ȯ��
    for (int i = 0; i < count - 1; i++) {
        if (user_input[i] > user_input[i + 1]) {
            MoveConsole(23, 16);
            SetColor(14);
            printf("����! ����!");
            SetColor(7);
            return 0;
        }
    }

    MoveConsole(23, 16);
    SetColor(14);
    printf("����! �����߽��ϴ�!");
    SetColor(7);
    return 1;
}
