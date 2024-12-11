#include "MOC.h"

void RemoveGarbageChar() {
    char newline[100];
    char ch;

    while (_kbhit()) { // 입력 버퍼에 남아 있는 키 처리
        ch = _getch();
        if (ch == '\r') {
            continue;
        }
        else { // 방향키, 쓸모없는 키
            while (_kbhit()) {
                ch = _getch();
                if (_kbhit() != 0) {
                    break;
                }
            }
        }
    }
}