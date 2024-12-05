#include "MOC.h"

#define MAX_ATTEMPTS 5

int now_level = 1;

void PrintAttempts(int attempts[], char results[][10], int attemptCount) {
    MoveConsole(22, 3);
    SetColor(7);
    for (int i = 0; i < attemptCount; i++) {
        MoveConsole(22, 4 + i);
        printf("%d -> %s", attempts[i], results[i]);
    }
}

void random_number() {
    int target, guess, attemptCount = 0;
    int attempts[MAX_ATTEMPTS] = { 0 };
    char results[MAX_ATTEMPTS][10];

    srand(time(NULL));
    if (now_level == 1) target = rand() % 20 + 1;
    else if (now_level == 2) target = rand() % 50 + 1;
    else if (now_level == 3) target = rand() % 70 + 1;

    while (attemptCount < MAX_ATTEMPTS) {
        MoveConsole(30, 12);
        SetColor(7);
        if (now_level == 1) printf("<1���� 20���� �� ���ڸ� ���纸����>");
        else if (now_level == 2) printf("<1���� 50���� �� ���ڸ� ���纸����>");
        else if (now_level == 3) printf("<1���� 70���� �� ���ڸ� ���纸����>");

        MoveConsole(45, 13); // ���� �Է� ��ġ
        printf("       ");       // �� ĭ ������� �����
        MoveConsole(45, 13); // Ŀ���� �ٽ� �Է� ��ġ�� �̵�

        // ���� �Է¹ޱ�
        if (scanf("%d", &guess) != 1) {
            // �߸��� �Է� ó��
            while (getchar() != '\n'); // �Է� ���� ����
            MoveConsole(32, 18);
            SetColor(4); // ������
            printf("��ȿ���� ���� �Է��Դϴ�. ���ڸ� �Է��ϼ���.");
            continue; // �ٽ� �Է¹ޱ�
        }

        // �Է°� ���
        attempts[attemptCount] = guess;

        // ��� ó��
        if (guess < target) {
            sprintf(results[attemptCount], "UP!");
        }
        else if (guess > target) {
            sprintf(results[attemptCount], "DOWN!");
        }
        else {
            MoveConsole(32, 18);
            SetColor(10); // �ʷϻ�
            printf("���ϵ帳�ϴ�! ���ڴ� %d�Դϴ�.", target);
            return; // ���� ����
        }

        attemptCount++;

        // ���� �õ� ���
        PrintAttempts(attempts, results, attemptCount);

        // ���� ��ȸ ǥ��
        MoveConsole(22, 2);
        SetColor(12); // ������
        printf("���� Ƚ��: %d", MAX_ATTEMPTS - attemptCount);
    }

    // ���� �޽���
    MoveConsole(32, 18);
    SetColor(4); // ������
    printf("�����ϼ̽��ϴ�! ���ڴ� %d�Դϴ�.", target);
}
