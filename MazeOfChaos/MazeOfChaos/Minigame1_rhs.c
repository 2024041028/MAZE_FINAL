<<<<<<< HEAD
#include "MOC.h"
<<<<<<< HEAD
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
=======
#include "MOC.h"
// ?ъ슜???낅젰 ?⑥닔 (?쒓컙 ?쒗븳 ?놁씠)
void InputWithoutTimeout(char* input, int max_length) {
    MoveConsole(23, 10); // ?ъ슜???낅젰 ?꾩튂
    printf("                             "); // ?댁쟾 ?낅젰 吏�?곌린
    MoveConsole(23, 10); // 而ㅼ꽌 ?꾩튂濡??대룞
    fgets(input, max_length, stdin); // ?낅젰 諛쏄린
    input[strcspn(input, "\n")] = '\0'; // 以꾨컮轅??쒓굅
}

// ?ъ슜???낅젰 ?⑥닔 (?쒓컙 ?쒗븳 ?ы븿, ?ㅻⅨ履??곷떒 移댁슫?몃떎??異쒕젰)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // ?쒖옉 ?쒓컙
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 移댁슫?몃떎???ㅻⅨ履??곷떒??異쒕젰
        MoveConsole(55, 1);
        printf("?⑥? ?쒓컙: %2d珥?, timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // ???낅젰???덉쑝硫?
            MoveConsole(23, 10); // ?ъ슜???낅젰 ?꾩튂
            printf("                             "); // ?댁쟾 ?낅젰 吏�?곌린
            MoveConsole(23, 10); // 而ㅼ꽌 ?꾩튂濡??대룞
            fgets(input, max_length, stdin); // ?낅젰 諛쏄린
            input[strcspn(input, "\n")] = '\0'; // 以꾨컮轅??쒓굅
            return 1; // ?깃났?곸쑝濡??낅젰諛쏆쓬
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
        }

        elapsed_time = clock() - start_time;
    }

<<<<<<< HEAD
    return 0; // 시간 초과
}

// 청개구리 가위바위보 게임
void PlayGreenFrogRPS() {
    const char* options[] = { "가위", "바위", "보" };
=======
    return 0; // ?쒓컙 珥덇낵
}

