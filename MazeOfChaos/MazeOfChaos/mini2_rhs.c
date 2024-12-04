#include "MOC.h"

// ����� �Է� �Լ� (�񵿱� �Է� �� �ǽð� ī��Ʈ�ٿ�)
int InputWithCount(char* input, int max_length, int timeout) {
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
    }

    input[index] = '\0'; // �Է� ����
    return 0; // �ð� �ʰ�
}

// �������� ����
void PlayAscendingGame() {
    int numbers[10];
    char user_input[100];
    int user_numbers[10];

    // ���� ���� �� �ʱ�ȭ
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 100 + 1; // 1~100 ������ ����
    }

    // Ʋ ���
    CreateOutFrame();

    // ���� �ȳ� ���
    MoveConsole(23, 2);
    printf("�������� ����");
    MoveConsole(23, 3);
    printf("================");

    // ���� �迭 ���
    MoveConsole(23, 5);
    printf("���� ���ڵ��� ������������ �����ϼ���:");
    MoveConsole(23, 6);
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }

    // ����� �Է� ��û (ī��Ʈ�ٿ� ����)
    MoveConsole(23, 8);
    printf("60�� �ȿ� ���ڸ� �Է��ϼ��� (�������� ����):");
    MoveConsole(23, 12); // ��� ����� ������ x������ �Է� ����

    if (!InputWithCount(user_input, sizeof(user_input), 60)) {
        MoveConsole(23, 14);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }

    // ����� �Է� ���� �迭�� ��ȯ
    char* token = strtok(user_input, " ");
    for (int i = 0; token != NULL && i < 10; i++) {
        user_numbers[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // ����� �Է� ���� (������������ Ȯ��)
    for (int i = 0; i < 9; i++) {
        if (user_numbers[i] > user_numbers[i + 1]) {
            MoveConsole(23, 14);
            printf("����! ���������� �ƴմϴ�.");
            return;
        }
    }

    // ���� �޽���
    MoveConsole(23, 14);
    printf("����! �ùٸ��� ������������ �����߽��ϴ�.");
}

/*int main() {
    system("cls"); // ȭ�� �ʱ�ȭ
    PlayAscendingGame(); // �������� ���� ����
    MoveConsole(23, 15);
    printf("Press any key to exit��");
    getchar();
    return 0;
}*/