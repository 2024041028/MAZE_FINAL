#include "MOC.h"


// ���� ���� �Լ�
void random_number() {
    int target, guess;
    char result[20];

    // ���� ���� ����
    srand(time(NULL));
    target = rand() % 100 + 1;

    while (1) {
        MoveConsole(30, 12);
        SetColor(12);
        printf("���ڸ� �����Ͻÿ� (1-100): ");
        scanf("%d", &guess);

        // ��� ó��
        if (guess < target) {
            sprintf(result, "UP!");
        }
        else if (guess > target) {
            sprintf(result, "DOWN!");
        }
        else {
            sprintf(result, "����!");
            MoveConsole(25, 14);
            SetColor(10); // �ʷϻ�
            printf("���ϵ帳�ϴ�! ������ %d�Դϴ�.          ", target);
            break;
        }

        // ��� �޽��� ���
        MoveConsole(25, 14);
        SetColor(12); 
        printf("%s                      ", result); // ���� �޽��� �����
    }
}

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
