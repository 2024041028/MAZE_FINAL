#include "MOC.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


void PlayReflexGame() {
    int now_level = 1; // �ʱ� ����
    int is_now_displayed = 0;       // '����' ��� ����
    int is_confusing_displayed = 0; // ȥ�� �ܾ� ��� ����
    int is_number_displayed = 0;    // ���� ��� ����
    char input;
    int reaction_time = 0;
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
    printf("'����'�̶�� ���ڰ� ������ 'p'�� ��������!");

    // ���ѽð� �ȳ� �޽���
    MoveConsole(36, 6);
    printf("%d�ܰ�: ���� �ð� %.1f��", now_level, level_time_limit[now_level - 1]);

    Sleep(2000); // ����ڿ��� �غ� �ð� ����

    while (1) {
        // �ʱ�ȭ
        MoveConsole(display_x, display_y);
        is_now_displayed = 0;
        is_confusing_displayed = 0;
        is_number_displayed = 0;

        if (rand() % 10 == 0) { // 10% Ȯ���� Ư�� �ܾ� ���
            if (rand() % 2 == 0) {
                printf("����  ");
                is_now_displayed = 1; // '����' ǥ�õ�
                reaction_time = clock(); // ���� �ð� ��� ����
                break;
            }
            else {
                int idx = rand() % num_confusing_words;
                printf("%s  ", confusing_words[idx]);
                is_confusing_displayed = 1; // ȥ�� �ܾ� ǥ�õ�
                Sleep(300); // ȥ�� �ܾ� ǥ�� �� ���� ������
                continue;
            }
        }
        else {
            int random_number = rand() % 100;
            printf("%02d  ", random_number); // ���� ���
            is_number_displayed = 1; // ���� ��� ���� ����
            Sleep(300); // ���� ǥ�� �� ���� ����
        }
    }

    // ���� �ð� ���� �� ����� �Է� ���
    while (1) {
        if (_kbhit()) { // Ű �Է� ����
            input = _getch();

            // ���� ���� ó��
            if (is_now_displayed && input == 'p') {
                reaction_time = clock() - reaction_time;
                MoveConsole(30, 15);
                printf("����! ���� �ð�: %.2f��  ", (float)reaction_time / CLOCKS_PER_SEC);
                return;
            }

            // �߸��� ���� ó��
            MoveConsole(30, 15);
            if (input == 'p') {
                if (is_confusing_displayed) {
                    printf("����! ȥ�� �ܾ�� 'p'�� �������ϴ�.          ");
                }
                else if (is_number_displayed) {
                    printf("����! ���ڿ��� 'p'�� �������ϴ�.              ");
                }
                else {
                    printf("����! �߸��� ���¿��� 'p'�� �������ϴ�.      ");
                }
            }
            else {
                printf("����! 'p'�� ������ �մϴ�.                     ");
            }
            return;
        }

        // ���� �ð� ���� (������ ���� �ð�)
        if ((float)(clock() - reaction_time) / CLOCKS_PER_SEC > level_time_limit[now_level - 1]) {
            MoveConsole(30, 15);
            printf("�ð� �ʰ�! ����!                              ");
            return;
        }
    }
}