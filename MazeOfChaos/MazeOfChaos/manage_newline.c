#include "MOC.h"

void RemoveGarbageChar() {
    char newline[100];
    char ch;
    while (_kbhit()) { // �Է� ���ۿ� ���� �ִ� Ű ó��
        ch = _getch();
        if(ch == -32 || ch == 0) { // ����Ű �� Ư��Ű ����
            ch = _getch(); // �� ��° ȣ��� ����Ű�� ���� Ű �ڵ� ��������
            continue;      // ����Ű ����
        }
        else if (ch == '\r') { // ����Ű ����
            continue;
        }
        else { // �Ϲ� �Է�
            while (_kbhit()) {
                ch = _getch(); // �Է� ���� ����
            }
        }
    }
}