#include "MOC.h"

char now_skin[10] = "X";
 // ※ ★ ♥ ♣ ♠ ◆ ▲ ♪ ♬ ◈ ▣ ⊙ ? ℡ φ Ψ Ø Ω

struct rank {
	char name[20];
	int record;
	struct rank* next;
}*pre, * cur, * first, * new;

void ranking(int level) {
	char name[20];
	int record = 0;
	int i;
	first = NULL;
	FILE* fp_ranking = fopen("Record.txt", "r");
	while (fscanf(fp_ranking, "%s", name) != EOF) {
		struct rank* new = malloc(sizeof(struct rank));
		strcpy(new->name, name); //유저 이름 입력
		for (i = 0; i < 26; i++) { //유저별 기록 입력
			fscanf(fp_ranking, "%d", &record);
			if (record == 0)break;
			if (i == level) {
				new->record = record;
				new->next = NULL;
				if (first == NULL)first = new;
				else {
					cur = first;
					while (cur != NULL && cur->record < record) {
						pre = cur;
						cur = cur->next;
					}
					if (cur == first) {
						new->next = cur;
						first = new;
					}
					else {
						pre->next = new;
						new->next = cur;
					}
				}
			}
		}
	}
	fclose(fp_ranking);
}

void MenuScreenFrame(int level) {
	CreateOutFrame();
	SetColor(7);
	MoveConsole(22, 2);
	printf("Name : %s", user_name);
	MoveConsole(22, 3);
	printf("현재 스킨 : %s", now_skin);

	MoveConsole(61, 2);
	printf("┃ 상점 P  ┃");
	MoveConsole(61, 1);
	printf("┏━━━━━━━━━┓");
	MoveConsole(61, 3);
	printf("┗━━━━━━━━━┛");

	SetColor(13);
	MoveConsole(36, 5);
	printf("┏━━━━━━━━━━━━━━━━━━━━┓");

	for (int i = 0; i < 10; i++) {
		MoveConsole(36, i + 6);
		printf("┃");
		MoveConsole(57, i + 6);
		printf("┃");
	}

	MoveConsole(36, 16);
	printf("┗━━━━━━━━━━━━━━━━━━━━┛");

	ranking(level);
	SetColor(7);
	cur = first;
	int i = 0;
	/*for (i = 0; i < 5; i++) {
		if (cur == NULL)break;
		MoveConsole(36, 17 + i);
		printf("%d. %s %d", i + 1,cur->name, cur->record);
		cur = cur->next;
	}*/
	for (int j = i; j < 5; j++) {
		MoveConsole(36, 17 + j);
		printf("%d.", j + 1);
	}
	MoveConsole(0, 0);
}


