#include "MOC.h"

// 사용자 입력 함수 (비동기 입력 및 실시간 카운트다운)
int InputWithCount(char* input, int max_length, int timeout) {
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
    }

    input[index] = '\0'; // 입력 종료
    return 0; // 시간 초과
}

// 오름차순 게임
void PlayAscendingGame() {
    int numbers[10];
    char user_input[100];
    int user_numbers[10];

    // 난수 생성 및 초기화
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 100 + 1; // 1~100 사이의 난수
    }

    // 틀 출력
    CreateOutFrame();

    // 게임 안내 출력
    MoveConsole(23, 2);
    printf("오름차순 게임");
    MoveConsole(23, 3);
    printf("================");

    // 난수 배열 출력
    MoveConsole(23, 5);
    printf("다음 숫자들을 오름차순으로 정렬하세요:");
    MoveConsole(23, 6);
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }

    // 사용자 입력 요청 (카운트다운 시작)
    MoveConsole(23, 8);
    printf("60초 안에 숫자를 입력하세요 (공백으로 구분):");
    MoveConsole(23, 12); // 출력 문장과 동일한 x값에서 입력 시작

    if (!InputWithCount(user_input, sizeof(user_input), 60)) {
        MoveConsole(23, 14);
        printf("시간 초과! 게임 실패!");
        return;
    }

    // 사용자 입력 숫자 배열로 변환
    char* token = strtok(user_input, " ");
    for (int i = 0; token != NULL && i < 10; i++) {
        user_numbers[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // 사용자 입력 검증 (오름차순인지 확인)
    for (int i = 0; i < 9; i++) {
        if (user_numbers[i] > user_numbers[i + 1]) {
            MoveConsole(23, 14);
            printf("실패! 오름차순이 아닙니다.");
            return;
        }
    }

    // 성공 메시지
    MoveConsole(23, 14);
    printf("성공! 올바르게 오름차순으로 정렬했습니다.");
}

/*int main() {
    system("cls"); // 화면 초기화
    PlayAscendingGame(); // 오름차순 게임 실행
    MoveConsole(23, 15);
    printf("Press any key to exit…");
    getchar();
    return 0;
}*/