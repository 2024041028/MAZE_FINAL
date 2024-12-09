#include "MOC.h"

// ����� �Է� �Լ� (�ð� ���� ����)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // ���� �ð�
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        MoveConsole(65, 1);
        printf("���� �ð�: %2d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) {
            MoveConsole(23, 10);
            printf("                             ");
            MoveConsole(23, 10);
            fgets(input, max_length, stdin);
            input[strcspn(input, "\n")] = '\0';
            return 1; // ���������� �Է¹���
        }

        elapsed_time = clock() - start_time;
    }

    return 0; // �ð� �ʰ�
}

// û������ ���������� ���� (���̵� ����)
void PlayGreenFrogRPS(int level) {
    const char* options[] = { "����", "����", "��" };
    char user_input[10];
    char reaction[10];
    int computer_choice;

    // ���̵� ����
    int timeout = 10; // �⺻ �ð�
    if (level == 1) timeout = 10;
    else if (level == 2) timeout = 5;
    else if (level == 3) timeout = 3;

    srand(time(NULL));

    // Ʋ ���
    CreateOutFrame();

    // ���� �ȳ� ���
    MoveConsole(23, 2);
    printf("û������ ���������� ����");
    MoveConsole(23, 3);
    printf("=======================");

    // ����� �Է� ��û
    MoveConsole(23, 5);
    printf("����, ����, �� �� �ϳ��� �Է��ϼ���:");
    InputWithTimeout(user_input, sizeof(user_input), timeout);

    MoveConsole(23, 7);
    printf("��ǻ���� ����: ");
    computer_choice = rand() % 3;
    printf("%s", options[computer_choice]);

    int user_choice = -1;
    if (strcmp(user_input, "����") == 0) user_choice = 0;
    else if (strcmp(user_input, "����") == 0) user_choice = 1;
    else if (strcmp(user_input, "��") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.");
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    MoveConsole(23, 9);
    printf("����� ���� ������ �Է��ϼ��� ('�̰��', '����', '����'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), timeout)) {
        MoveConsole(23, 11);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }

    int success = 0;
    if (result == 0 && strcmp(reaction, "����") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "����") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "�̰��") == 0) success = 1;

    MoveConsole(23, 11);
    if (success) printf("����! ����!");
    else printf("Ʋ�Ƚ��ϴ�. ����!");
}
