<<<<<<< HEAD
#include "MOC.h"
<<<<<<< HEAD
// ����� �Է� �Լ� (�ð� ���� ����)
void InputWithoutTimeout(char* input, int max_length) {
    MoveConsole(23, 10); // ����� �Է� ��ġ
    printf("                             "); // ���� �Է� �����
    MoveConsole(23, 10); // Ŀ�� ��ġ�� �̵�
    fgets(input, max_length, stdin); // �Է� �ޱ�
    input[strcspn(input, "\n")] = '\0'; // �ٹٲ� ����
}

// ����� �Է� �Լ� (�ð� ���� ����, ������ ��� ī��Ʈ�ٿ� ���)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // ���� �ð�
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ī��Ʈ�ٿ� ������ ��ܿ� ���
        MoveConsole(55, 1);
        printf("���� �ð�: %2d��", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // Ű �Է��� ������
            MoveConsole(23, 10); // ����� �Է� ��ġ
            printf("                             "); // ���� �Է� �����
            MoveConsole(23, 10); // Ŀ�� ��ġ�� �̵�
            fgets(input, max_length, stdin); // �Է� �ޱ�
            input[strcspn(input, "\n")] = '\0'; // �ٹٲ� ����
            return 1; // ���������� �Է¹���
=======
#include "MOC.h"
// ?�용???�력 ?�수 (?�간 ?�한 ?�이)
void InputWithoutTimeout(char* input, int max_length) {
    MoveConsole(23, 10); // ?�용???�력 ?�치
    printf("                             "); // ?�전 ?�력 지?�기
    MoveConsole(23, 10); // 커서 ?�치�??�동
    fgets(input, max_length, stdin); // ?�력 받기
    input[strcspn(input, "\n")] = '\0'; // 줄바�??�거
}

// ?�용???�력 ?�수 (?�간 ?�한 ?�함, ?�른�??�단 카운?�다??출력)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // ?�작 ?�간
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 카운?�다???�른�??�단??출력
        MoveConsole(55, 1);
        printf("?��? ?�간: %2d�?, timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // ???�력???�으�?
            MoveConsole(23, 10); // ?�용???�력 ?�치
            printf("                             "); // ?�전 ?�력 지?�기
            MoveConsole(23, 10); // 커서 ?�치�??�동
            fgets(input, max_length, stdin); // ?�력 받기
            input[strcspn(input, "\n")] = '\0'; // 줄바�??�거
            return 1; // ?�공?�으�??�력받음
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
        }

        elapsed_time = clock() - start_time;
    }

<<<<<<< HEAD
    return 0; // �ð� �ʰ�
}

// û������ ���������� ����
void PlayGreenFrogRPS() {
    const char* options[] = { "����", "����", "��" };
=======
    return 0; // ?�간 초과
}

