<<<<<<< HEAD
#include "MOC.h"
<<<<<<< HEAD
// »ç¿ëÀÚ ÀÔ·Â ÇÔ¼ö (½Ã°£ Á¦ÇÑ ¾øÀÌ)
void InputWithoutTimeout(char* input, int max_length) {
    MoveConsole(23, 10); // »ç¿ëÀÚ ÀÔ·Â À§Ä¡
    printf("                             "); // ÀÌÀü ÀÔ·Â Áö¿ì±â
    MoveConsole(23, 10); // Ä¿¼­ À§Ä¡·Î ÀÌµ¿
    fgets(input, max_length, stdin); // ÀÔ·Â ¹Ş±â
    input[strcspn(input, "\n")] = '\0'; // ÁÙ¹Ù²Ş Á¦°Å
}

// »ç¿ëÀÚ ÀÔ·Â ÇÔ¼ö (½Ã°£ Á¦ÇÑ Æ÷ÇÔ, ¿À¸¥ÂÊ »ó´Ü Ä«¿îÆ®´Ù¿î Ãâ·Â)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // ½ÃÀÛ ½Ã°£
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // Ä«¿îÆ®´Ù¿î ¿À¸¥ÂÊ »ó´Ü¿¡ Ãâ·Â
        MoveConsole(55, 1);
        printf("³²Àº ½Ã°£: %2dÃÊ", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // Å° ÀÔ·ÂÀÌ ÀÖÀ¸¸é
            MoveConsole(23, 10); // »ç¿ëÀÚ ÀÔ·Â À§Ä¡
            printf("                             "); // ÀÌÀü ÀÔ·Â Áö¿ì±â
            MoveConsole(23, 10); // Ä¿¼­ À§Ä¡·Î ÀÌµ¿
            fgets(input, max_length, stdin); // ÀÔ·Â ¹Ş±â
            input[strcspn(input, "\n")] = '\0'; // ÁÙ¹Ù²Ş Á¦°Å
            return 1; // ¼º°øÀûÀ¸·Î ÀÔ·Â¹ŞÀ½
=======
#include "MOC.h"
// ?¬ìš©???…ë ¥ ?¨ìˆ˜ (?œê°„ ?œí•œ ?†ì´)
void InputWithoutTimeout(char* input, int max_length) {
    MoveConsole(23, 10); // ?¬ìš©???…ë ¥ ?„ì¹˜
    printf("                             "); // ?´ì „ ?…ë ¥ ì§€?°ê¸°
    MoveConsole(23, 10); // ì»¤ì„œ ?„ì¹˜ë¡??´ë™
    fgets(input, max_length, stdin); // ?…ë ¥ ë°›ê¸°
    input[strcspn(input, "\n")] = '\0'; // ì¤„ë°”ê¿??œê±°
}

// ?¬ìš©???…ë ¥ ?¨ìˆ˜ (?œê°„ ?œí•œ ?¬í•¨, ?¤ë¥¸ìª??ë‹¨ ì¹´ìš´?¸ë‹¤??ì¶œë ¥)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // ?œì‘ ?œê°„
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ì¹´ìš´?¸ë‹¤???¤ë¥¸ìª??ë‹¨??ì¶œë ¥
        MoveConsole(55, 1);
        printf("?¨ì? ?œê°„: %2dì´?, timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // ???…ë ¥???ˆìœ¼ë©?
            MoveConsole(23, 10); // ?¬ìš©???…ë ¥ ?„ì¹˜
            printf("                             "); // ?´ì „ ?…ë ¥ ì§€?°ê¸°
            MoveConsole(23, 10); // ì»¤ì„œ ?„ì¹˜ë¡??´ë™
            fgets(input, max_length, stdin); // ?…ë ¥ ë°›ê¸°
            input[strcspn(input, "\n")] = '\0'; // ì¤„ë°”ê¿??œê±°
            return 1; // ?±ê³µ?ìœ¼ë¡??…ë ¥ë°›ìŒ
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
        }

        elapsed_time = clock() - start_time;
    }

<<<<<<< HEAD
    return 0; // ½Ã°£ ÃÊ°ú
}

// Ã»°³±¸¸® °¡À§¹ÙÀ§º¸ °ÔÀÓ
void PlayGreenFrogRPS() {
    const char* options[] = { "°¡À§", "¹ÙÀ§", "º¸" };
=======
    return 0; // ?œê°„ ì´ˆê³¼
}

