#include "MOC.h"
#include <stdbool.h>
#include <windows.h>

extern int h; // ��� (�ٸ� ���Ͽ��� ����� ���� ����)
extern char user_name[20]; // ����� �̸� (�ٸ� ���Ͽ��� ����� ���� ����)


// �ܼ� ���ڵ� ����
void SetupConsoleEncoding() {
    // ��� ���ڵ��� CP949�� ���� (�ѱ� ����)
    SetConsoleOutputCP(CP_ACP);
    // �Է� ���ڵ��� CP949�� ����
    SetConsoleCP(CP_ACP);
}

// ����� �Է� �Լ� (�ð� ���� ����, �Է°� ����� ǥ��, �ѱ� ����)
bool InputWithTimeoutTrivia(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    WCHAR wide_input[256]; // �����ڵ� �Է� ó����
    DWORD chars_read;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ī��Ʈ�ٿ� ������ ��ܿ� ���
        MoveConsole(65, 2);
        printf("���� �ð�: %2d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        // �Է� ����
        if (WaitForSingleObject(hConsoleInput, 50) == WAIT_OBJECT_0) {
            if (ReadConsoleW(hConsoleInput, wide_input, max_length - 1, &chars_read, NULL)) {
                wide_input[chars_read - 2] = L'\0'; // ���� ����
                WideCharToMultiByte(CP_ACP, 0, wide_input, -1, input, max_length, NULL, NULL); // �����ڵ� -> CP949 ��ȯ
                return true; // �Է� ����
            }
        }

        elapsed_time = clock() - start_time;
    }

    return false; // �ð� �ʰ�
}

// ��� ���� ���� (������ Ʋ ����, �ѱ� ����)
void PlayTriviaQuizGame(int level) {
    SetupConsoleEncoding(); // �ܼ� ���ڵ� ����

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
