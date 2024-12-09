#include "MOC.h"

// 사용자 상태 변수
extern int h; // 목숨 (다른 파일에서 선언된 전역 변수)
extern char user_name[20]; // 사용자 이름 (다른 파일에서 선언된 전역 변수)


// 사용자 이름과 목숨 출력 함수
void DisplayUserInfo() {
    MoveConsole(23, 2); // 사용자 이름 출력 위치
    printf("아이디: %s", user_name);

    MoveConsole(23, 3); // 목숨 출력 위치
    printf("목숨: ");
    SetColor(4); // 빨간색 하트
    for (int i = 0; i < h; i++) {
        printf("♥");
    }
    SetColor(7); // 기본색
    for (int i = h; i < 3; i++) {
        printf("♡");
    }
}

// 사용자 입력 함수 (비동기 입력 및 실시간 카운트다운)
int InputWithcnt3(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        MoveConsole(65, 2); // 카운트다운 위치 (사각형 틀 안)
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') {
                input[index] = '\0';
                return 1;
            }
            else if (ch == '\b' && index > 0) {
                index--;
                MoveConsole(23 + index, 12);
                printf(" ");
                MoveConsole(23 + index, 12);
            }
            else if (index < max_length - 1) {
                input[index++] = ch;
                MoveConsole(23 + index - 1, 12);
                printf("%c", ch);
            }
        }
        elapsed_time = clock() - start_time;
    }

    input[index] = '\0';
    return 0;
}

// 화살표 게임
void PlayArrowGame(int level) {
    char* arrows[] = { "↑", "↓", "←", "→" };
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { 1, -1, 0, 0 };
    int arrow_count = 4, timeout = 30;
    int x = 0, y = 0;
    char user_input[50];
    int user_x, user_y;

    // 난이도 설정
    if (level == 1) { arrow_count = 4; timeout = 30; }
    else if (level == 2) { arrow_count = 5; timeout = 20; }
    else if (level == 3) { arrow_count = 7; timeout = 15; }

    srand(time(NULL));

    CreateOutFrame(); // 사각형 틀 생성
    DisplayUserInfo(); // 사용자 정보 출력

    // 화살표 출력
    MoveConsole(23, 5);
    printf("화살표 게임");
    MoveConsole(23, 6);
    printf("================");
    MoveConsole(23, 8);
    printf("다음 화살표를 보고 최종 좌표를 추측하세요:");
    MoveConsole(23, 9);

    for (int i = 0; i < arrow_count; i++) {
        int arrow_index = rand() % 4;
        printf("%s ", arrows[arrow_index]);
        x += dx[arrow_index];
        y += dy[arrow_index];
    }

    MoveConsole(23, 11);
    printf("%d초 안에 최종 좌표를 입력하세요 (예: (x, y)):", timeout);

    if (!InputWithcnt3(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 13);
        printf("시간 초과! 실패!");
        return;
    }

    if (sscanf(user_input, "(%d, %d)", &user_x, &user_y) != 2) {
        MoveConsole(23, 13);
        printf("입력 형식이 잘못되었습니다!");
        return;
    }

    if (user_x == x && user_y == y) {
        MoveConsole(23, 13);
        printf("정답! 성공했습니다!");
    }
    else {
        MoveConsole(23, 13);
        printf("오답! 정답은 (%d, %d)입니다.", x, y);
    }
}