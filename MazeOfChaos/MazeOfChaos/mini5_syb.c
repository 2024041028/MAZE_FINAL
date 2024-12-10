#include "MOC.h"

// ���� ���� ���� �Լ�
int GetRandomColor() {
    return rand() % 15 + 1; // 1~15 ������ ���� �ڵ� ��ȯ
}

void PlayReflexGame() {
    int now_level = 1; // �ʱ� ����
    int is_now_displayed = 0; // '����' ��� ����
    char input;
    int reaction_start_time = 0;
    const char* confusing_words[] = { "�ڱ�", "����", "����", "�ڱ�", "����" }; // ȥ�� �ܾ� �迭
    int num_confusing_words = sizeof(confusing_words) / sizeof(confusing_words[0]);

    // ������ �ð� ���� ����
    float level_time_limit[] = { 1.0, 0.7, 0.5 };
    if (now_level < 1 || now_level > 3) now_level = 1; // ���� ���� ����

    srand(time(NULL));

    const int display_x = 45; // ��� ��ġ x ��ǥ
    const int display_y = 12; // ��� ��ġ y ��ǥ

    // �ȳ� �޽��� ���
    MoveConsole(27, 5);
    SetColor(7);
    printf("'����'�̶�� ���ڰ� ������ 'p'�� ��������!");

    // ���ѽð� �ȳ� �޽���
    MoveConsole(36, 6);
    SetColor(7);
    printf("%d�ܰ�: ���� �ð� %.1f��", now_level, level_time_limit[now_level - 1]);

    Sleep(2000); // ����ڿ��� �غ� �ð� ����

    while (1) {
        // �÷��� �ʱ�ȭ
        is_now_displayed = 0;

        // ȭ�鿡 ���
        MoveConsole(display_x, display_y);
        if (rand() % 10 == 0) { // 10% Ȯ���� "����" �Ǵ� ȥ�� �ܾ� ���
            if (rand() % 2 == 0) {
                SetColor(GetRandomColor()); // ���� ���� ����
                printf("����  ");
                is_now_displayed = 1;
                reaction_start_time = clock(); // ���� �ð� ��� ����
            }
            else {
                int idx = rand() % num_confusing_words;
                SetColor(GetRandomColor()); // ���� ���� ����
                printf("%s  ", confusing_words[idx]);
                Sleep(300); // ȥ�� �ܾ� ǥ�� �� ���� ������
                continue;
            }
        }
        else { // ���� ���
            int random_number = rand() % 100;
            SetColor(GetRandomColor()); // ���� ���� ����
            printf("%02d  ", random_number);
            Sleep(300);
            // ����ڰ� ���ڰ� ��µ� �� 'p'�� ������ ��� ����
            if (_kbhit()) { // Ű �Է� ����
                input = _getch();
                if (input == 'p') {
                    MoveConsole(30, 15);
                    SetColor(4);
                    printf("����! �߸��� ��Ȳ���� 'p'�� �������ϴ�. ");
                    return; // ���� �� ���� ����
                }
            }
            continue;
        }

        // "����"�� ��µ� �� ����� ���� ���
        while (1) {
            if (_kbhit()) { // Ű �Է� ����
                input = _getch();

                if (is_now_displayed && input == 'p') { // '����'�� �ùٸ� ����
                    int reaction_time = clock() - reaction_start_time;
                    MoveConsole(37, 15);
                    SetColor(10);
                    printf("����! ���� �ð�: %.2f��  ", (float)reaction_time / CLOCKS_PER_SEC);
                    return;
                }

                // '����'�� ��µ��� ���� ���¿��� 'p' �Է� ó��
                if (input == 'p') {
                    MoveConsole(30, 15);
                    SetColor(4);
                    printf("����! �߸��� ��Ȳ���� 'p'�� �������ϴ�.");
                    return; // ���� �� ���� ����
                }
            }

            // "����" ���¿��� �ð� �ʰ� ó��
            if (is_now_displayed && (float)(clock() - reaction_start_time) / CLOCKS_PER_SEC > level_time_limit[now_level - 1]) {
                MoveConsole(39, 15);
                SetColor(4);
                printf("�ð� �ʰ�! ����!");
                return; // �ð� �ʰ� �� ���� ����
            }
        }
    }
}
