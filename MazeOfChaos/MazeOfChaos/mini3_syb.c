#include "MOC.h"
#include <windows.h> // Sleep 함수를 사용하기 위한 헤더

#define MAX_QUESTIONS 5    // 문제 수
#define TIME_LIMIT 15      // 제한 시간 (초)

// 사용자 입력을 받는 함수 (카운트다운 포함)
int Countdown(char* input, int max_length, int timeout) {
    int start_time = clock(); // 시작 시간
    int elapsed_time = 0;
    int index = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) { // 제한 시간 내 반복
        // 카운트다운 오른쪽 상단에 출력
        MoveConsole(55, 1);
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
                    MoveConsole(54 + index, 12); // 입력 위치 조정
                    printf(" "); // 지우기
                    MoveConsole(54 + index, 12); // 다시 입력 위치로 이동
                }
            }
            else if (index < max_length - 1) { // 추가 입력 가능 시
                input[index++] = ch;
                MoveConsole(54 + index - 1, 12); // 입력 위치 조정
                printf("%c", ch);
            }
        }

        elapsed_time = clock() - start_time; // 경과 시간 업데이트
    }

    input[index] = '\0'; // 입력 종료
    return 0; // 시간 초과
}

// 랜덤 산수 문제 생성 함수
void GenerateMathProblem(int* a, int* b, char* op, int* answer) {
    *a = rand() % 50 + 1; // 1부터 50 사이의 숫자
    *b = rand() % 50 + 1;
    *op = (rand() % 2 == 0) ? '+' : '-'; // 랜덤으로 '+' 또는 '-' 선택

    // 정답 계산
    if (*op == '+') {
        *answer = *a + *b;
    }
    else {
        *answer = *a - *b;
    }
}

// 산수 게임 함수
void PlayMathGame() {
    system("cls");
    CreateOutFrame(); // 게임 틀 생성

    srand(time(NULL)); // 랜덤 시드 설정

    int score = 0; // 맞춘 문제 수
    int a, b, userAnswer, correctAnswer;
    char op; // 연산자 변수 선언 추가

    // 시작 안내 메시지
    MoveConsole(36, 5);
    SetColor(14); // 노란색
    printf("산수 게임에 오신 것을 환영합니다!\n");
    printf("3초 뒤 게임이 시작됩니다.\n");

    // 3초 카운트다운 표시
    for (int countdown = 3; countdown > 0; countdown--) {
        MoveConsole(36, 7);
        printf("남은 시간: %d초\n", countdown);
        Sleep(1000); // 1초 대기
    }

    SetColor(7); // 기본 색상 복원
    Sleep(1000); // 마지막 메시지 출력 후 1초 대기

    for (int i = 1; i <= MAX_QUESTIONS; i++) {
        // 문제 생성
        GenerateMathProblem(&a, &b, &op, &correctAnswer);

        // 문제 출력
        system("cls");
        CreateOutFrame();
        MoveConsole(36, 8);
        SetColor(11); // 파란색
        printf("문제 %d: %d %c %d = ?", i, a, op, b);

        // 사용자 입력 요청 (카운트다운 시작)
        MoveConsole(36, 10);
        SetColor(14); // 노란색
        printf("제한 시간: %d초\n", TIME_LIMIT);
        MoveConsole(36, 12);
        SetColor(7); // 기본 색
        printf("답을 입력하세요: "); // 입력 요청 출력
        MoveConsole(64, 12); // 입력 위치를 4칸 오른쪽으로 조정

        char user_input[100]; // 사용자 입력을 받을 배열

        // 사용자 입력 받기 (타이머 포함)
        if (!Countdown(user_input, sizeof(user_input), TIME_LIMIT)) {
            MoveConsole(36, 14);
            SetColor(4); // 빨간색
            printf("시간 초과! 게임 실패!");
            MoveConsole(36, 16);
            printf("Press any key to return to the main menu...");
            getchar();
            return;
        }

        // 입력값을 정수로 변환
        userAnswer = atoi(user_input);

        // 정답 확인
        if (userAnswer == correctAnswer) {
            MoveConsole(36, 14);
            SetColor(10); // 초록색
            printf("정답입니다!");
            score++;
        }
        else {
            MoveConsole(36, 14);
            SetColor(4); // 빨간색
            printf("오답입니다! 정답은 %d입니다.", correctAnswer);
        }

        // 문제 진행 상태 출력
        MoveConsole(36, 16);
        SetColor(7); // 기본 색상 복원
        printf("현재 점수: %d / %d", score, i);
        getchar(); // 다음 문제로 진행하기 위해 대기
    }

    // 게임 결과
    system("cls");
    CreateOutFrame();
    MoveConsole(36, 10);

    if (score == MAX_QUESTIONS) {
        SetColor(10); // 초록색
        printf("축하합니다! 모든 문제를 맞췄습니다!");
    }
    else {
        SetColor(4); // 빨간색
        printf("게임 종료! 맞춘 문제: %d/%d", score, MAX_QUESTIONS);
    }

    MoveConsole(36, 12);
    SetColor(7); // 기본 색상 복원
    printf("Press any key to return to the main menu...");
    getchar();
}
