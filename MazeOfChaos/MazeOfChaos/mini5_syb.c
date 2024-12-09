#include "MOC.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


void PlayReflexGame() {
    int now_level = 1; // 초기 레벨
    int is_now_displayed = 0;       // '지금' 출력 여부
    int is_confusing_displayed = 0; // 혼동 단어 출력 여부
    int is_number_displayed = 0;    // 숫자 출력 여부
    char input;
    int reaction_time = 0;
    const char* confusing_words[] = { "자금", "ㅈ금", "지국", "자극", "ㅈ긍" }; // 혼동 단어 배열
    int num_confusing_words = sizeof(confusing_words) / sizeof(confusing_words[0]);

    // 레벨별 시간 제한 설정
    float level_time_limit[] = { 1.0, 0.7, 0.5 };
    if (now_level < 1 || now_level > 3) now_level = 1; // 레벨 범위 제한

    srand(time(NULL));

    const int display_x = 45; // 출력 위치 x 좌표
    const int display_y = 12; // 출력 위치 y 좌표

    // 안내 메시지 출력
    MoveConsole(27, 5);
    printf("'지금'이라는 글자가 나오면 'p'를 누르세요!");

    // 제한시간 안내 메시지
    MoveConsole(36, 6);
    printf("%d단계: 제한 시간 %.1f초", now_level, level_time_limit[now_level - 1]);

    Sleep(2000); // 사용자에게 준비 시간 제공

    while (1) {
        // 초기화
        MoveConsole(display_x, display_y);
        is_now_displayed = 0;
        is_confusing_displayed = 0;
        is_number_displayed = 0;

        if (rand() % 10 == 0) { // 10% 확률로 특정 단어 출력
            if (rand() % 2 == 0) {
                printf("지금  ");
                is_now_displayed = 1; // '지금' 표시됨
                reaction_time = clock(); // 반응 시간 기록 시작
                break;
            }
            else {
                int idx = rand() % num_confusing_words;
                printf("%s  ", confusing_words[idx]);
                is_confusing_displayed = 1; // 혼동 단어 표시됨
                Sleep(300); // 혼동 단어 표시 후 다음 루프로
                continue;
            }
        }
        else {
            int random_number = rand() % 100;
            printf("%02d  ", random_number); // 숫자 출력
            is_number_displayed = 1; // 숫자 출력 상태 설정
            Sleep(300); // 숫자 표시 후 다음 루프
        }
    }

    // 반응 시간 측정 및 사용자 입력 대기
    while (1) {
        if (_kbhit()) { // 키 입력 감지
            input = _getch();

            // 반응 성공 처리
            if (is_now_displayed && input == 'p') {
                reaction_time = clock() - reaction_time;
                MoveConsole(30, 15);
                printf("성공! 반응 시간: %.2f초  ", (float)reaction_time / CLOCKS_PER_SEC);
                return;
            }

            // 잘못된 반응 처리
            MoveConsole(30, 15);
            if (input == 'p') {
                if (is_confusing_displayed) {
                    printf("실패! 혼동 단어에서 'p'를 눌렀습니다.          ");
                }
                else if (is_number_displayed) {
                    printf("실패! 숫자에서 'p'를 눌렀습니다.              ");
                }
                else {
                    printf("실패! 잘못된 상태에서 'p'를 눌렀습니다.      ");
                }
            }
            else {
                printf("실패! 'p'를 눌러야 합니다.                     ");
            }
            return;
        }

        // 반응 시간 제한 (레벨에 따른 시간)
        if ((float)(clock() - reaction_time) / CLOCKS_PER_SEC > level_time_limit[now_level - 1]) {
            MoveConsole(30, 15);
            printf("시간 초과! 실패!                              ");
            return;
        }
    }
}