#include "MOC.h"

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 5 // 최대 단어 길이 (5글자)

// 랜덤 단어 생성 함수
void ChooseRandomWord(char* word, int wordLength) {
    const char* words3[] = { "cat", "dog", "bat", "hat", "rat", "man" };
    const char* words4[] = { "wolf", "deer", "frog", "lion", "bear", "duck" };
    const char* words5[] = { "tiger", "eagle", "shark", "snake", "horse", "zebra" };

    const char** wordsArray;
    int arraySize;

    // 레벨에 따라 배열과 크기 설정
    if (wordLength == 3) {
        wordsArray = words3;
        arraySize = sizeof(words3) / sizeof(words3[0]);
    }
    else if (wordLength == 4) {
        wordsArray = words4;
        arraySize = sizeof(words4) / sizeof(words4[0]);
    }
    else if (wordLength == 5) {
        wordsArray = words5;
        arraySize = sizeof(words5) / sizeof(words5[0]);
    }
    else {
        return; // 잘못된 길이일 경우 종료
    }

    int index = rand() % arraySize;

    // strcpy 대신 단어 복사 수행
    for (int i = 0; i < wordLength; i++) {
        word[i] = wordsArray[index][i];
    }
    word[wordLength] = '\0'; // 문자열 종료
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
    now_level = 1;
    int wordLength = now_level + 2; // 단어 길이 결정 (3, 4, 5글자)
    char word[MAX_WORD_LENGTH + 1]; // 고정 크기 배열로 단어 저장
    char guessed[MAX_WORD_LENGTH + 1]; // 고정 크기 배열로 추측한 글자 저장
    char wrongGuesses[MAX_ATTEMPTS] = { 0 }; // 틀린 글자 저장
    int attempts = 0;

    // 랜덤 단어 선택
    srand(time(NULL));
    ChooseRandomWord(word, wordLength);

    // 초기화
    for (int i = 0; i < wordLength; i++) {
        guessed[i] = '_'; // 초기 상태: '_'로 표시
    }
    guessed[wordLength] = '\0'; // 문자열 종료

    while (attempts < MAX_ATTEMPTS) {
        system("cls"); // 화면 초기화
        CreateOutFrame(now_color_num);

        // 남은 목숨을 하트로 출력
        PrintHearts(MAX_ATTEMPTS - attempts);

        MoveConsole(38, 9);
        SetColor(11); // 밝은 파란색
        printf("정답 단어 : %s", guessed);
        MoveConsole(38, 12);
        printf("틀린 글자 : %s", wrongGuesses);
        MoveConsole(36, 14);
        printf("글자를 맞혀보세요: ");

        char guess = getchar(); // 문자 입력
        getchar(); // 줄바꿈 제거

        // 이미 틀린 글자 또는 맞춘 글자를 입력한 경우 처리
        if (strchr(wrongGuesses, guess) != NULL || strchr(guessed, guess) != NULL) {
            MoveConsole(23, 18);
            SetColor(14); // 노란색
            printf("'%c'는 이미 입력한 단어입니다. 엔터키를 눌러주세요", guess);
            SetColor(7); // 기본 색상 복원
            getchar(); // 사용자 입력 대기
            continue; // 다음 반복
        }

        // 글자가 맞는지 확인
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
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
            CreateOutFrame(now_color_num);
            MoveConsole(31, 13);
            SetColor(10); // 초록색
            printf("축하드립니다 단어는 %s입니다!", word);
            MoveConsole(25, 15);
            SetColor(7);
            printf("Press any key to return to the main menu...");
            getchar(); getchar();
            return; // 게임 성공
        }
    }

    // 실패 메시지
    system("cls");
    CreateOutFrame(now_color_num);
    MoveConsole(25, 13);
    SetColor(4); // 빨간색
    printf("시도를 모두 사용하셨습니다 단어는 %s입니다!", word);
    MoveConsole(25, 15);
    SetColor(7);
    printf("Press any key to return to the main menu...");
    getchar(); getchar();
}
