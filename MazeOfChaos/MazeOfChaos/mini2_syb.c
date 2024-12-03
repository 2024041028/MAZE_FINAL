#include "MOC.h"

#define MAX_ATTEMPTS 6
#define WORD_LENGTH 3
// ���� �ܾ� ���� �Լ�
void ChooseRandomWord(char* word) {
    const char* words[] = { "cat", "dog", "bat", "hat", "rat", "man" };
    int index = rand() % (sizeof(words) / sizeof(words[0]));
    strcpy(word, words[index]);
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
        MoveConsole(25, 5);
        SetColor(11); // ���� �Ķ���
        printf("Current Word: %s\n", guessed);
        MoveConsole(25, 7);
        printf("Wrong guesses: %s\n", wrongGuesses);
        MoveConsole(25, 9);
        printf("Attempts left: %d\n", MAX_ATTEMPTS - attempts);
        MoveConsole(25, 11);
        SetColor(11); // ���� �Ķ���
        printf("Guess a letter: ");

        char guess;
        scanf(" %c", &guess); // ���� �Է�

        // �̹� Ʋ�� �������� Ȯ��
        if (strchr(wrongGuesses, guess) != NULL || strchr(guessed, guess) != NULL) {
            MoveConsole(25, 13);
            printf("You already guessed '%c'. Try again.\n", guess);
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
            MoveConsole(25, 15);
            SetColor(10); // �ʷϻ�
            printf("Congratulations! You guessed the word: %s\n", word);
            return; // ���� ����
        }
    }

    // ���� �޽���
    MoveConsole(25, 17);
    SetColor(4); // ������
    printf("You've run out of attempts! The word was: %s\n", word);
}

int main() {
    // �׵θ� ����
    system("cls");
    CreateOutFrame();
    SetColor(7); // �⺻ ����

    // ��� ���� ����
    PlayHangman();

    // ���� �޽���
    MoveConsole(25, 20);
    printf("Press any key to exit...");
    getchar(); // ���α׷� ���� ���
    getchar(); // �߰� ���
    return 0;
}