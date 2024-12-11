#include "MOC.h"

void RemoveGarbageChar() {
    char newline[100];
    char ch;

    while (_kbhit()) { // 입력 버퍼에 남아 있는 키 처리
        ch = _getch();

        if (ch == -32 || ch == 0) { // 방향키 및 특수키 감지
            ch = _getch(); // 두 번째 호출로 실제 키 코드 가져오기
            // 방향키는 무시
            if (ch == 72 || ch == 80 || ch == 75 || ch == 77) {
                continue; // 방향키일 경우 아무 작업도 하지 않고 루프 계속
            }
        }
        else if (ch == '\r') { // 엔터키
            continue; // 엔터키도 무시
        }
        else { // 방향키나 엔터키가 아닌 입력이 발생했을 때
            while (_kbhit() != 0)
                ch = _getch();
        }
    }
}