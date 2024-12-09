#include "MOC.h"
#include <stdbool.h>

extern int h; // ��� (�ٸ� ���Ͽ��� ����� ���� ����)
extern char user_name[20]; // ����� �̸� (�ٸ� ���Ͽ��� ����� ���� ����)
extern int skip; // ��ŵ�� (�ٸ� ���Ͽ��� ����� ���� ����)

// �̴ϰ��� �� ���� �� ���� ȭ��
bool DisplayMiniGameRule(const char* game_rule) {
    int flag = 0; // 0: GO, 1: SKIP

    // ȭ�� �ʱ�ȭ �� Ʋ ����
    CreateOutFrame();

    // ����� ID �� ��� ���
    MoveConsole(23, 2);
    printf("ID : %s", user_name);
    MoveConsole(23, 3);
    printf("��� : ");
    SetColor(4);
    for (int i = 0; i < h; i++) printf("\u2665"); // �� ���
    for (int i = h; i < 3; i++) printf("\u2661"); // �� ���
    SetColor(7);

    // ���� �� ����
    MoveConsole(23, 5);
    printf("���� ���:");
    PrintWrappedText(game_rule, 23, 6, 40); // �ٹٲ� ó���� ���� ����

    // GO�� SKIP ���� ȭ��
    while (true) {
        if (flag == 0) {
            MoveConsole(23, 12);
            SetColor(7);
            printf("�� GO");
            MoveConsole(23, 13);
            SetColor(skip > 0 ? 8 : 4); // ��ŵ�� ������ SKIP ��Ȱ��ȭ ����
            printf("  SKIP");
        }
        else {
            MoveConsole(23, 12);
            SetColor(8);
            printf("  GO");
            MoveConsole(23, 13);
            SetColor(skip > 0 ? 7 : 4);
            printf("�� SKIP");
        }
        SetColor(7);

        // ����Ű �� ����Ű �Է� ó��
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            if (flag == 0 && skip > 0) {
                flag = 1;
                Sleep(150);
            }
        }
        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (flag == 1) {
                flag = 0;
                Sleep(150);
            }
        }
        else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            RemoveGarbageChar();
            if (flag == 0) {
                // GO ���� �� true ��ȯ (���� ����)
                return true;
            }
            else if (flag == 1 && skip > 0) {
                // SKIP ���� �� ��ŵ�� ���� �� false ��ȯ
                skip--;
                return false;
            }
        }
        Sleep(50); // CPU ������ ����
    }
}

// �ٳѱ� ó���� �ؽ�Ʈ ��� �Լ�
void PrintWrappedText2(const char* text, int x, int y, int width) {
    int len = strlen(text);
    int line_start = 0;

    while (line_start < len) {
        MoveConsole(x, y++);
        for (int i = 0; i < width && (line_start + i) < len; i++) {
            printf("%c", text[line_start + i]);
        }
        line_start += width;
    }
}
