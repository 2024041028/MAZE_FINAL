#include "MOC.h"

// 사용자 입력 함수 (시간 제한 포함)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // 시작 시간
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        MoveConsole(65, 1);
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) {
            MoveConsole(23, 10);
            printf("                             ");
            MoveConsole(23, 10);
            fgets(input, max_length, stdin);
            input[strcspn(input, "\n")] = '\0';
            return 1; // 성공적으로 입력받음
        }

        elapsed_time = clock() - start_time;
    }

    return 0; // 시간 초과
}

// 청개구리 가위바위보 게임 (난이도 포함)
void PlayGreenFrogRPS(int level) {
    const char* options[] = { "가위", "바위", "보" };
    char user_input[10];
    char reaction[10];
    int computer_choice;

    // 난이도 설정
    int timeout = 10; // 기본 시간
    if (level == 1) timeout = 10;
    else if (level == 2) timeout = 5;
    else if (level == 3) timeout = 3;

    srand(time(NULL));

    // 틀 출력
    CreateOutFrame();

    // 게임 안내 출력
    MoveConsole(23, 2);
    printf("청개구리 가위바위보 게임");
    MoveConsole(23, 3);
    printf("=======================");

    // 사용자 입력 요청
    MoveConsole(23, 5);
    printf("가위, 바위, 보 중 하나를 입력하세요:");
    InputWithTimeout(user_input, sizeof(user_input), timeout);

    MoveConsole(23, 7);
    printf("컴퓨터의 선택: ");
    computer_choice = rand() % 3;
    printf("%s", options[computer_choice]);

    int user_choice = -1;
    if (strcmp(user_input, "가위") == 0) user_choice = 0;
    else if (strcmp(user_input, "바위") == 0) user_choice = 1;
    else if (strcmp(user_input, "보") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("잘못된 입력입니다. 다시 시도하세요.");
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    MoveConsole(23, 9);
    printf("결과에 따라 반응을 입력하세요 ('이겼다', '졌다', '개굴'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), timeout)) {
        MoveConsole(23, 11);
        printf("시간 초과! 게임 실패!");
        return;
    }

    int success = 0;
    if (result == 0 && strcmp(reaction, "개굴") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "졌다") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "이겼다") == 0) success = 1;

    MoveConsole(23, 11);
    if (success) printf("정답! 성공!");
    else printf("틀렸습니다. 실패!");
}
