#include "MOC.h"

#define MAX_ATTEMPTS 5

int now_level = 1;

void PrintAttempts(int attempts[], char results[][10], int attemptCount) {
    MoveConsole(22, 3);
    SetColor(7);
    for (int i = 0; i < attemptCount; i++) {
        MoveConsole(22, 4 + i);
        printf("%d -> %s", attempts[i], results[i]);
    }
}

void random_number() {
    int target, guess, attemptCount = 0;
    int attempts[MAX_ATTEMPTS] = { 0 };
    char results[MAX_ATTEMPTS][10];

    srand(time(NULL));
    if (now_level == 1) target = rand() % 20 + 1;
    else if (now_level == 2) target = rand() % 50 + 1;
    else if (now_level == 3) target = rand() % 70 + 1;

    while (attemptCount < MAX_ATTEMPTS) {
        MoveConsole(30, 12);
        SetColor(7);
        if (now_level == 1) printf("<1부터 20까지 중 숫자를 맞춰보세요>");
        else if (now_level == 2) printf("<1부터 50까지 중 숫자를 맞춰보세요>");
        else if (now_level == 3) printf("<1부터 70까지 중 숫자를 맞춰보세요>");

        MoveConsole(45, 13); // 이전 입력 위치
        printf("       ");       // 빈 칸 출력으로 덮어쓰기
        MoveConsole(45, 13); // 커서를 다시 입력 위치로 이동

        // 숫자 입력받기
        if (scanf("%d", &guess) != 1) {
            // 잘못된 입력 처리
            while (getchar() != '\n'); // 입력 버퍼 비우기
            MoveConsole(32, 18);
            SetColor(4); // 빨간색
            printf("유효하지 않은 입력입니다. 숫자를 입력하세요.");
            continue; // 다시 입력받기
        }

        // 입력값 기록
        attempts[attemptCount] = guess;

        // 결과 처리
        if (guess < target) {
            sprintf(results[attemptCount], "UP!");
        }
        else if (guess > target) {
            sprintf(results[attemptCount], "DOWN!");
        }
        else {
            MoveConsole(32, 18);
            SetColor(10); // 초록색
            printf("축하드립니다! 숫자는 %d입니다.", target);
            return; // 게임 성공
        }

        attemptCount++;

        // 이전 시도 출력
        PrintAttempts(attempts, results, attemptCount);

        // 남은 기회 표시
        MoveConsole(22, 2);
        SetColor(12); // 빨간색
        printf("남은 횟수: %d", MAX_ATTEMPTS - attemptCount);
    }

    // 실패 메시지
    MoveConsole(32, 18);
    SetColor(4); // 빨간색
    printf("실패하셨습니다! 숫자는 %d입니다.", target);
}
