#include "MOC.h"

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 5 // �ִ� �ܾ� ���� (5����)

// ���� �ܾ� ���� �Լ�
void ChooseRandomWord(char* word, int wordLength) {
    const char* words3[] = { "cat", "dog", "bat", "hat", "rat", "man" };
    const char* words4[] = { "wolf", "deer", "frog", "lion", "bear", "duck" };
    const char* words5[] = { "tiger", "eagle", "shark", "snake", "horse", "zebra" };

    const char** wordsArray;
    int arraySize;

    // ������ ���� �迭�� ũ�� ����
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
        return; // �߸��� ������ ��� ����
    }

    int index = rand() % arraySize;

    // strcpy ��� �ܾ� ���� ����
    for (int i = 0; i < wordLength; i++) {
        word[i] = wordsArray[index][i];
    }
    word[wordLength] = '\0'; // ���ڿ� ����
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
    now_level = 1;
    int wordLength = now_level + 2; // �ܾ� ���� ���� (3, 4, 5����)
    char word[MAX_WORD_LENGTH + 1]; // ���� ũ�� �迭�� �ܾ� ����
    char guessed[MAX_WORD_LENGTH + 1]; // ���� ũ�� �迭�� ������ ���� ����
    char wrongGuesses[MAX_ATTEMPTS] = { 0 }; // Ʋ�� ���� ����
    int attempts = 0;

    // ���� �ܾ� ����
    srand(time(NULL));
    ChooseRandomWord(word, wordLength);

    // �ʱ�ȭ
    for (int i = 0; i < wordLength; i++) {
        guessed[i] = '_'; // �ʱ� ����: '_'�� ǥ��
    }
    guessed[wordLength] = '\0'; // ���ڿ� ����

    while (attempts < MAX_ATTEMPTS) {
        system("cls"); // ȭ�� �ʱ�ȭ
        CreateOutFrame(now_color_num);

        // ���� ����� ��Ʈ�� ���
        PrintHearts(MAX_ATTEMPTS - attempts);

        MoveConsole(38, 9);
        SetColor(11); // ���� �Ķ���
        printf("���� �ܾ� : %s", guessed);
        MoveConsole(38, 12);
        printf("Ʋ�� ���� : %s", wrongGuesses);
        MoveConsole(36, 14);
        printf("���ڸ� ����������: ");

        char guess = getchar(); // ���� �Է�
        getchar(); // �ٹٲ� ����

        // �̹� Ʋ�� ���� �Ǵ� ���� ���ڸ� �Է��� ��� ó��
        if (strchr(wrongGuesses, guess) != NULL || strchr(guessed, guess) != NULL) {
            MoveConsole(23, 18);
            SetColor(14); // �����
            printf("'%c'�� �̹� �Է��� �ܾ��Դϴ�. ����Ű�� �����ּ���", guess);
            SetColor(7); // �⺻ ���� ����
            getchar(); // ����� �Է� ���
            continue; // ���� �ݺ�
        }

        // ���ڰ� �´��� Ȯ��
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
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
            system("cls");
            CreateOutFrame(now_color_num);
            MoveConsole(31, 13);
            SetColor(10); // �ʷϻ�
            printf("���ϵ帳�ϴ� �ܾ�� %s�Դϴ�!", word);
            MoveConsole(25, 15);
            SetColor(7);
            printf("Press any key to return to the main menu...");
            getchar(); getchar();
            return; // ���� ����
        }
    }

    // ���� �޽���
    system("cls");
    CreateOutFrame(now_color_num);
    MoveConsole(25, 13);
    SetColor(4); // ������
    printf("�õ��� ��� ����ϼ̽��ϴ� �ܾ�� %s�Դϴ�!", word);
    MoveConsole(25, 15);
    SetColor(7);
    printf("Press any key to return to the main menu...");
    getchar(); getchar();
}