// ì²?°œêµ¬ë¦¬ ê°€?„ë°”?„ë³´ ê²Œì„
void PlayGreenFrogRPS() {
    const char* options[] = { "ê°€??, "ë°”ìœ„", "ë³? };
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
    char user_input[10];
    char reaction[10];
    int computer_choice;

<<<<<<< HEAD
    // ÃÊ±âÈ­
    srand(time(NULL));

    // Æ² Ãâ·Â
    CreateOutFrame();

    // °ÔÀÓ ¾È³» Ãâ·Â
    MoveConsole(23, 2);
    printf("Ã»°³±¸¸® °¡À§¹ÙÀ§º¸ °ÔÀÓ");
    MoveConsole(23, 3);
    printf("=======================");

    // »ç¿ëÀÚ ÀÔ·Â ¿äÃ»
    MoveConsole(23, 5);
    printf("°¡À§, ¹ÙÀ§, º¸ Áß ÇÏ³ª¸¦ ÀÔ·ÂÇÏ¼¼¿ä:");
    InputWithoutTimeout(user_input, sizeof(user_input)); // ½Ã°£ Á¦ÇÑ ¾øÀÌ ÀÔ·Â¹ŞÀ½

    // ÄÄÇ»ÅÍ °á°ú Ãâ·Â
    MoveConsole(23, 7);
    printf("ÄÄÇ»ÅÍÀÇ ¼±ÅÃ: ");
    computer_choice = rand() % 3; // ÄÄÇ»ÅÍ ¼±ÅÃ °áÁ¤
    printf("%s", options[computer_choice]);

    // °á°ú °è»ê
    int user_choice = -1;
    if (strcmp(user_input, "°¡À§") == 0) user_choice = 0;
    else if (strcmp(user_input, "¹ÙÀ§") == 0) user_choice = 1;
    else if (strcmp(user_input, "º¸") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù. ´Ù½Ã ½ÃµµÇÏ¼¼¿ä.");
=======
    // ì´ˆê¸°??
    srand(time(NULL));

    // ?€ ì¶œë ¥
    CreateOutFrame();

    // ê²Œì„ ?ˆë‚´ ì¶œë ¥
    MoveConsole(23, 2);
    printf("ì²?°œêµ¬ë¦¬ ê°€?„ë°”?„ë³´ ê²Œì„");
    MoveConsole(23, 3);
    printf("=======================");

    // ?¬ìš©???…ë ¥ ?”ì²­
    MoveConsole(23, 5);
    printf("ê°€?? ë°”ìœ„, ë³?ì¤??˜ë‚˜ë¥??…ë ¥?˜ì„¸??");
    InputWithoutTimeout(user_input, sizeof(user_input)); // ?œê°„ ?œí•œ ?†ì´ ?…ë ¥ë°›ìŒ

    // ì»´í“¨??ê²°ê³¼ ì¶œë ¥
    MoveConsole(23, 7);
    printf("ì»´í“¨?°ì˜ ? íƒ: ");
    computer_choice = rand() % 3; // ì»´í“¨??? íƒ ê²°ì •
    printf("%s", options[computer_choice]);

    // ê²°ê³¼ ê³„ì‚°
    int user_choice = -1;
    if (strcmp(user_input, "ê°€??) == 0) user_choice = 0;
    else if (strcmp(user_input, "ë°”ìœ„") == 0) user_choice = 1;
    else if (strcmp(user_input, "ë³?) == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("?˜ëª»???…ë ¥?…ë‹ˆ?? ?¤ì‹œ ?œë„?˜ì„¸??");
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

<<<<<<< HEAD
    // ¹İÀÀ ÀÔ·Â ¿äÃ» (Ä«¿îÆ®´Ù¿î ½ÃÀÛ)
    MoveConsole(23, 9);
    printf("°á°ú¿¡ µû¶ó ¹İÀÀÀ» ÀÔ·ÂÇÏ¼¼¿ä");
    MoveConsole(23, 10);
    printf("('ÀÌ°å´Ù', 'Á³´Ù', '°³±¼'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), 10)) {
        MoveConsole(23, 11);
        printf("½Ã°£ ÃÊ°ú! °ÔÀÓ ½ÇÆĞ!");
        return;
    }

    // °á°ú È®ÀÎ
    int success = 0;
    if (result == 0 && strcmp(reaction, "°³±¼") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "Á³´Ù") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "ÀÌ°å´Ù") == 0) success = 1;

    // ÃÖÁ¾ °á°ú Ãâ·Â
    MoveConsole(23, 11);
    if (success) {
        printf("Á¤´ä! ¼º°ø!");
    }
    else {
        printf("Æ²·È½À´Ï´Ù. ½ÇÆĞ!");
    }
}
/*
int main() {
    system("cls"); // È­¸é ÃÊ±âÈ­
    PlayGreenFrogRPS(); // °ÔÀÓ ½ÇÇà
    MoveConsole(23, 15);
    printf("Press any key to exit¡¦");
    getchar();
    return 0;
}
*/
=======
    // ë°˜ì‘ ?…ë ¥ ?”ì²­ (ì¹´ìš´?¸ë‹¤???œì‘)
    MoveConsole(23, 9);
    printf("ê²°ê³¼???°ë¼ ë°˜ì‘???…ë ¥?˜ì„¸??);
    MoveConsole(23, 10);
    printf("('?´ê²¼??, 'ì¡Œë‹¤', 'ê°œêµ´'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), 10)) {
        MoveConsole(23, 11);
        printf("?œê°„ ì´ˆê³¼! ê²Œì„ ?¤íŒ¨!");
        return;
    }

    // ê²°ê³¼ ?•ì¸
    int success = 0;
    if (result == 0 && strcmp(reaction, "ê°œêµ´") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "ì¡Œë‹¤") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "?´ê²¼??) == 0) success = 1;

    // ìµœì¢… ê²°ê³¼ ì¶œë ¥
    MoveConsole(23, 11);
    if (success) {
        printf("?•ë‹µ! ?±ê³µ!");
    }
    else {
        printf("?€?¸ìŠµ?ˆë‹¤. ?¤íŒ¨!");
    }
}

int main() {
    system("cls"); // ?”ë©´ ì´ˆê¸°??
    PlayGreenFrogRPS(); // ê²Œì„ ?¤í–‰
    MoveConsole(23, 15);
    printf("Press any key to exit??);
    getchar();
    return 0;
}
>>>>>>> 9bcd7fbf33c7fe15f305409ed6f520c8f9fae595
=======
#include "MOC.h"
// ì‚¬ìš©ì ì…ë ¥ í•¨ìˆ˜ (ì‹œê°„ ì œí•œ ì—†ì´)
void InputWithoutTimeout(char* input, int max_length) {
    MoveConsole(23, 10); // ì‚¬ìš©ì ì…ë ¥ ìœ„ì¹˜
    printf("                             "); // ì´ì „ ì…ë ¥ ì§€ìš°ê¸°
    MoveConsole(23, 10); // ì»¤ì„œ ìœ„ì¹˜ë¡œ ì´ë™
    fgets(input, max_length, stdin); // ì…ë ¥ ë°›ê¸°
    input[strcspn(input, "\n")] = '\0'; // ì¤„ë°”ê¿ˆ ì œê±°
}

// ì‚¬ìš©ì ì…ë ¥ í•¨ìˆ˜ (ì‹œê°„ ì œí•œ í¬í•¨, ì˜¤ë¥¸ìª½ ìƒë‹¨ ì¹´ìš´íŠ¸ë‹¤ìš´ ì¶œë ¥)
int InputWithTimeout(char* input, int max_length, int timeout) {
    int start_time = clock(); // ì‹œì‘ ì‹œê°„
    int elapsed_time = 0;

    while (elapsed_time < timeout * CLOCKS_PER_SEC) {
        // ì¹´ìš´íŠ¸ë‹¤ìš´ ì˜¤ë¥¸ìª½ ìƒë‹¨ì— ì¶œë ¥
        MoveConsole(55, 1);
        printf("ë‚¨ì€ ì‹œê°„: %2dì´ˆ", timeout - elapsed_time / CLOCKS_PER_SEC);

        if (_kbhit()) { // í‚¤ ì…ë ¥ì´ ìˆìœ¼ë©´
            MoveConsole(23, 10); // ì‚¬ìš©ì ì…ë ¥ ìœ„ì¹˜
            printf("                             "); // ì´ì „ ì…ë ¥ ì§€ìš°ê¸°
            MoveConsole(23, 10); // ì»¤ì„œ ìœ„ì¹˜ë¡œ ì´ë™
            fgets(input, max_length, stdin); // ì…ë ¥ ë°›ê¸°
            input[strcspn(input, "\n")] = '\0'; // ì¤„ë°”ê¿ˆ ì œê±°
            return 1; // ì„±ê³µì ìœ¼ë¡œ ì…ë ¥ë°›ìŒ
        }

        elapsed_time = clock() - start_time;
    }

    return 0; // ì‹œê°„ ì´ˆê³¼
}

// ì²­ê°œêµ¬ë¦¬ ê°€ìœ„ë°”ìœ„ë³´ ê²Œì„
void PlayGreenFrogRPS() {
    const char* options[] = { "ê°€ìœ„", "ë°”ìœ„", "ë³´" };
    char user_input[10];
    char reaction[10];
    int computer_choice;

    // ì´ˆê¸°í™”
    srand(time(NULL));

    // í‹€ ì¶œë ¥
    CreateOutFrame();

    // ê²Œì„ ì•ˆë‚´ ì¶œë ¥
    MoveConsole(23, 2);
    printf("ì²­ê°œêµ¬ë¦¬ ê°€ìœ„ë°”ìœ„ë³´ ê²Œì„");
    MoveConsole(23, 3);
    printf("=======================");

    // ì‚¬ìš©ì ì…ë ¥ ìš”ì²­
    MoveConsole(23, 5);
    printf("ê°€ìœ„, ë°”ìœ„, ë³´ ì¤‘ í•˜ë‚˜ë¥¼ ì…ë ¥í•˜ì„¸ìš”:");
    InputWithoutTimeout(user_input, sizeof(user_input)); // ì‹œê°„ ì œí•œ ì—†ì´ ì…ë ¥ë°›ìŒ

    // ì»´í“¨í„° ê²°ê³¼ ì¶œë ¥
    MoveConsole(23, 7);
    printf("ì»´í“¨í„°ì˜ ì„ íƒ: ");
    computer_choice = rand() % 3; // ì»´í“¨í„° ì„ íƒ ê²°ì •
    printf("%s", options[computer_choice]);

    // ê²°ê³¼ ê³„ì‚°
    int user_choice = -1;
    if (strcmp(user_input, "ê°€ìœ„") == 0) user_choice = 0;
    else if (strcmp(user_input, "ë°”ìœ„") == 0) user_choice = 1;
    else if (strcmp(user_input, "ë³´") == 0) user_choice = 2;

    if (user_choice == -1) {
        MoveConsole(23, 9);
        printf("ì˜ëª»ëœ ì…ë ¥ì…ë‹ˆë‹¤. ë‹¤ì‹œ ì‹œë„í•˜ì„¸ìš”.");
        return;
    }

    int result = (user_choice - computer_choice + 3) % 3;

    // ë°˜ì‘ ì…ë ¥ ìš”ì²­ (ì¹´ìš´íŠ¸ë‹¤ìš´ ì‹œì‘)
    MoveConsole(23, 9);
    printf("ê²°ê³¼ì— ë”°ë¼ ë°˜ì‘ì„ ì…ë ¥í•˜ì„¸ìš”");
    MoveConsole(23, 10);
    printf("('ì´ê²¼ë‹¤', 'ì¡Œë‹¤', 'ê°œêµ´'): ");

    if (!InputWithTimeout(reaction, sizeof(reaction), 10)) {
        MoveConsole(23, 11);
        printf("ì‹œê°„ ì´ˆê³¼! ê²Œì„ ì‹¤íŒ¨!");
        return;
    }

    // ê²°ê³¼ í™•ì¸
    int success = 0;
    if (result == 0 && strcmp(reaction, "ê°œêµ´") == 0) success = 1;
    else if (result == 1 && strcmp(reaction, "ì¡Œë‹¤") == 0) success = 1;
    else if (result == 2 && strcmp(reaction, "ì´ê²¼ë‹¤") == 0) success = 1;

    // ìµœì¢… ê²°ê³¼ ì¶œë ¥
    MoveConsole(23, 11);
    if (success) {
        printf("ì •ë‹µ! ì„±ê³µ!");
    }
    else {
        printf("í‹€ë ¸ìŠµë‹ˆë‹¤. ì‹¤íŒ¨!");
    }
}

int main() {
    system("cls"); // í™”ë©´ ì´ˆê¸°í™”
    PlayGreenFrogRPS(); // ê²Œì„ ì‹¤í–‰
    MoveConsole(23, 15);
    printf("Press any key to exitâ€¦");
    getchar();
    return 0;
}
>>>>>>> 6b6dc2e5789f4ced41a5bf33db9cfc72028a3f0c
