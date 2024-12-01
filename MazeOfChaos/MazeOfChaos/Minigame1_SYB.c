#include "MOC.h"

#define MAX_ATTEMPTS 5
void PrintAttempts(int attempts[], char results[][10], int attemptCount) {
    MoveConsole(22, 3);
    SetColor(13);
    printf("남은 기회:");
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
    target = rand() % 100 + 1;

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
            MoveConsole(25, 14);
            SetColor(10); // 초록색
            printf("Congratulations! The number was %d.          ", target);
            return; // 게임 성공
        }

        attemptCount++;

        // 이전 시도 출력
        PrintAttempts(attempts, results, attemptCount);

        // 남은 기회 표시
        MoveConsole(25, 20);
        SetColor(12); // 빨간색
        printf("Remaining Attempts: %d", MAX_ATTEMPTS - attemptCount);
    }

    // 실패 메시지
    MoveConsole(25, 22);
    SetColor(4); // 빨간색
    printf("Failed! The number was %d.                        ", target);
}

<<<<<<< HEAD


int main() {
    // 테두리 생성
    system("cls");
    CreateOutFrame();

    // 게임 시작
    random_number();

    // 종료 메시지
    MoveConsole(25, 16);
    SetColor(7); // 기본 색상
    printf("나가려면 아무키나 눌러주세요.");
    getchar(); // 프로그램 종료 대기
    getchar(); // 추가 대기
    return 0;
}
=======
//int main() {
//    // 테두리 생성
//    system("cls");
//    CreateOutFrame();
//
//    // 게임 시작
//    random_number();
//
//    // 종료 메시지
//    MoveConsole(25, 16);
//    SetColor(7); // 기본 색상
//    printf("나가려면 아무키나 눌러주세요.");
//    getchar(); // 프로그램 종료 대기
//    getchar(); // 추가 대기
//    return 0;
//}
>>>>>>> dde508484033dd8c9782ab2ca68a1125b0770e16
