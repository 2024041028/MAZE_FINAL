#include "MOC.h"

#define MAX_ATTEMPTS 6
#define WORD_LENGTH 3

// 랜덤 단어 생성 함수
void ChooseRandomWord(char* word) {
    const char* words[] = { "cat", "dog", "bat", "hat", "rat", "man" };
    int index = rand() % (sizeof(words) / sizeof(words[0]));
    strcpy(word, words[index]);
}

// 남은 목숨을 하트로 출력하는 함수
void PrintHearts(int attemptsLeft) {
    MoveConsole(25, 3);
    SetColor(12); // 빨간색
    printf("Lives: ");
    for (int i = 0; i < attemptsLeft; i++) {
        printf("♥ "); // 남은 시도 수만큼 하트 출력
    }
    for (int i = 0; i < (MAX_ATTEMPTS - attemptsLeft); i++) {
        printf("♡ "); // 소진된 시도는 빈 하트로 표시
    }
    SetColor(7); // 기본 색상 복원
}

// 행맨 게임 함수
void PlayHangman() {
    char word[WORD_LENGTH + 1]; // 단어 저장 (3글자 + null terminator)
    char guessed[WORD_LENGTH + 1]; // 추측한 글자 저장
    char wrongGuesses[MAX_ATTEMPTS] = { 0 }; // 틀린 글자 저장
    int attempts = 0;

    // 랜덤 단어 선택
    srand(time(NULL));
    ChooseRandomWord(word);

    // 초기화
    for (int i = 0; i < WORD_LENGTH; i++) {
        guessed[i] = '_'; // 초기 상태: '_'로 표시
    }
    guessed[WORD_LENGTH] = '\0'; // 문자열 종료

    while (attempts < MAX_ATTEMPTS) {
        system("cls"); // 화면 초기화
        CreateOutFrame();

        // 남은 목숨을 하트로 출력
        PrintHearts(MAX_ATTEMPTS - attempts);

        MoveConsole(38, 9);
        SetColor(11); // 밝은 파란색
        printf("정답 단어 : %s", guessed);
        MoveConsole(38, 12);
        printf("틀린 글자 : %s", wrongGuesses);
        MoveConsole(36, 14);
        printf("글자를 맞혀보세요: ");

        char guess;
        scanf(" %c", &guess); // 문자 입력

        // 이미 틀린 글자 또는 맞춘 글자를 입력한 경우 처리
        if (strchr(wrongGuesses, guess) != NULL || strchr(guessed, guess) != NULL) {
            MoveConsole(36, 18);
            SetColor(14); // 노란색
            printf("'%c' is already guessed. Try another letter.", guess);
            SetColor(7); // 기본 색상 복원
            getchar(); getchar(); // 잠시 대기
            continue; // 다음 반복
        }

        // 글자가 맞는지 확인
        int found = 0;
        for (int i = 0; i < WORD_LENGTH; i++) {
            if (word[i] == guess) {
                guessed[i] = guess; // 맞춘 글자를 표시
                found = 1; // 맞춘 글자가 있다
            }
        }

        // 맞춘 글자가 없을 경우
        if (!found) {
            wrongGuesses[attempts] = guess; // 틀린 글자 추가
            attempts++; // 시도 증가
        }

        // 단어를 모두 맞춘 경우
        if (strcmp(word, guessed) == 0) {
            system("cls");
            CreateOutFrame();
            MoveConsole(25, 13);
            SetColor(10); // 초록색
            printf("Congratulations! You guessed the word: %s", word);
            MoveConsole(25, 15);
            SetColor(7);
            printf("Press any key to return to the main menu...");
            getchar(); getchar();
            return; // 게임 성공
        }
    }

    // 실패 메시지
    system("cls");
    CreateOutFrame();
    MoveConsole(25, 13);
    SetColor(4); // 빨간색
    printf("You've run out of attempts! The word was: %s", word);
    MoveConsole(25, 15);
    SetColor(7);
    printf("Press any key to return to the main menu...");
    getchar(); getchar();
}