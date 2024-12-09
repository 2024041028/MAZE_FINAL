#include "MOC.h"

// 사용자 입력 함수 (시간 제한 포함)
int InputWithcnt2(char* input, int max_length, int timeout) {
    int start_time = clock(); // 시작 시간
    int elapsed_time = 0;
    int index = 0;

    MoveConsole(23, 12);

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 카운트다운 오른쪽 상단에 출력
        MoveConsole(65, 1);
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') { // Enter 키 입력 시 종료
                input[index] = '\0';
                return 1; // 입력 성공
            }
            else if (ch == '\b' && index > 0) { // Backspace 처리
                index--;
                MoveConsole(23 + index, 12);
                printf(" ");
                MoveConsole(23 + index, 12);
            }
            else if (index < max_length - 1) { // 입력 가능
                input[index++] = ch;
                MoveConsole(23 + index - 1, 12);
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time;
    }

    input[index] = '\0'; // 입력 종료
    return 0; // 시간 초과
}

// 화살표 게임 (난이도 포함)
void PlayArrowGame(int level) {
    char* arrows[] = { "↑", "↓", "←", "→" };
    int dx[] = { 0, 0, -1, 1 }; // x 변화값
    int dy[] = { 1, -1, 0, 0 }; // y 변화값

    int x = 0, y = 0; // 시작 좌표
    char user_input[50];
    int user_x, user_y;

    // 난이도에 따른 화살표 개수와 제한 시간 설정
    int arrow_count = 4; // 기본 화살표 개수
    int timeout = 30;    // 기본 제한 시간

    if (level == 1) {
        arrow_count = 4;
        timeout = 30;
    }
    else if (level == 2) {
        arrow_count = 5;
        timeout = 20;
    }
    else if (level == 3) {
        arrow_count = 7;
        timeout = 15;
    }

    // 난수 초기화
    srand(time(NULL));

    // 틀 출력
    CreateOutFrame();

    // 게임 안내 출력
    MoveConsole(23, 2);
    printf("화살표 게임");
    MoveConsole(23, 3);
    printf("================");

    // 화살표 출력 및 좌표 계산
    MoveConsole(23, 5);
    printf("다음 화살표를 보고 최종 좌표를 추측하세요:");
    MoveConsole(23, 6);

    for (int i = 0; i < arrow_count; i++) {
        int arrow_index = rand() % 4; // 랜덤 화살표 선택
        printf("%s ", arrows[arrow_index]); // 화살표 출력
        x += dx[arrow_index]; // x 좌표 갱신
        y += dy[arrow_index]; // y 좌표 갱신
    }

    // 사용자 입력 요청
    MoveConsole(23, 8);
    printf("%d초 안에 최종 좌표를 입력하세요 (예: (x, y)):", timeout);

    if (!InputWithcnt2(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 14);
        printf("시간 초과! 게임 실패!");
        return;
    }

    // 입력된 좌표를 숫자로 변환
    if (sscanf(user_input, "(%d, %d)", &user_x, &user_y) != 2) {
        MoveConsole(23, 14);
        printf("입력 형식이 잘못되었습니다. (예: (2, 3))");
        return;
    }

    // 정답 확인
    if (user_x == x && user_y == y) {
        MoveConsole(23, 14);
        printf("정답! 성공했습니다.");
    }
    else {
        MoveConsole(23, 14);
        printf("오답! 정답은 (%d, %d)입니다.", x, y);
    }
}
