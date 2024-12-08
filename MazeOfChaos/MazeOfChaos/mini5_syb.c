#include "MOC.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define TIME_LIMIT 2.0 // '지금!' 반응 제한 시간 (초)
#define MAX_LEVEL 5    // 최대 난이도
#define BASE_SPEED 1000 // 숫자 표시 기본 속도 (밀리초)

// 혼란 문구 배열
const char* CONFUSING_TEXTS[] = { "지금!", "자금", "ㅈ금", "집음", "ㅣ금" };
const int NUM_CONFUSING_TEXTS = 5;

// 랜덤 문구 생성 함수
const char* GenerateRandomText(int is_now) {
    if (is_now) {
        return "지금!"; // 올바른 문구
    }
    else {
        return CONFUSING_TEXTS[rand() % NUM_CONFUSING_TEXTS]; // 혼란 문구
    }
}

// 반응 속도 측정 및 입력 받기
int GetReactionTime(double* reaction_time) {
    clock_t start_time = clock();
    clock_t elapsed_time;
    int success = 0;

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'p' || ch == 'P') {
                elapsed_time = clock() - start_time;
                *reaction_time = (double)elapsed_time / CLOCKS_PER_SEC;
                success = 1;
                break;
            }
        }

        elapsed_time = clock() - start_time;
        if ((double)elapsed_time / CLOCKS_PER_SEC > TIME_LIMIT) {
            *reaction_time = -1; // 시간 초과
            break;
        }
    }
    return success;
}

// 순발력 게임 함수
void PlayReactionGame() {
    system("cls");
    CreateOutFrame(); // 게임 틀 생성

    srand(time(NULL)); // 랜덤 시드 설정

    int level = 1;
    double reaction_time;

    // 난이도 루프
    while (level <= MAX_LEVEL) {
        int display_speed = BASE_SPEED - (level - 1) * 200; // 난이도에 따른 속도 증가
        int correct_trigger = rand() % 5 + 3; // '지금!' 출력 타이밍
        int rounds = 0;

        // 숫자와 문구 출력 루프
        while (rounds++ < correct_trigger) {
            system("cls");
            CreateOutFrame();

            // 숫자 출력
            int random_number = rand() % 1000;
            MoveConsole(36, 8);
            SetColor(11); // 파란색
            printf("%d", random_number);

            // 랜덤 문구 출력
            const char* random_text = GenerateRandomText(rounds == correct_trigger);
            MoveConsole(36, 10);
            SetColor(14); // 노란색
            printf("%s", random_text);

            if (rounds == correct_trigger) {
                // '지금!'일 때 반응 확인
                if (GetReactionTime(&reaction_time)) {
                    // 성공
                    MoveConsole(36, 12);
                    SetColor(10); // 초록색
                    printf("성공! 반응 시간: %.3f초", reaction_time);
                    Sleep(2000);
                    level++;
                    break;
                }
                else {
                    // 실패
                    MoveConsole(36, 12);
                    SetColor(4); // 빨간색
                    printf("실패! 시간 초과!");
                    MoveConsole(36, 14);
                    printf("Press any key to return to the main menu...");
                    getchar();
                    return;
                }
            }

            Sleep(display_speed); // 다음 숫자 출력 전 대기
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
