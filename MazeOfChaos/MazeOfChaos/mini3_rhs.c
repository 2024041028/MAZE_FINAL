#include "MOC.h"
#include <stdbool.h>
extern int h; // ��� (�ٸ� ���Ͽ��� ����� ���� ����)
extern char user_name[20]; // ����� �̸� (�ٸ� ���Ͽ��� ����� ���� ����)

// ����� �Է� �Լ� (�ð� ���� ����, �񵿱� ó��)
bool InputWithTimeoutTrivia(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    // �Է� �ʱ�ȭ
    input[0] = '\0';

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ī��Ʈ�ٿ� ������ ��ܿ� ���
        MoveConsole(55, 2);
        printf("���� �ð�: %2d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // Ű �Է� ����
            char ch = _getch();
            if (ch == '\r') { // Enter Ű �Է� �� ����
                input[index] = '\0';
                return true; // �Է� ����
            }
            else if (ch == '\b' && index > 0) { // Backspace ó��
                index--;
                MoveConsole(23 + index, 14);
                printf(" ");
                MoveConsole(23 + index, 14);
            }
            else if (index < max_length - 1) { // �߰� �Է� ����
                input[index++] = ch;
                SetColor(14);
                MoveConsole(23 + index - 1, 14);
                printf("%c", ch);
                SetColor(7);
            }
        }

        // ��� �ð� ����
        elapsed_time = clock() - start_time;
    }

    input[index] = '\0'; // �Է� ����
    return false; // �ð� �ʰ�
}

// ��� ���� ���� (�񵿱� �Է� �� ī��Ʈ�ٿ� ����)
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

    // ����� ID �� ��� ���
    MoveConsole(23, 2);
    printf("ID : %s", user_name);
    MoveConsole(23, 3);
    printf("��� : ");
    SetColor(4);
    for (int i = 0; i < h; i++) printf("��");
    for (int i = h; i < 3; i++) printf("��");
    SetColor(7);

    // ���� ���
    MoveConsole(23, 5);
    printf("��� ���� ����");
    MoveConsole(23, 6);
    printf("================");
    MoveConsole(23, 8);
    printf("����: %s", questions[random_index]);

    MoveConsole(23, 11);
    printf("%d�� �ȿ� ������ �Է��ϼ���:", timeout);
    MoveConsole(23, 14);

    // �񵿱� �Է� ó��
    if (!InputWithTimeoutTrivia(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 16);
        SetColor(14);
        printf("�ð� �ʰ�! ���� ����!");
        SetColor(7);
        return;
    }

    // �Է°� ���
    MoveConsole(23, 15);
    printf("�Է��� ��: ");
    SetColor(14);
    printf("%s", user_input);
    SetColor(7);

    // ���� Ȯ��
    if (strcmp(user_input, answers[random_index]) == 0) {
        MoveConsole(23, 17);
        SetColor(14);
        printf("����! �����߽��ϴ�!");
        SetColor(7);
    }
    else {
        MoveConsole(23, 17);
        SetColor(14);
        printf("����! ������ '%s'�Դϴ�.", answers[random_index]);
        SetColor(7);
    }
}
