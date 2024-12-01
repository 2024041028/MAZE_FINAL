#include "MOC.h"

#define MAX_ATTEMPTS 5
void PrintAttempts(int attempts[], char results[][10], int attemptCount) {
    MoveConsole(22, 3);
    SetColor(13);
    printf("���� ��ȸ:");
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
    target = rand() % 100 + 1;

    while (attemptCount < MAX_ATTEMPTS) {
        MoveConsole(30, 12);
        SetColor(7);
        printf("<1���� 10���� �� ���ڸ� ���纸����>");
        MoveConsole(45, 13); // ���� �Է� ��ġ
        printf("       ");       // �� ĭ ������� �����
        MoveConsole(45, 13); // Ŀ���� �ٽ� �Է� ��ġ�� �̵�
        scanf("%d", &guess);

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
            MoveConsole(25, 14);
            SetColor(10); // �ʷϻ�
            printf("Congratulations! The number was %d.          ", target);
            return; // ���� ����
        }

        attemptCount++;

        // ���� �õ� ���
        PrintAttempts(attempts, results, attemptCount);

        // ���� ��ȸ ǥ��
        MoveConsole(25, 20);
        SetColor(12); // ������
        printf("Remaining Attempts: %d", MAX_ATTEMPTS - attemptCount);
    }

    // ���� �޽���
    MoveConsole(25, 22);
    SetColor(4); // ������
    printf("Failed! The number was %d.                        ", target);
}

<<<<<<< HEAD


int main() {
    // �׵θ� ����
    system("cls");
    CreateOutFrame();

    // ���� ����
    random_number();

    // ���� �޽���
    MoveConsole(25, 16);
    SetColor(7); // �⺻ ����
    printf("�������� �ƹ�Ű�� �����ּ���.");
    getchar(); // ���α׷� ���� ���
    getchar(); // �߰� ���
    return 0;
}
=======
//int main() {
//    // �׵θ� ����
//    system("cls");
//    CreateOutFrame();
//
//    // ���� ����
//    random_number();
//
//    // ���� �޽���
//    MoveConsole(25, 16);
//    SetColor(7); // �⺻ ����
//    printf("�������� �ƹ�Ű�� �����ּ���.");
//    getchar(); // ���α׷� ���� ���
//    getchar(); // �߰� ���
//    return 0;
//}
>>>>>>> dde508484033dd8c9782ab2ca68a1125b0770e16
