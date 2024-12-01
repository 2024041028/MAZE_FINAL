#include "MOC.h"


// 게임 실행 함수
void random_number() {
    int target, guess;
    char result[20];

    // 랜덤 숫자 생성
    srand(time(NULL));
    target = rand() % 100 + 1;

    while (1) {
        MoveConsole(30, 12);
        SetColor(12);
        printf("숫자를 추측하시오 (1-100): ");
        scanf("%d", &guess);

        // 결과 처리
        if (guess < target) {
            sprintf(result, "UP!");
        }
        else if (guess > target) {
            sprintf(result, "DOWN!");
        }
        else {
            sprintf(result, "정답!");
            MoveConsole(25, 14);
            SetColor(10); // 초록색
            printf("축하드립니다! 정답은 %d입니다.          ", target);
            break;
        }

        // 결과 메시지 출력
        MoveConsole(25, 14);
        SetColor(12); 
        printf("%s                      ", result); // 이전 메시지 지우기
    }
}

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
