#include "MOC.h"
// 사용자 입력 함수 (비동기 입력 및 실시간 카운트다운)
int InputWithCountdown2(char* input, int max_length, int timeout) {
    int start_time = clock(); // 시작 시간
    int elapsed_time = 0;
    int index = 0;

    // 커서를 입력 위치로 이동
    MoveConsole(23, 12);

    while (elapsed_time < timeout * CLOCKS_PER_SEC) { // 제한 시간 내 반복
        // 카운트다운 오른쪽 상단에 출력
        MoveConsole(65, 1);
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // 키 입력 감지
            char ch = _getch(); // 키 입력을 읽음
            if (ch == '\r') { // Enter 키 입력 시 종료
                input[index] = '\0';
                return 1; // 성공적으로 입력받음
            }
            else if (ch == '\b') { // Backspace 키 처리
                if (index > 0) {
                    index--;
                    MoveConsole(23 + index, 12);
                    printf(" ");
                    MoveConsole(23 + index, 12);
                }
            }
            else if (index < max_length - 1) { // 추가 입력 가능 시
                input[index++] = ch; // 입력 버퍼에 문자 추가
                MoveConsole(23 + index - 1, 12);
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time;
    }

    input[index] = '\0'; // 입력 종료
    return 0; // 시간 초과
}

// 화살표 게임
void PlayArrowGame() {
    char* arrows[] = { "↑", "↓", "←", "→" };
    int dx[] = { 0, 0, -1, 1 }; // x 변화값
    int dy[] = { 1, -1, 0, 0 }; // y 변화값

    int x = 0, y = 0; // 시작 좌표
    char user_input[50];
    int user_x, user_y;

    // 난수 생성
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

    for (int i = 0; i < 5; i++) {
        int arrow_index = rand() % 4; // 랜덤 화살표 선택
        printf("%s ", arrows[arrow_index]); // 화살표 출력
        x += dx[arrow_index]; // x 좌표 갱신
        y += dy[arrow_index]; // y 좌표 갱신
    }

    // 사용자 입력 요청
    MoveConsole(23, 8);
    printf("30초 안에 최종 좌표를 입력하세요 (예: (x, y)):");

    if (!InputWithCountdown2(user_input, sizeof(user_input), 30)) {
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