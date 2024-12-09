#include "MOC.h"
#include <stdbool.h>
#include <windows.h>

extern int h; // 목숨 (다른 파일에서 선언된 전역 변수)
extern char user_name[20]; // 사용자 이름 (다른 파일에서 선언된 전역 변수)

// 콘솔 인코딩 설정
void SetupConsoleEncoding2() {
    SetConsoleOutputCP(CP_ACP);
    SetConsoleCP(CP_ACP);
}

// 사용자 입력 함수 (시간 제한 포함, 입력값 노란색 표시, 카운트다운)
bool InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 카운트다운 오른쪽 상단에 출력
        MoveConsole(55, 2);
        printf("            ");
        MoveConsole(55, 2);
        printf("남은 시간: %d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // 키 입력 확인
            char ch = _getch();
            if (ch == '\r') { // Enter 키
                input[index] = '\0';
                return true; // 입력 완료
            }
            else if (ch == '\b' && index > 0) { // Backspace 처리
                index--;
                MoveConsole(23 + index, 14);
                printf(" ");
                MoveConsole(23 + index, 14);
            }
            else if (index < max_length - 1) { // 입력 가능한 경우
                input[index++] = ch;
                SetColor(14);
                MoveConsole(23 + index - 1, 14);
                printf("%c", ch);
                SetColor(7);
            }
        }

        elapsed_time = clock() - start_time;
        Sleep(50); // 화면 업데이트를 위한 지연
    }

    input[index] = '\0';
    return false; // 시간 초과
}

// 청개구리 가위바위보 게임
void PlayGreenFrogRPS(int level) {
    SetupConsoleEncoding2();

    const char* options[] = { "가위", "바위", "보" };
    char user_input[20];
    char reaction[20];
    int computer_choice;
    int timeout = 10;

    // 난이도 설정
    if (level == 1) timeout = 10;  // 쉬움: 10초
    else if (level == 2) timeout = 7;  // 보통: 7초
    else if (level == 3) timeout = 5;  // 어려움: 5초

    srand(time(NULL));
    CreateOutFrame();

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
    printf("청개구리 가위바위보 게임");
    MoveConsole(23, 6);
    printf("======================");

    // 첫 번째 입력 요청
    MoveConsole(23, 8);
    printf("가위, 바위, 보 중 하나를 입력하세요:");
    MoveConsole(23, 10);

    if (!InputWithTimeout(user_input, sizeof(user_input), 20)) { // 첫 번째 입력
        MoveConsole(23, 12);
        printf("시간 초과! 게임 종료.");
        return;
    }

    // 입력값 출력
    MoveConsole(23, 12);
    SetColor(14);
    printf("입력값: %s", user_input);
    SetColor(7);

    // 컴퓨터 선택 출력
    computer_choice = rand() % 3;
    MoveConsole(23, 14);
    printf("컴퓨터 선택: %s", options[computer_choice]);

    // 결과 계산
    int user_choice = -1;
    if (strcmp(user_input, "가위") == 0) user_choice = 0;
    else if (strcmp(user_input, "바위") == 0) user_choice = 1;
    else if (strcmp(user_input, "보") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 16);
        printf("잘못된 입력입니다. 게임 종료.");
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    // 두 번째 입력 요청 (반응 입력)
    MoveConsole(23, 16);
    printf("결과에 따라 반응을 입력하세요 (이겼다, 졌다, 개굴):");
    MoveConsole(23, 18);

    if (!InputWithTimeout(reaction, sizeof(reaction), timeout)) { // 두 번째 입력
        MoveConsole(23, 20);
        SetColor(14);
        printf("시간 초과! 게임 실패!");
        SetColor(7);
        return;
    }

    // 반응 확인
    bool success = false;
    if (result == 0 && strcmp(reaction, "개굴") == 0) success = true;
    else if (result == 1 && strcmp(reaction, "졌다") == 0) success = true;
    else if (result == 2 && strcmp(reaction, "이겼다") == 0) success = true;

    // 최종 결과 출력
    MoveConsole(23, 20);
    if (success) {
        SetColor(14);
        printf("정답! 성공했습니다!");
        SetColor(7);
    }
    else {
        SetColor(14);
        printf("틀렸습니다. 실패!");
        SetColor(7);
    }
}
