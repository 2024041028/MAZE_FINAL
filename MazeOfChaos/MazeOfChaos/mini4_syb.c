#include "MOC.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h> // Sleep 함수

#define MAX_LEVEL 3 // 최대 난이도
#define TIME_DISPLAY 3 // 알파벳 표시 시간 (초)

// 난이도에 따른 알파벳 개수 설정
int GetAlphabetCount(int level) {
    return 3 + (level - 1) * 2; // 난이도 1: 3개, 난이도 2: 5개, 난이도 3: 7개
}

// 랜덤 알파벳 생성 함수
void GenerateRandomAlphabets(char* sequence, int count) {
    for (int i = 0; i < count; i++) {
        sequence[i] = 'A' + rand() % 26; // A부터 Z까지 랜덤 알파벳 생성
    }
    sequence[count] = '\0'; // 문자열 종료 문자 추가
}

// 사용자 입력 받기 함수
void GetUserInput(char* input, int max_length) {
    int index = 0;
    char ch;

    while (1) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == '\r') { // Enter 키로 입력 종료
                input[index] = '\0';
                break;
            }
            else if (ch == '\b') { // Backspace 처리
                if (index > 0) {
                    index--;
                    MoveConsole(50 + index, 16);
                    printf(" ");
                    MoveConsole(50 + index, 16);
                }
            }
            else if (index < max_length - 1) { // 입력 가능 여부 확인
                input[index++] = ch;
                MoveConsole(50 + index - 1, 16);
                printf("%c", ch);
            }
        }
    }
}

// 기억력 게임 함수
void PlayMemoryGame() {
    system("cls");
    CreateOutFrame(); // 게임 틀 생성

    srand(time(NULL)); // 랜덤 시드 설정

    int level = 1;
    char sequence[20], user_input[20];

    // 난이도 루프
    while (level <= MAX_LEVEL) {
        int alphabet_count = GetAlphabetCount(level); // 현재 난이도에 따른 알파벳 개수

        // 랜덤 알파벳 생성
        GenerateRandomAlphabets(sequence, alphabet_count);

        // 화면에 알파벳 출력
        system("cls");
        CreateOutFrame();
        MoveConsole(36, 8);
        SetColor(14); // 노란색
        printf("Level %d", level);
        MoveConsole(36, 10);
        SetColor(11); // 파란색
        printf("기억하세요: %s", sequence);

        Sleep(TIME_DISPLAY * 1000); // 알파벳 표시 시간 동안 대기

        // 알파벳 숨기기
        system("cls");
        CreateOutFrame();
        MoveConsole(36, 10);
        SetColor(14); // 노란색
        printf("알파벳을 입력하세요:");

        // 사용자 입력 받기
        MoveConsole(50, 16); // 입력 위치 조정
        SetColor(7); // 기본 색상
        GetUserInput(user_input, sizeof(user_input));

        // 입력 비교
        if (strcmp(sequence, user_input) == 0) {
            // 정답인 경우
            MoveConsole(36, 12);
            SetColor(10); // 초록색
            printf("정답입니다! 다음 레벨로 넘어갑니다!");
            level++;
            Sleep(2000); // 2초 대기 후 다음 레벨로
        }
        else {
            // 오답인 경우
            MoveConsole(36, 12);
            SetColor(4); // 빨간색
            printf("오답입니다! 정답은: %s", sequence);
            MoveConsole(36, 14);
            printf("Press any key to return to the main menu...");
            getchar();
            return;
        }
    }

    // 게임 클리어
    system("cls");
    CreateOutFrame();
    MoveConsole(36, 10);
    SetColor(10); // 초록색
    printf("축하합니다! 모든 레벨을 클리어했습니다!");
    MoveConsole(36, 12);
    SetColor(7); // 기본 색상 복원
    printf("Press any key to return to the main menu...");
    getchar();
}
