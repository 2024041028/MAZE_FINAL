#include "MOC.h"

#define MAX_ATTEMPTS 3
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
    target = rand() % 10 + 1;

    while (attemptCount < MAX_ATTEMPTS) {
        MoveConsole(30, 12);
        SetColor(7);
        printf("<1부터 10까지 중 숫자를 맞춰보세요>");
        MoveConsole(45, 13); // 이전 입력 위치
        printf("       ");       // 빈 칸 출력으로 덮어쓰기
        MoveConsole(45, 13); // 커서를 다시 입력 위치로 이동
        scanf("%d", &guess);

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
            printf("축하드립니다 숫자는 %d입니다.", target);
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
    printf("실패하셨습니다 숫자는 %d입니다.", target);
}


//
//int main() {
//    // 테두리 생성
//    system("cls");
//    CreateOutFrame();
//
//    // 게임 시작
//    random_number();
//
//    // 종료 메시지
//    MoveConsole(32, 19);
//    SetColor(7); // 기본 색상
//    printf("나가려면 아무키나 눌러주세요.");
//    getchar(); // 프로그램 종료 대기
//    getchar(); // 추가 대기
//    return 0;
//}
