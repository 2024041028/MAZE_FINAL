#include "MOC.h"

void RemoveGarbageChar() {
    char newline[100];
    char ch;
    while (_kbhit()) { // 입력 버퍼에 남아 있는 키 처리
        ch = _getch();
        if(ch == -32 || ch == 0) { // 방향키 및 특수키 감지
            ch = _getch(); // 두 번째 호출로 방향키의 실제 키 코드 가져오기
            continue;      // 방향키 무시
        }
        else if (ch == '\r') { // 엔터키 무시
            continue;
        }
        else { // 일반 입력
            while (_kbhit()) {
                ch = _getch(); // 입력 버퍼 비우기
            }
        }
    }
}