#include "MOC.h"

// 랜덤 색상 생성 함수
int GetRandomColor() {
    return rand() % 15 + 1; // 1~15 사이의 색상 코드 반환
}

void PlayReflexGame() {
    int now_level = 1; // 초기 레벨
    int is_now_displayed = 0; // '지금' 출력 여부
    char input;
    int reaction_start_time = 0;
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
    SetColor(7);
    printf("'지금'이라는 글자가 나오면 'p'를 누르세요!");

    // 제한시간 안내 메시지
    MoveConsole(36, 6);
    SetColor(7);
    printf("%d단계: 제한 시간 %.1f초", now_level, level_time_limit[now_level - 1]);

    Sleep(2000); // 사용자에게 준비 시간 제공

    while (1) {
        // 플래그 초기화
        is_now_displayed = 0;

        // 화면에 출력
        MoveConsole(display_x, display_y);
        if (rand() % 10 == 0) { // 10% 확률로 "지금" 또는 혼동 단어 출력
            if (rand() % 2 == 0) {
                SetColor(GetRandomColor()); // 랜덤 색상 설정
                printf("지금  ");
                is_now_displayed = 1;
                reaction_start_time = clock(); // 반응 시간 기록 시작
            }
            else {
                int idx = rand() % num_confusing_words;
                SetColor(GetRandomColor()); // 랜덤 색상 설정
                printf("%s  ", confusing_words[idx]);
                Sleep(300); // 혼동 단어 표시 후 다음 루프로
                continue;
            }
        }
        else { // 숫자 출력
            int random_number = rand() % 100;
            SetColor(GetRandomColor()); // 랜덤 색상 설정
            printf("%02d  ", random_number);
            Sleep(300);
            // 사용자가 숫자가 출력될 때 'p'를 누르면 즉시 종료
            if (_kbhit()) { // 키 입력 감지
                input = _getch();
                if (input == 'p') {
                    MoveConsole(30, 15);
                    SetColor(4);
                    printf("실패! 잘못된 상황에서 'p'를 눌렀습니다. ");
                    return; // 실패 시 게임 종료
                }
            }
            continue;
        }

        // "지금"이 출력된 후 사용자 반응 대기
        while (1) {
            if (_kbhit()) { // 키 입력 감지
                input = _getch();

                if (is_now_displayed && input == 'p') { // '지금'에 올바른 반응
                    int reaction_time = clock() - reaction_start_time;
                    MoveConsole(37, 15);
                    SetColor(10);
                    printf("성공! 반응 시간: %.2f초  ", (float)reaction_time / CLOCKS_PER_SEC);
                    return;
                }

                // '지금'이 출력되지 않은 상태에서 'p' 입력 처리
                if (input == 'p') {
                    MoveConsole(30, 15);
                    SetColor(4);
                    printf("실패! 잘못된 상황에서 'p'를 눌렀습니다.");
                    return; // 실패 시 게임 종료
                }
            }

            // "지금" 상태에서 시간 초과 처리
            if (is_now_displayed && (float)(clock() - reaction_start_time) / CLOCKS_PER_SEC > level_time_limit[now_level - 1]) {
                MoveConsole(39, 15);
                SetColor(4);
                printf("시간 초과! 실패!");
                return; // 시간 초과 시 게임 종료
            }
        }
    }
}
