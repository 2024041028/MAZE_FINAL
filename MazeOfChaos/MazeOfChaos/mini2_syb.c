#include "MOC.h"

#define MAX_ATTEMPTS 6
#define WORD_LENGTH 3

// ���� �ܾ� ���� �Լ�
void ChooseRandomWord(char* word) {
    const char* words[] = { "cat", "dog", "bat", "hat", "rat", "man" };
    int index = rand() % (sizeof(words) / sizeof(words[0]));
    strcpy(word, words[index]);
}

// ���� ����� ��Ʈ�� ����ϴ� �Լ�
void PrintHearts(int attemptsLeft) {
    MoveConsole(25, 3);
    SetColor(12); // ������
    printf("Lives: ");
    for (int i = 0; i < attemptsLeft; i++) {
        printf("�� "); // ���� �õ� ����ŭ ��Ʈ ���
    }
    for (int i = 0; i < (MAX_ATTEMPTS - attemptsLeft); i++) {
        printf("�� "); // ������ �õ��� �� ��Ʈ�� ǥ��
    }
    SetColor(7); // �⺻ ���� ����
}

// ��� ���� �Լ�
void PlayHangman() {
    char word[WORD_LENGTH + 1]; // �ܾ� ���� (3���� + null terminator)
    char guessed[WORD_LENGTH + 1]; // ������ ���� ����
    char wrongGuesses[MAX_ATTEMPTS] = { 0 }; // Ʋ�� ���� ����
    int attempts = 0;

    // ���� �ܾ� ����
    srand(time(NULL));
    ChooseRandomWord(word);

    // �ʱ�ȭ
    for (int i = 0; i < WORD_LENGTH; i++) {
        guessed[i] = '_'; // �ʱ� ����: '_'�� ǥ��
    }
    guessed[WORD_LENGTH] = '\0'; // ���ڿ� ����

    while (attempts < MAX_ATTEMPTS) {
        system("cls"); // ȭ�� �ʱ�ȭ
        CreateOutFrame();

        // ���� ����� ��Ʈ�� ���
        PrintHearts(MAX_ATTEMPTS - attempts);

        MoveConsole(25, 5);
        SetColor(11); // ���� �Ķ���
        printf("Current Word: %s", guessed);
        MoveConsole(25, 7);
        printf("Wrong guesses: %s", wrongGuesses);
        MoveConsole(25, 9);
        printf("Guess a letter: ");

        char guess;
        scanf(" %c", &guess); // ���� �Է�

        // �̹� Ʋ�� �������� Ȯ��
        if (strchr(wrongGuesses, guess) != NULL || strchr(guessed, guess) != NULL) {
            MoveConsole(25, 11);
            printf("You already guessed '%c'. Try again.", guess);
            getchar(); // ��� ���
            continue; // �ݺ�
        }

        // ���ڰ� �´��� Ȯ��
        int found = 0;
        for (int i = 0; i < WORD_LENGTH; i++) {
            if (word[i] == guess) {
                guessed[i] = guess; // ���� ���ڸ� ǥ��
                found = 1; // ���� ���ڰ� �ִ�
            }
        }

        // ���� ���ڰ� ���� ���
        if (!found) {
            wrongGuesses[attempts] = guess; // Ʋ�� ���� �߰�
            attempts++; // �õ� ����
        }

        // �ܾ ��� ���� ���
        if (strcmp(word, guessed) == 0) {
            MoveConsole(25, 13);
            SetColor(10); // �ʷϻ�
            printf("Congratulations! You guessed the word: %s\n", word);
            MoveConsole(25, 15);
            SetColor(7);
            printf("Press any key to return to the main menu...");
            getchar(); getchar();
            return; // ���� ����
        }
    }
}