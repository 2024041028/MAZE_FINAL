#include "MOC.h"

void RemoveGarbageChar() {
    char newline[100];
    char ch;

    while (_kbhit()) { // �Է� ���ۿ� ���� �ִ� Ű ó��
        ch = _getch();

        if (ch == -32 || ch == 0) { // ����Ű �� Ư��Ű ����
            ch = _getch(); // �� ��° ȣ��� ���� Ű �ڵ� ��������
            // ����Ű�� ����
            if (ch == 72 || ch == 80 || ch == 75 || ch == 77) {
                continue; // ����Ű�� ��� �ƹ� �۾��� ���� �ʰ� ���� ���
            }
        }
        else if (ch == '\r') { // ����Ű
            continue; // ����Ű�� ����
        }
        else { // ����Ű�� ����Ű�� �ƴ� �Է��� �߻����� ��
            while (_kbhit() != 0)
                ch = _getch();
        }
    }
}