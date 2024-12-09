#include "MOC.h"
#include <stdbool.h>
extern int h; // 목숨 (다른 파일에서 선언된 전역 변수)
extern char user_name[20]; // 사용자 이름 (다른 파일에서 선언된 전역 변수)

// 사용자 입력 함수 (시간 제한 포함, 비동기 처리)
bool InputWithTimeoutTrivia(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    // 입력 초기화
    input[0] = '\0';

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 카운트다운 오른쪽 상단에 출력
        MoveConsole(55, 2);
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // 키 입력 감지
            char ch = _getch();
            if (ch == '\r') { // Enter 키 입력 시 종료
                input[index] = '\0';
                return true; // 입력 성공
            }
            else if (ch == '\b' && index > 0) { // Backspace 처리
                index--;
                MoveConsole(23 + index, 14);
                printf(" ");
                MoveConsole(23 + index, 14);
            }
            else if (index < max_length - 1) { // 추가 입력 가능
                input[index++] = ch;
                SetColor(14);
                MoveConsole(23 + index - 1, 14);
                printf("%c", ch);
                SetColor(7);
            }
        }

        // 경과 시간 갱신
        elapsed_time = clock() - start_time;
    }

    input[index] = '\0'; // 입력 종료
    return false; // 시간 초과
}

// 상식 퀴즈 게임 (비동기 입력 및 카운트다운 포함)
void PlayTriviaQuizGame(int level) {
    char* questions[] = {
        "대한민국의 수도는 어디인가요?",
        "지구에서 가장 높은 산은 무엇인가요?",
        "태양계에서 가장 큰 행성은 무엇인가요?",
        "피타고라스 정리는 직각삼각형의 무엇을 설명하나요?",
        "컴퓨터에서 사용되는 기본적인 0과 1의 단위를 무엇이라고 하나요?",
        "물이 얼어 고체가 되는 온도는 섭씨 몇 도인가요?",
        "에디슨이 발명한 가장 유명한 것은 무엇인가요?",
        "대한민국에서 가장 긴 강은 무엇인가요?",
        "인류가 최초로 달에 착륙한 해는 언제인가요?",
        "세계에서 가장 많이 사용되는 언어는 무엇인가요?"
    };

    char* answers[] = { "서울", "에베레스트", "목성", "빗변", "비트", "0도", "전구", "한강", "1969년", "중국어" };
    char user_input[50];
    int num_questions = 10;
    int timeout = 10;

    // 난이도 설정
    if (level == 1) timeout = 10;
    else if (level == 2) timeout = 7;
    else if (level == 3) timeout = 5;

    srand(time(NULL));
    int random_index = rand() % num_questions;

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

    // 질문 출력
    MoveConsole(23, 5);
    printf("상식 퀴즈 게임");
    MoveConsole(23, 6);
    printf("================");
    MoveConsole(23, 8);
    printf("문제: %s", questions[random_index]);

    MoveConsole(23, 11);
    printf("%d초 안에 정답을 입력하세요:", timeout);
    MoveConsole(23, 14);

    // 비동기 입력 처리
    if (!InputWithTimeoutTrivia(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 16);
        SetColor(14);
        printf("시간 초과! 게임 실패!");
        SetColor(7);
        return;
    }

    // 입력값 출력
    MoveConsole(23, 15);
    printf("입력한 값: ");
    SetColor(14);
    printf("%s", user_input);
    SetColor(7);

    // 정답 확인
    if (strcmp(user_input, answers[random_index]) == 0) {
        MoveConsole(23, 17);
        SetColor(14);
        printf("정답! 성공했습니다!");
        SetColor(7);
    }
    else {
        MoveConsole(23, 17);
        SetColor(14);
        printf("오답! 정답은 '%s'입니다.", answers[random_index]);
        SetColor(7);
    }
}
