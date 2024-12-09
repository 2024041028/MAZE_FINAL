#include "MOC.h"

// 사용자 입력 함수 (비동기 입력 및 실시간 카운트다운)
int InputWithcnt(char* input, int max_length, int timeout) {
    int start_time = clock(); // 시작 시간
    int elapsed_time = 0;
    int index = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) { // 제한 시간 내 반복
        // 카운트다운 오른쪽 상단에 출력
        MoveConsole(65, 1);
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // 키 입력 감지
            char ch = _getch(); // 키 입력을 읽음
            if (ch == '\r') { // Enter 키 입력 시 종료
                input[index] = '\0'; // 입력 종료
                return 1; // 성공적으로 입력받음
            }
            else if (ch == '\b') { // Backspace 키 처리
                if (index > 0) {
                    index--;
                    MoveConsole(23 + index, 12); // 출력 문장과 동일한 x값에서 입력
                    printf(" ");
                    MoveConsole(23 + index, 12);
                }
            }
            else if (index < max_length - 1) { // 추가 입력 가능 시
                input[index++] = ch; // 입력 버퍼에 문자 추가
                MoveConsole(23 + index - 1, 12); // 출력 문장과 동일한 x값에서 입력
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time; // 경과 시간 계산
        Sleep(50); // 짧은 대기 시간으로 CPU 사용률 감소
    }

    input[index] = '\0'; // 입력 종료
    return 0; // 시간 초과
}

// 오름차순 정렬 게임 (난이도 포함)
void PlayAscendingGame(int level) {
    int numbers[10], user_input[10];
    char input[50];
    int count = 5, timeout = 30;

    // 난이도 설정
    if (level == 1) { count = 5; timeout = 30; }
    else if (level == 2) { count = 6; timeout = 30; }
    else if (level == 3) { count = 10; timeout = 40; }

    srand(time(NULL));

    CreateOutFrame();

    // 숫자 출력
    MoveConsole(23, 2);
    printf("오름차순 정렬 게임");
    MoveConsole(23, 3);
    printf("================");
    MoveConsole(23, 5);
    printf("다음 숫자를 오름차순으로 정렬하세요:");
    MoveConsole(23, 6);
    for (int i = 0; i < count; i++) {
        numbers[i] = rand() % 100;
        printf("%d ", numbers[i]);
    }

    // 사용자 입력
    MoveConsole(23, 8);
    printf("%d초 안에 정렬된 숫자를 입력하세요:", timeout);

    if (!InputWithcnt(input, sizeof(input), timeout)) {
        MoveConsole(23, 10);
        printf("시간 초과! 게임 실패!");
        return;
    }

    // 입력된 숫자 파싱
    char* token = strtok(input, " ");
    for (int i = 0; i < count; i++) {
        if (!token || sscanf(token, "%d", &user_input[i]) != 1) {
            MoveConsole(23, 12);
            printf("입력 오류! 실패!");
            return;
        }
        token = strtok(NULL, " ");
    }

    // 정답 확인
    for (int i = 0; i < count - 1; i++) {
        if (user_input[i] > user_input[i + 1]) {
            MoveConsole(23, 12);
            printf("오답! 실패!");
            return;
        }
    }

    MoveConsole(23, 12);
    printf("정답! 성공했습니다!");
}