void Level(int level) {
	SetColor(7);
	if (level == 1) {
		MoveConsole(41, 6);
		printf("      111  ");
		MoveConsole(41, 7);
		printf("    11 11  ");
		MoveConsole(41, 8);
		printf("   11  11  ");
		MoveConsole(41, 9);
		printf("  11   11  ");
		MoveConsole(41, 10);
		printf("       11  ");
		MoveConsole(41, 11);
		printf("       11  ");
		MoveConsole(41, 12);
		printf("       11  ");
		MoveConsole(41, 13);
		printf("       11  ");
		MoveConsole(41, 14);
		printf("       11 ");
		MoveConsole(41, 15);
		printf(" 1111111111111");

		MoveConsole(61, 9);
		printf("     ▒▒");
		MoveConsole(61, 10);
		printf("       ▒▒");
		MoveConsole(61, 11);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		MoveConsole(61, 12);
		printf("       ▒▒");
		MoveConsole(61, 13);
		printf("     ▒▒");

		if (user_record[1] == 0) {
			SetColor(12);
			MoveConsole(61, 15);
			printf(" ※ 잠금 ※");
		}
	}
	else if (level == 2) {
		MoveConsole(41, 6);
		printf("   222222  ");
		MoveConsole(41, 7);
		printf(" 22      22 ");
		MoveConsole(41, 8);
		printf("22        22");
		MoveConsole(41, 9);
		printf("        22");
		MoveConsole(41, 10);
		printf("      22 ");
		MoveConsole(41, 11);
		printf("     22  ");
		MoveConsole(41, 12);
		printf("   22  ");
		MoveConsole(41, 13);
		printf(" 22  ");
		MoveConsole(41, 14);
		printf("22  ");
		MoveConsole(41, 15);
		printf("222222222222");

		MoveConsole(22, 9);
		printf("    ▒▒");
		MoveConsole(22, 10);
		printf("  ▒▒");
		MoveConsole(22, 11);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		MoveConsole(22, 12);
		printf("  ▒▒");
		MoveConsole(22, 13);
		printf("    ▒▒");

		MoveConsole(61, 9);
		printf("     ▒▒");
		MoveConsole(61, 10);
		printf("       ▒▒");
		MoveConsole(61, 11);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		MoveConsole(61, 12);
		printf("       ▒▒");
		MoveConsole(61, 13);
		printf("     ▒▒");

		if (user_record[2] == 0) {
			SetColor(12);
			MoveConsole(61, 15);
			printf(" ※ 잠금 ※");
		}
	}
	else if (level == 3) {
		MoveConsole(41, 7);
		printf("  333333333  ");
		MoveConsole(41, 8);
		printf(" 33       33");
		MoveConsole(41, 9);
		printf("33         33");
		MoveConsole(41, 10);
		printf("          33 ");
		MoveConsole(41, 11);
		printf("      3333 ");
		MoveConsole(41, 12);
		printf("          33 ");
		MoveConsole(41, 13);
		printf("33         33");
		MoveConsole(41, 14);
		printf(" 33       33");
		MoveConsole(41, 15);
		printf("  333333333  ");

		MoveConsole(22, 9);
		printf("    ▒▒");
		MoveConsole(22, 10);
		printf("  ▒▒");
		MoveConsole(22, 11);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		MoveConsole(22, 12);
		printf("  ▒▒");
		MoveConsole(22, 13);
		printf("    ▒▒");

		MoveConsole(61, 9);
		printf("     ▒▒");
		MoveConsole(61, 10);
		printf("       ▒▒");
		MoveConsole(61, 11);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		MoveConsole(61, 12);
		printf("       ▒▒");
		MoveConsole(61, 13);
		printf("     ▒▒");

		if (user_record[3] == 0) {
			SetColor(12);
			MoveConsole(61, 15);
			printf(" ※ 잠금 ※");
		}
	}
	else if (level == 4) {
		MoveConsole(41, 6);
		printf("      444  ");
		MoveConsole(41, 7);
		printf("    44 44  ");
		MoveConsole(41, 8);
		printf("   44  44  ");
		MoveConsole(41, 9);
		printf("  44   44  ");
		MoveConsole(41, 10);
		printf(" 44    44  ");
		MoveConsole(41, 11);
		printf("44444444444444");
		MoveConsole(41, 12);
		printf("       44  ");
		MoveConsole(41, 13);
		printf("       44  ");
		MoveConsole(41, 14);
		printf("       44 ");
		MoveConsole(41, 15);
		printf("       44");
		MoveConsole(22, 9);

		printf("    ▒▒");
		MoveConsole(22, 10);
		printf("  ▒▒");
		MoveConsole(22, 11);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		MoveConsole(22, 12);
		printf("  ▒▒");
		MoveConsole(22, 13);
		printf("    ▒▒");

		MoveConsole(61, 9);
		printf("     ▒▒");
		MoveConsole(61, 10);
		printf("       ▒▒");
		MoveConsole(61, 11);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		MoveConsole(61, 12);
		printf("       ▒▒");
		MoveConsole(61, 13);
		printf("     ▒▒");

		if (user_record[4] == 0) {
			SetColor(12);
			MoveConsole(61, 15);
			printf(" ※ 잠금 ※");
		}
	}
	else if (level == 5) {
		MoveConsole(41, 6);
		printf("55555555555");
		MoveConsole(41, 7);
		printf("55        ");
		MoveConsole(41, 8);
		printf("55");
		MoveConsole(41, 9);
		printf("55555555");
		MoveConsole(41, 10);
		printf("       555");
		MoveConsole(41, 11);
		printf("         55");
		MoveConsole(41, 12);
		printf("          55");
		MoveConsole(41, 13);
		printf("         55");
		MoveConsole(41, 14);
		printf("55      55");
		MoveConsole(41, 15);
		printf(" 55555555");

		MoveConsole(22, 9);
		printf("    ▒▒");
		MoveConsole(22, 10);
		printf("  ▒▒");
		MoveConsole(22, 11);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		MoveConsole(22, 12);
		printf("  ▒▒");
		MoveConsole(22, 13);
		printf("    ▒▒");
	}
}


void MenuScreen() {
	int flag = 1;
	int max_level = 1;
	for (int i = 1; i <= 5; i++) {
		if (user_record[i] == 0) {
			max_level = i;
			break;
		}
		else if (i == 5) {
			max_level = 5;
		}
	}
	ScreenReset();
	MenuScreenFrame(flag);
	Sleep(100);
	while (1) {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && flag != 5 && flag < max_level) {
			ScreenReset();
			MenuScreenFrame(flag);
			flag++;
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && flag != 1) {
			ScreenReset();
			MenuScreenFrame(flag);
			flag--;
			Sleep(150);
		}
		else if (GetAsyncKeyState(0x50) & 0x8000) {
			ScreenReset();
			ShopScreen();
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			RemoveGarbageChar();
			now_level = flag;
			maze_game();
			MenuScreenFrame(flag);
			for (int i = 1; i <= 5; i++) {
				if (user_record[i] == 0) {
					max_level = i;
					break;
				}
				else if (i == 5) {
					max_level = 5;
				}
			}

		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			FinishGame();
		}

		Level(flag);
	}
}