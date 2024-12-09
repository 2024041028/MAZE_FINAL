#include "MOC.h"

extern int h; // 목숨 (다른 파일에서 선언된 전역 변수)
extern char user_name[20]; // 사용자 이름 (다른 파일에서 선언된 전역 변수)

// 사용자 입력 함수 (카운트다운 없음)
int InputWithcnt1(char* input, int max_length, int x, int y) {
    int index = 0;

    MoveConsole(x, y);

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') { // Enter 키 입력 시 종료
                input[index] = '\0';
                return 1; // 성공적으로 입력받음
            }
            else if (ch == '\b' && index > 0) { // Backspace 처리
                index--;
                MoveConsole(x + index * 2, y);
                printf("  "); // 공백으로 지움
                MoveConsole(x + index * 2, y);
            }
            else if (index < max_length - 1) { // 입력 가능
                input[index++] = ch; // 입력값 저장
                MoveConsole(x + (index - 1) * 2, y);
                printf("%c", ch);
            }
        }
    }

    return 0; // 종료 (실패는 없음)
}

// 청개구리 가위바위보 게임
void PlayGreenFrogRPS(int level) {
    const char* options[] = { "가위", "바위", "보" };
    char user_input[10] = { 0 };
    char reaction[10] = { 0 };
    int computer_choice;
    int timeout2 = 5;

    // 난이도 설정
    if (level == 1) { timeout2 = 5; }
    else if (level == 2) { timeout2 = 4; }
    else if (level == 3) { timeout2 = 3; }

    // 초기화
    srand(time(NULL));

    CreateOutFrame();

    // 사용자 ID와 목숨 출력
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
    printf("청개구리 가위바위보 게임");
    MoveConsole(23, 6);
    printf("=======================");

    // 첫 번째 입력 요청 (카운트다운 없음)
    MoveConsole(23, 8);
    printf("가위, 바위, 보 중 하나를 입력하세요:");
    MoveConsole(23, 10);
    SetColor(14);
    if (!InputWithcnt1(user_input, sizeof(user_input), 23, 12)) {
        SetColor(7);
        MoveConsole(23, 14);
        printf("입력 오류! 게임 종료!");
        return;
    }

    // 입력값 출력
    MoveConsole(23, 12);
    SetColor(14);
    printf("입력한 값: %s", user_input);
    SetColor(7);

    // 컴퓨터 선택 출력
    MoveConsole(23, 14);
    printf("컴퓨터의 선택: ");
    computer_choice = rand() % 3; // 컴퓨터 선택 결정
    SetColor(14);
    printf("%s", options[computer_choice]);
    SetColor(7);

    // 두 번째 입력 요청 (카운트다운 실행)
    MoveConsole(23, 16);
    printf("결과에 따라 반응을 입력하세요");
    MoveConsole(23, 17);
    printf("('이겼다', '졌다', '개굴'): ");
    MoveConsole(23, 19);
    SetColor(14);
    if (!InputWithcnt1(reaction, sizeof(reaction), timeout2, 23, 20)) {
        SetColor(7);
        MoveConsole(23, 22);
        printf("시간 초과! 게임 실패!");
        return;
    }
    SetColor(7);

    // 결과 확인
    int user_choice = -1;
    if (strcmp(user_input, "가위") == 0) user_choice = 0;
    else if (strcmp(user_input, "바위") == 0) user_choice = 1;
    else if (strcmp(user_input, "보") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 22);
        SetColor(14);
        printf("잘못된 입력입니다. 다시 시도하세요.");
        SetColor(7);
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    // 최종 결과 출력
    MoveConsole(23, 22);
    SetColor(14);
    if ((result == 0 && strcmp(reaction, "개굴") == 0) ||
        (result == 1 && strcmp(reaction, "졌다") == 0) ||
        (result == 2 && strcmp(reaction, "이겼다") == 0)) {
        printf("정답! 성공!");
    }
    else {
        printf("틀렸습니다. 실패!");
    }
    SetColor(7);
}