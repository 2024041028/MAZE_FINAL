#include "MOC.h"

extern int h; // 목숨 (다른 파일에서 선언된 전역 변수)
extern char user_name[20];

// 사용자 입력 함수 (시간 제한 포함, 입력값 노란색 표시)
int InputWithTimeoutAscending(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 카운트다운 오른쪽 상단에 출력
        MoveConsole(55, 2);
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') {
                input[index] = '\0';
                return 1; // 입력 성공
            }
            else if (ch == '\b' && index > 0) {
                index--;
                MoveConsole(23 + index, 14);
                printf(" ");
                MoveConsole(23 + index, 14);
            }
            else if (index < max_length - 1) {
                input[index++] = ch;
                SetColor(14);
                MoveConsole(23 + index - 1, 14);
                printf("%c", ch);
                SetColor(7);
            }
        }

        elapsed_time = clock() - start_time;
    }

    input[index] = '\0';
    return 0; // 시간 초과
}

// 오름차순 정렬 게임 (수정된 틀 적용)
int PlayAscendingGame(int level)

{ 
   

    int numbers[10], user_input[10];
    char input[50];
    int count = 5, timeout = 30;

    // 난이도 설정
    if (level == 1) { count = 5; timeout = 30; }
    else if (level == 2) { count = 6; timeout = 30; }
    else if (level == 3) { count = 10; timeout = 40; }

    srand(time(NULL));



    // 사용자 ID 및 목숨 출력
    MoveConsole(23, 2);
    printf("ID : %s", user_name);
    MoveConsole(23, 3);
    printf("목숨 : ");
    SetColor(4);
    for (int i = 0; i < h; i++) printf("♥");
    for (int i = h; i < 3; i++) printf("♡");
    SetColor(7);

    // 게임 안내 출력
    MoveConsole(23, 5);
    printf("오름차순 정렬 게임");
    MoveConsole(23, 6);
    printf("================");
    MoveConsole(23, 8);
    printf("다음 숫자를 오름차순으로 정렬하세요:");
    MoveConsole(23, 9);
    for (int i = 0; i < count; i++) {
        numbers[i] = rand() % 100;
        printf("%d ", numbers[i]);
    }

    // 사용자 입력 요청
    MoveConsole(23, 11);
    printf("%d초 안에 정렬된 숫자를 입력하세요:", timeout);
    MoveConsole(23, 14);
    if (!InputWithTimeoutAscending(input, sizeof(input), timeout)) {
        MoveConsole(23, 16);
        SetColor(14);
        printf("시간 초과! 게임 실패!");
        SetColor(7);
        return 0;
    }

    // 입력된 숫자 파싱
    char* token = strtok(input, " ");
    for (int i = 0; i < count; i++) {
        if (!token || sscanf(token, "%d", &user_input[i]) != 1) {
            MoveConsole(23, 16);
            SetColor(14);
            printf("입력 오류! 실패!");
            SetColor(7);
            return;
        }
        token = strtok(NULL, " ");
    }

    // 정답 확인
    for (int i = 0; i < count - 1; i++) {
        if (user_input[i] > user_input[i + 1]) {
            MoveConsole(23, 16);
            SetColor(14);
            printf("오답! 실패!");
            SetColor(7);
            return 0;
        }
    }

    MoveConsole(23, 16);
    SetColor(14);
    printf("정답! 성공했습니다!");
    SetColor(7);
    return 1;
}