// �?��구리 가?�바?�보 게임
void PlayGreenFrogRPS() {
    const char* options[] = { "가??, "바위", "�? };
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
    char user_input[10];
    char reaction[10];
    int computer_choice;

<<<<<<< HEAD
    // �ʱ�ȭ
    srand(time(NULL));

    // Ʋ ���
    CreateOutFrame();

    // ���� �ȳ� ���
    MoveConsole(23, 2);
    printf("û������ ���������� ����");
    MoveConsole(23, 3);
    printf("=======================");

    // ����� �Է� ��û
    MoveConsole(23, 5);
    printf("����, ����, �� �� �ϳ��� �Է��ϼ���:");
    InputWithoutTimeout(user_input, sizeof(user_input)); // �ð� ���� ���� �Է¹���

    // ��ǻ�� ��� ���
    MoveConsole(23, 7);
    printf("��ǻ���� ����: ");
    computer_choice = rand() % 3; // ��ǻ�� ���� ����
    printf("%s", options[computer_choice]);

    // ��� ���
    int user_choice = -1;
    if (strcmp(user_input, "����") == 0) user_choice = 0;
    else if (strcmp(user_input, "����") == 0) user_choice = 1;
    else if (strcmp(user_input, "��") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.");
=======
    // 초기??
    srand(time(NULL));

    // ?� 출력
    CreateOutFrame();

    // 게임 ?�내 출력
    MoveConsole(23, 2);
    printf("�?��구리 가?�바?�보 게임");
    MoveConsole(23, 3);
    printf("=======================");

    // ?�용???�력 ?�청
    MoveConsole(23, 5);
    printf("가?? 바위, �?�??�나�??�력?�세??");
    InputWithoutTimeout(user_input, sizeof(user_input)); // ?�간 ?�한 ?�이 ?�력받음

    // 컴퓨??결과 출력
    MoveConsole(23, 7);
    printf("컴퓨?�의 ?�택: ");
    computer_choice = rand() % 3; // 컴퓨???�택 결정
    printf("%s", options[computer_choice]);

    // 결과 계산
    int user_choice = -1;
    if (strcmp(user_input, "가??) == 0) user_choice = 0;
    else if (strcmp(user_input, "바위") == 0) user_choice = 1;
    else if (strcmp(user_input, "�?) == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("?�못???�력?�니?? ?�시 ?�도?�세??");
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

<<<<<<< HEAD
    // ���� �Է� ��û (ī��Ʈ�ٿ� ����)
    MoveConsole(23, 9);
    printf("����� ���� ������ �Է��ϼ���");
    MoveConsole(23, 10);
    printf("('�̰��', '����', '����'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), 10)) {
        MoveConsole(23, 11);
        printf("�ð� �ʰ�! ���� ����!");
        return;
    }

    // ��� Ȯ��
    int success = 0;
    if (result == 0 && strcmp(reaction, "����") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "����") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "�̰��") == 0) success = 1;

    // ���� ��� ���
    MoveConsole(23, 11);
    if (success) {
        printf("����! ����!");
    }
    else {
        printf("Ʋ�Ƚ��ϴ�. ����!");
    }
}
/*
int main() {
    system("cls"); // ȭ�� �ʱ�ȭ
    PlayGreenFrogRPS(); // ���� ����
    MoveConsole(23, 15);
    printf("Press any key to exit��");
    getchar();
    return 0;
}
*/
=======
    // 반응 ?�력 ?�청 (카운?�다???�작)
    MoveConsole(23, 9);
    printf("결과???�라 반응???�력?�세??);
    MoveConsole(23, 10);
    printf("('?�겼??, '졌다', '개굴'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), 10)) {
        MoveConsole(23, 11);
        printf("?�간 초과! 게임 ?�패!");
        return;
    }

    // 결과 ?�인
    int success = 0;
    if (result == 0 && strcmp(reaction, "개굴") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "졌다") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "?�겼??) == 0) success = 1;

    // 최종 결과 출력
    MoveConsole(23, 11);
    if (success) {
        printf("?�답! ?�공!");
    }
    else {
        printf("?�?�습?�다. ?�패!");
    }
}

int main() {
    system("cls"); // ?�면 초기??
    PlayGreenFrogRPS(); // 게임 ?�행
    MoveConsole(23, 15);
    printf("Press any key to exit??);
    getchar();
    return 0;
}
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
=======
#include "MOC.h"
// 사용자 입력 함수 (시간 제한 없이)
void InputWithoutTimeout(char* input, int max_length) {
    MoveConsole(23, 10); // 사용자 입력 위치
    printf("                             "); // 이전 입력 지우기
    MoveConsole(23, 10); // 커서 위치로 이동
    fgets(input, max_length, stdin); // 입력 받기
    input[strcspn(input, "\n")] = '\0'; // 줄바꿈 제거
}

// 사용자 입력 함수 (시간 제한 포함, 오른쪽 상단 카운트다운 출력)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // 시작 시간
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 카운트다운 오른쪽 상단에 출력
        MoveConsole(55, 1);
        printf("남은 시간: %2d초", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // 키 입력이 있으면
            MoveConsole(23, 10); // 사용자 입력 위치
            printf("                             "); // 이전 입력 지우기
            MoveConsole(23, 10); // 커서 위치로 이동
            fgets(input, max_length, stdin); // 입력 받기
            input[strcspn(input, "\n")] = '\0'; // 줄바꿈 제거
            return 1; // 성공적으로 입력받음
        }

        elapsed_time = clock() - start_time;
    }

    return 0; // 시간 초과
}

// 청개구리 가위바위보 게임
void PlayGreenFrogRPS() {
    const char* options[] = { "가위", "바위", "보" };
    char user_input[10];
    char reaction[10];
    int computer_choice;

    // 초기화
    srand(time(NULL));

    // 틀 출력
    CreateOutFrame();

    // 게임 안내 출력
    MoveConsole(23, 2);
    printf("청개구리 가위바위보 게임");
    MoveConsole(23, 3);
    printf("=======================");

    // 사용자 입력 요청
    MoveConsole(23, 5);
    printf("가위, 바위, 보 중 하나를 입력하세요:");
    InputWithoutTimeout(user_input, sizeof(user_input)); // 시간 제한 없이 입력받음

    // 컴퓨터 결과 출력
    MoveConsole(23, 7);
    printf("컴퓨터의 선택: ");
    computer_choice = rand() % 3; // 컴퓨터 선택 결정
    printf("%s", options[computer_choice]);

    // 결과 계산
    int user_choice = -1;
    if (strcmp(user_input, "가위") == 0) user_choice = 0;
    else if (strcmp(user_input, "바위") == 0) user_choice = 1;
    else if (strcmp(user_input, "보") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("잘못된 입력입니다. 다시 시도하세요.");
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    // 반응 입력 요청 (카운트다운 시작)
    MoveConsole(23, 9);
    printf("결과에 따라 반응을 입력하세요");
    MoveConsole(23, 10);
    printf("('이겼다', '졌다', '개굴'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), 10)) {
        MoveConsole(23, 11);
        printf("시간 초과! 게임 실패!");
        return;
    }

    // 결과 확인
    int success = 0;
    if (result == 0 && strcmp(reaction, "개굴") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "졌다") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "이겼다") == 0) success = 1;

    // 최종 결과 출력
    MoveConsole(23, 11);
    if (success) {
        printf("정답! 성공!");
    }
    else {
        printf("틀렸습니다. 실패!");
    }
}

int main() {
    system("cls"); // 화면 초기화
    PlayGreenFrogRPS(); // 게임 실행
    MoveConsole(23, 15);
    printf("Press any key to exit…");
    getchar();
    return 0;
}
>>>>>>> 6b6dc2e5789f4ced41a5bf33db9cfc72028a3f0c