// 泥?컻援щ━ 媛�?꾨컮?꾨낫 寃뚯엫
void PlayGreenFrogRPS() {
    const char* options[] = { "媛�??, "諛붿쐞", "蹂? };
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
    char user_input[10];
    char reaction[10];
    int computer_choice;

<<<<<<< HEAD
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
=======
    // 珥덇린??
    srand(time(NULL));

    // ?� 異쒕젰
    CreateOutFrame();

    // 寃뚯엫 ?덈궡 異쒕젰
    MoveConsole(23, 2);
    printf("泥?컻援щ━ 媛�?꾨컮?꾨낫 寃뚯엫");
    MoveConsole(23, 3);
    printf("=======================");

    // ?ъ슜???낅젰 ?붿껌
    MoveConsole(23, 5);
    printf("媛�?? 諛붿쐞, 蹂?以??섎굹瑜??낅젰?섏꽭??");
    InputWithoutTimeout(user_input, sizeof(user_input)); // ?쒓컙 ?쒗븳 ?놁씠 ?낅젰諛쏆쓬

    // 而댄벂??寃곌낵 異쒕젰
    MoveConsole(23, 7);
    printf("而댄벂?곗쓽 ?좏깮: ");
    computer_choice = rand() % 3; // 而댄벂???좏깮 寃곗젙
    printf("%s", options[computer_choice]);

    // 寃곌낵 怨꾩궛
    int user_choice = -1;
    if (strcmp(user_input, "媛�??) == 0) user_choice = 0;
    else if (strcmp(user_input, "諛붿쐞") == 0) user_choice = 1;
    else if (strcmp(user_input, "蹂?) == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("?섎せ???낅젰?낅땲?? ?ㅼ떆 ?쒕룄?섏꽭??");
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

<<<<<<< HEAD
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
/*
int main() {
    system("cls"); // 화면 초기화
    PlayGreenFrogRPS(); // 게임 실행
    MoveConsole(23, 15);
    printf("Press any key to exit…");
    getchar();
    return 0;
}
*/
=======
    // 諛섏쓳 ?낅젰 ?붿껌 (移댁슫?몃떎???쒖옉)
    MoveConsole(23, 9);
    printf("寃곌낵???곕씪 諛섏쓳???낅젰?섏꽭??);
    MoveConsole(23, 10);
    printf("('?닿꼈??, '議뚮떎', '媛쒓뎬'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), 10)) {
        MoveConsole(23, 11);
        printf("?쒓컙 珥덇낵! 寃뚯엫 ?ㅽ뙣!");
        return;
    }

    // 寃곌낵 ?뺤씤
    int success = 0;
    if (result == 0 && strcmp(reaction, "媛쒓뎬") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "議뚮떎") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "?닿꼈??) == 0) success = 1;

    // 理쒖쥌 寃곌낵 異쒕젰
    MoveConsole(23, 11);
    if (success) {
        printf("?뺣떟! ?깃났!");
    }
    else {
        printf("?�?몄뒿?덈떎. ?ㅽ뙣!");
    }
}

int main() {
    system("cls"); // ?붾㈃ 珥덇린??
    PlayGreenFrogRPS(); // 寃뚯엫 ?ㅽ뻾
    MoveConsole(23, 15);
    printf("Press any key to exit??);
    getchar();
    return 0;
}
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
=======
#include "MOC.h"
// �궗�슜�옄 �엯�젰 �븿�닔 (�떆媛� �젣�븳 �뾾�씠)
void InputWithoutTimeout(char* input, int max_length) {
    MoveConsole(23, 10); // �궗�슜�옄 �엯�젰 �쐞移�
    printf("                             "); // �씠�쟾 �엯�젰 吏��슦湲�
    MoveConsole(23, 10); // 而ㅼ꽌 �쐞移섎줈 �씠�룞
    fgets(input, max_length, stdin); // �엯�젰 諛쏄린
    input[strcspn(input, "\n")] = '\0'; // 以꾨컮轅� �젣嫄�
}

// �궗�슜�옄 �엯�젰 �븿�닔 (�떆媛� �젣�븳 �룷�븿, �삤瑜몄そ �긽�떒 移댁슫�듃�떎�슫 異쒕젰)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // �떆�옉 �떆媛�
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // 移댁슫�듃�떎�슫 �삤瑜몄そ �긽�떒�뿉 異쒕젰
        MoveConsole(55, 1);
        printf("�궓��� �떆媛�: %2d珥�", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // �궎 �엯�젰�씠 �엳�쑝硫�
            MoveConsole(23, 10); // �궗�슜�옄 �엯�젰 �쐞移�
            printf("                             "); // �씠�쟾 �엯�젰 吏��슦湲�
            MoveConsole(23, 10); // 而ㅼ꽌 �쐞移섎줈 �씠�룞
            fgets(input, max_length, stdin); // �엯�젰 諛쏄린
            input[strcspn(input, "\n")] = '\0'; // 以꾨컮轅� �젣嫄�
            return 1; // �꽦怨듭쟻�쑝濡� �엯�젰諛쏆쓬
        }

        elapsed_time = clock() - start_time;
    }

    return 0; // �떆媛� 珥덇낵
}

// 泥�媛쒓뎄由� 媛��쐞諛붿쐞蹂� 寃뚯엫
void PlayGreenFrogRPS() {
    const char* options[] = { "媛��쐞", "諛붿쐞", "蹂�" };
    char user_input[10];
    char reaction[10];
    int computer_choice;

    // 珥덇린�솕
    srand(time(NULL));

    // ��� 異쒕젰
    CreateOutFrame();

    // 寃뚯엫 �븞�궡 異쒕젰
    MoveConsole(23, 2);
    printf("泥�媛쒓뎄由� 媛��쐞諛붿쐞蹂� 寃뚯엫");
    MoveConsole(23, 3);
    printf("=======================");

    // �궗�슜�옄 �엯�젰 �슂泥�
    MoveConsole(23, 5);
    printf("媛��쐞, 諛붿쐞, 蹂� 以� �븯�굹瑜� �엯�젰�븯�꽭�슂:");
    InputWithoutTimeout(user_input, sizeof(user_input)); // �떆媛� �젣�븳 �뾾�씠 �엯�젰諛쏆쓬

    // 而댄벂�꽣 寃곌낵 異쒕젰
    MoveConsole(23, 7);
    printf("而댄벂�꽣�쓽 �꽑�깮: ");
    computer_choice = rand() % 3; // 而댄벂�꽣 �꽑�깮 寃곗젙
    printf("%s", options[computer_choice]);

    // 寃곌낵 怨꾩궛
    int user_choice = -1;
    if (strcmp(user_input, "媛��쐞") == 0) user_choice = 0;
    else if (strcmp(user_input, "諛붿쐞") == 0) user_choice = 1;
    else if (strcmp(user_input, "蹂�") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("�옒紐삳맂 �엯�젰�엯�땲�떎. �떎�떆 �떆�룄�븯�꽭�슂.");
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    // 諛섏쓳 �엯�젰 �슂泥� (移댁슫�듃�떎�슫 �떆�옉)
    MoveConsole(23, 9);
    printf("寃곌낵�뿉 �뵲�씪 諛섏쓳�쓣 �엯�젰�븯�꽭�슂");
    MoveConsole(23, 10);
    printf("('�씠寃쇰떎', '議뚮떎', '媛쒓뎬'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), 10)) {
        MoveConsole(23, 11);
        printf("�떆媛� 珥덇낵! 寃뚯엫 �떎�뙣!");
        return;
    }

    // 寃곌낵 �솗�씤
    int success = 0;
    if (result == 0 && strcmp(reaction, "媛쒓뎬") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "議뚮떎") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "�씠寃쇰떎") == 0) success = 1;

    // 理쒖쥌 寃곌낵 異쒕젰
    MoveConsole(23, 11);
    if (success) {
        printf("�젙�떟! �꽦怨�!");
    }
    else {
        printf("����졇�뒿�땲�떎. �떎�뙣!");
    }
}

int main() {
    system("cls"); // �솕硫� 珥덇린�솕
    PlayGreenFrogRPS(); // 寃뚯엫 �떎�뻾
    MoveConsole(23, 15);
    printf("Press any key to exit���");
    getchar();
    return 0;
}
>>>>>>> 6b6dc2e5789f4ced41a5bf33db9cfc72028a3f0c
