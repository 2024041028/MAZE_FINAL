#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "MOC.h"

#define MAX_QUESTIONS 5    // 문제 수
#define TIME_LIMIT 30      // 제한 시간 (초)

// 사용자 입력을 받는 함수 (카운트다운 포함)
int Countdown(char* input, int max_length, int timeout) {
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
    char op;

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
        printf("답을 입력하세요: ");

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
