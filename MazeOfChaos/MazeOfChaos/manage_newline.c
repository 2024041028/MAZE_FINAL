#include "MOC.h"

void RemoveGarbageChar() {
    char newline[100];
    char ch;

    while (_kbhit()) { // �Է� ���ۿ� ���� �ִ� Ű ó��
        ch = _getch();
        if (ch == '\r') {
            continue;
        }
        else { // ����Ű, ������� Ű
            while (_kbhit()) {
                ch = _getch();
                if (_kbhit() != 0) {
                    break;
                }
            }
        }
    }
}