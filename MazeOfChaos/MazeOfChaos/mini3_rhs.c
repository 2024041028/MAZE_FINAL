#include "MOC.h"

// ����� �Է� �Լ� (�񵿱� �Է� �� �ǽð� ī��Ʈ�ٿ�)
int InputWithCountdown(char* input, int max_length, int timeout) {
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
                input[index++] = ch;
                MoveConsole(23 + index - 1, 12);
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time;
        Sleep(50); // CPU ���� ����
    }

    input[index] = '\0'; // �Է� ����
    return 0; // �ð� �ʰ�
}

// ��� ���� ���� (���̵� ����)
void PlayTriviaQuizGame(int level) {
    char* questions[] = {
        "���ѹα��� ������ ����ΰ���?",
        "�������� ���� ���� ���� �����ΰ���?",
        "�¾�迡�� ���� ū �༺�� �����ΰ���?",
        "��Ÿ��� ������ �����ﰢ���� ������ �����ϳ���?",
        "��ǻ�Ϳ��� ���Ǵ� �⺻���� 0�� 1�� ������ �����̶�� �ϳ���?",
        "���� ��� ��ü�� �Ǵ� �µ��� ���� �� ���ΰ���?",
        "������ �߸��� ���� ������ ���� �����ΰ���?",
        "���ѹα����� ���� �� ���� �����ΰ���?",
        "�η��� ���ʷ� �޿� ������ �ش� �����ΰ���?",
        "���迡�� ���� ���� ���Ǵ� ���� �����ΰ���?"
    };

    char* answers[] = { "����", "��������Ʈ", "��", "����", "��Ʈ", "0��", "����", "�Ѱ�", "1969��", "�߱���" };
    char user_input[50];
    int num_questions = 10;
    int timeout = 10;

    // ���̵� ����
    if (level == 1) timeout = 10;
    else if (level == 2) timeout = 7;
    else if (level == 3) timeout = 5;

    srand(time(NULL));
    int random_index = rand() % num_questions;

    CreateOutFrame();

    // ���� ���
    MoveConsole(23, 2);
    printf("��� ���� ����");
    MoveConsole(23, 3);
    printf("================");
    MoveConsole(23, 5);
    printf("����: %s", questions[random_index]);

    MoveConsole(23, 8);
    printf("%d�� �ȿ� ������ �Է��ϼ���:", timeout);

    if (!InputWithCountdown(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 10);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }

    if (strcmp(user_input, answers[random_index]) == 0) {
        MoveConsole(23, 10);
        printf("����! �����߽��ϴ�!");
    }
    else {
        MoveConsole(23, 10);
        printf("����! ������ '%s'�Դϴ�.", answers[random_index]);
    }
}
