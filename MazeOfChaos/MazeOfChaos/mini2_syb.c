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

        MoveConsole(25, 5);
        SetColor(11); // 밝은 파란색
        printf("Current Word: %s", guessed);
        MoveConsole(25, 7);
        printf("Wrong guesses: %s", wrongGuesses);
        MoveConsole(25, 9);
        printf("Guess a letter: ");

        char guess;
        scanf(" %c", &guess); // 문자 입력

        // 이미 틀린 글자인지 확인
        if (strchr(wrongGuesses, guess) != NULL || strchr(guessed, guess) != NULL) {
            MoveConsole(25, 11);
            printf("You already guessed '%c'. Try again.", guess);
            getchar(); // 잠깐 대기
            continue; // 반복
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
            MoveConsole(25, 13);
            SetColor(10); // 초록색
            printf("Congratulations! You guessed the word: %s\n", word);
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
    PrintHearts(0); // 실패 시 모든 목숨 소진
    MoveConsole(25, 13);
    SetColor(4); // 빨간색
    printf("You've run out of attempts! The word was: %s\n", word);
    MoveConsole(25, 15);
    SetColor(7);
    printf("Press any key to return to the main menu...");
    getchar();
    getchar();}
