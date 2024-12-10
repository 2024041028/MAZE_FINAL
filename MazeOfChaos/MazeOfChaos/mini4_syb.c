#include "MOC.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX_QUESTIONS 5 // 총 문제 수
#define TIME_DISPLAY 3  // 문제 표시 시간 (초)

// 초기 레벨 설정
now_level = 1; // 초기 레벨 1

// 난이도에 따른 문자열 길이 반환
int GetStringLengthForLevel(int level) {
    return 3 + level; // 1레벨: 4글자, 2레벨: 5글자, 3레벨: 6글자
}

// 랜덤 문자열 생성 함수 (숫자와 영어 알파벳 포함)
void GenerateRandomString(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        if (rand() % 2 == 0) { // 50% 확률로 숫자 또는 알파벳 생성
            sequence[i] = '0' + rand() % 10; // 0~9 숫자
        }
        else {
            sequence[i] = 'A' + rand() % 26; // A~Z 알파벳
        }
    }
    sequence[length] = '\0'; // 문자열 종료
}

// 사용자 입력 받기 함수
void GetUserInput(char* input, int max_length, int start_x, int start_y) {
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
                    MoveConsole(start_x + index, start_y);
                    printf(" ");
                    MoveConsole(start_x + index, start_y);
                }
            }
            else if (index < max_length - 1) { // 입력 가능 여부 확인
                input[index++] = ch;
                MoveConsole(start_x + index - 1, start_y);
                printf("%c", ch);
            }
        }
    }
}

// 기억력 게임 함수
void PlayMemoryGame() {
    system("cls");
    CreateOutFrame(now_color_num); // 게임 틀 생성
    srand(time(NULL)); // 랜덤 시드 설정

    int correct_count = 0; // 정답 횟수
    char sequence[20], user_input[20];

    // 현재 난이도 게임 진행
    for (int question = 1; question <= MAX_QUESTIONS; question++) {
        int str_length = GetStringLengthForLevel(now_level); // 현재 레벨에 따른 문자열 길이

        // 랜덤 문자열 생성
        GenerateRandomString(sequence, str_length);

        // 화면에 문자열 출력
        system("cls");
        CreateOutFrame(now_color_num);
        MoveConsole(38,9);
        SetColor(14); // 노란색
        printf("Level %d - 문제 %d", now_level, question);
        MoveConsole(38, 11);
        SetColor(11); // 파란색
        printf("기억하세요: %s", sequence);

        Sleep(TIME_DISPLAY * 1000); // 문자열 표시 시간 동안 대기

        // 문자열 숨기기
        system("cls");
        CreateOutFrame(now_color_num);
        MoveConsole(35, 10);
        SetColor(14); // 노란색
        printf("문자열을 입력하세요: ");

        // 입력 필드 커서 위치 설정
        int input_start_x = 35 + strlen("문자열을 입력하세요: ");
        int input_start_y = 10;
        MoveConsole(input_start_x, input_start_y);
        SetColor(7); // 기본 색상
        GetUserInput(user_input, sizeof(user_input), input_start_x, input_start_y);

        // 입력 비교
        if (strcmp(sequence, user_input) == 0) {
            // 정답인 경우
            correct_count++;
            MoveConsole(42, 12);
            SetColor(10); // 초록색
            printf("정답입니다!");
        }
        else {
            // 오답인 경우
            MoveConsole(35, 12);
            SetColor(4); // 빨간색
            printf("오답입니다! 정답은: %s", sequence);
        }

        MoveConsole(36, 14);
        SetColor(7); // 기본 색상 복원
        printf("현재 정답 개수: %d / %d", correct_count, question);

        Sleep(2000); // 2초 대기
    }

    // 결과 출력
    system("cls");
    CreateOutFrame(now_color_num);
    MoveConsole(24, 10);

    if (correct_count >= 3) {
        SetColor(10); // 초록색
        printf("축하합니다! Level %d에서 %d개의 문제를 맞췄습니다!", now_level, correct_count);
    }
    else {
        SetColor(4); // 빨간색
        MoveConsole(32, 10);
        printf("Level %d 실패! 정답 개수: %d / %d", now_level, correct_count, MAX_QUESTIONS);
    }

    MoveConsole(26, 12);
    SetColor(7); // 기본 색상 복원
    printf("Press any key to return to the main menu...");
    getchar();
}
