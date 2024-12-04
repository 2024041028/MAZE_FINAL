#include "MOC.h"

// 사용자 입력 함수 (비동기 입력 및 실시간 카운트다운)
int InputWithCountdown(char* input, int max_length, int timeout) {
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
                input[index] = '\0';
                return 1; // 성공적으로 입력받음
            }
            else if (ch == '\b') { // Backspace 키 처리
                if (index > 0) {
                    index--;
                    MoveConsole(23 + index, 12);
                    printf(" ");
                    MoveConsole(23 + index, 12);
                }
            }
            else if (index < max_length - 1) { // 추가 입력 가능 시
                input[index++] = ch;
                MoveConsole(23 + index - 1, 12);
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time;
    }

    input[index] = '\0'; // 입력 종료
    return 0; // 시간 초과
}

// 상식 퀴즈 게임
void PlayTriviaQuizGame() {
    // 퀴즈 질문과 정답 데이터
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

    char* answers[] = {
        "서울",
        "에베레스트",
        "목성",
        "빗변",
        "비트",
        "0도",
        "전구",
        "한강",
        "1969년",
        "중국어"
    };

    char user_input[100];
    int num_questions = 10;

    // 난수 생성
    srand(time(NULL));
    int random_index = rand() % num_questions;

    // 틀 출력
    CreateOutFrame();

    // 게임 안내 출력
    MoveConsole(23, 2);
    printf("상식 퀴즈 게임");
    MoveConsole(23, 3);
    printf("================");

    // 랜덤 질문 출력
    MoveConsole(23, 5);
    printf("문제: %s", questions[random_index]);

    // 사용자 입력 요청 (카운트다운 시작)
    MoveConsole(23, 8);
    printf("30초 안에 정답을 입력하세요:");
    MoveConsole(23, 12);

    if (!InputWithCountdown(user_input, sizeof(user_input), 30)) {
        MoveConsole(23, 14);
        printf("시간 초과! 게임 실패!");
        return;
    }

    // 정답 확인
    if (strcmp(user_input, answers[random_index]) == 0) {
        MoveConsole(23, 14);
        printf("정답! 성공했습니다.");
    }
    else {
        MoveConsole(23, 14);
        printf("오답! 정답은 '%s'입니다.", answers[random_index]);
    }
}

   