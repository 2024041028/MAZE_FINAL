#include "MOC.h"
#include <stdbool.h>

extern int h; // 목숨 (다른 파일에서 선언된 전역 변수)
extern char user_name[20]; // 사용자 이름 (다른 파일에서 선언된 전역 변수)
extern int skip; // 스킵권 (다른 파일에서 선언된 전역 변수)

// 미니게임 룰 설명 및 선택 화면
bool DisplayMiniGameRule(const char* game_rule) {
    int flag = 0; // 0: GO, 1: SKIP

    // 화면 초기화 및 틀 생성
    CreateOutFrame();

    // 사용자 ID 및 목숨 출력
    MoveConsole(23, 2);
    printf("ID : %s", user_name);
    MoveConsole(23, 3);
    printf("목숨 : ");
    SetColor(4);
    for (int i = 0; i < h; i++) printf("\u2665"); // ♥ 출력
    for (int i = h; i < 3; i++) printf("\u2661"); // ♡ 출력
    SetColor(7);

    // 게임 룰 설명
    MoveConsole(23, 5);
    printf("게임 방법:");
    PrintWrappedText(game_rule, 23, 6, 40); // 줄바꿈 처리된 게임 설명

    // GO와 SKIP 선택 화면
    while (true) {
        if (flag == 0) {
            MoveConsole(23, 12);
            SetColor(7);
            printf("▶ GO");
            MoveConsole(23, 13);
            SetColor(skip > 0 ? 8 : 4); // 스킵권 없으면 SKIP 비활성화 색상
            printf("  SKIP");
        }
        else {
            MoveConsole(23, 12);
            SetColor(8);
            printf("  GO");
            MoveConsole(23, 13);
            SetColor(skip > 0 ? 7 : 4);
            printf("▶ SKIP");
        }
        SetColor(7);

        // 방향키 및 엔터키 입력 처리
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
                // GO 선택 시 true 반환 (게임 시작)
                return true;
            }
            else if (flag == 1 && skip > 0) {
                // SKIP 선택 시 스킵권 차감 및 false 반환
                skip--;
                return false;
            }
        }
        Sleep(50); // CPU 과부하 방지
    }
}

// 줄넘김 처리된 텍스트 출력 함수
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
