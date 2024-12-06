#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "MOC.h"

#define MAX_QUESTIONS 5    // 문제 수
#define TIME_LIMIT 10      // 제한 시간 (초)

// 타이머 함수
int StartTimer(int timeLimit) {
    clock_t startTime = clock(); // 시작 시간 저장
    while (1) {
        clock_t currentTime = clock();
        double elapsed = (double)(currentTime - startTime) / CLOCKS_PER_SEC;
        if (elapsed > timeLimit) {
            return 0; // 시간 초과
        }

        if (_kbhit()) { // 키 입력이 있으면
            return 1; // 정상 진행
        }
    }
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

// 사용자 입력을 받아 정수로 변환하는 함수
int GetUserInput() {
    int number = 0;
    char ch;

    while (1) {
        if (_kbhit()) { // 키 입력 확인
            ch = _getch(); // 키 입력 받기

            if (ch == 13) { // Enter 키가 눌리면 입력 종료
                break;
            }
            else if (ch >= '0' && ch <= '9') { // 숫자 입력일 경우
                number = number * 10 + (ch - '0'); // 입력된 숫자를 정수로 변환
                printf("%c", ch); // 입력된 숫자 출력
            }
        }
    }

    printf("\n"); // 입력 종료 후 줄 바꿈
    return number;
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

        // 타이머 시작
        MoveConsole(36, 10);
        SetColor(14); // 노란색
        printf("제한 시간: %d초", TIME_LIMIT);

        MoveConsole(36, 12);
        SetColor(7); // 기본 색
        printf("답을 입력하세요: ");

        if (!StartTimer(TIME_LIMIT)) { // 시간 초과 확인
            MoveConsole(36, 14);
            SetColor(4); // 빨간색
            printf("시간 초과! 게임 실패!");
            MoveConsole(36, 16);
            printf("Press any key to return to the main menu...");
            getchar();
            return;
        }

        // 사용자 입력 받기
        userAnswer = GetUserInput();

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
