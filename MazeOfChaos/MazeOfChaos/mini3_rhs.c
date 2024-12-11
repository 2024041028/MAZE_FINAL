#include "MOC.h"
#include <stdbool.h>
#include <windows.h>

extern int h; // 목숨
extern char user_name[20]; // 사용자 이름

// 콘솔 인코딩 설정
void SetupConsoleEncoding() {
    SetConsoleOutputCP(CP_ACP);
    SetConsoleCP(CP_ACP);
}

// 텍스트 줄넘김 처리 함수
void PrintWrappedText(const char* text, int x, int y, int width) {
    int len = strlen(text);
    int line_start = 0;

    while (line_start < len) {
        MoveConsole(x, y++);
        for (int i = 0; i < width && (line_start + i) < len; i++) {
            printf("%c", text[line_start + i]);
        }
        line_start += width;
    }
}

// 사용자 입력 함수 (카운트다운 포함, 입력값 노란색 표시, 줄넘김 처리)
bool InputWithTimeoutTrivia(char* input, int max_length, int timeout) {
    int start_time = clock();
    int elapsed_time = 0;
    int index = 0;

    HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 카운트다운 오른쪽 상단에 출력 (사각형 틀 안에서 유지)
        MoveConsole(55, 2);
        printf("          "); // 잔여 값 지우기
        MoveConsole(55, 2);
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        // 키 입력 확인
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') { // Enter 키
                input[index] = '\0';
                return true; // 입력 완료
            }
            else if (ch == '\b' && index > 0) { // Backspace
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

        // 경과 시간 계산
        elapsed_time = clock() - start_time;

        // 화면 업데이트를 위한 지연
        Sleep(50);
    }

    input[index] = '\0';
    return false; // 시간 초과
}

// 상식 퀴즈 게임
int PlayTriviaQuizGame(int level) {

    ShowInstructionsAndMenu(2);
    SetupConsoleEncoding();

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
    PrintWrappedText(questions[random_index], 23, 8, 40); // 줄넘김 처리된 질문 출력

    MoveConsole(23, 12);
    printf("%d초 안에 정답을 입력하세요:", timeout);
    MoveConsole(23, 14);
    if (!InputWithTimeoutTrivia(user_input, sizeof(user_input), timeout)) {
        MoveConsole(23, 16);
        SetColor(14);
        printf("시간 초과! 게임 실패!");
        SetColor(7);
        return;
    }

    MoveConsole(23, 14);
    SetColor(14);
    printf("입력값: %s", user_input); // 입력한 값 출력
    SetColor(7);

    if (strcmp(user_input, answers[random_index]) == 0) {
        MoveConsole(23, 16);
        SetColor(14);
        printf("정답! 성공했습니다!");
        SetColor(7);
        return 1;
    }
    else {
        MoveConsole(23, 16);
        SetColor(14);
        printf("오답! 정답은 '%s'입니다.", answers[random_index]);
        SetColor(7);
        return 0;
    }
}
