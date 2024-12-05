#include "MOC.h"

char skin_list[20][10] = { "X","※", "★", "♥", "♣", "♠", "◆", "▲", "♪", "♬", "◈", "▣", "⊙", "?", "℡", "φ", "Ψ", "Ø", "Ω","@" };

int ShopScreen() {
	ScreenReset();
	SetColor(7);
	MoveConsole(59, 2);
	printf("┃뒤로가기 ☜ ┃");
	MoveConsole(59, 1);
	printf("┏━━━━━━━━━━━┓");
	MoveConsole(59, 3);
	printf("┗━━━━━━━━━━━┛");

	MoveConsole(22, 2);
	printf("Name : %s", user_name);
	MoveConsole(22, 3);
	printf("현재 스킨 : %c", now_skin);
	MoveConsole(22, 4);
	printf("코인 : %d", user_coin);

	SetColor(11);
	MoveConsole(22, 7);
	printf("<Skin List>");

	int cnt = 1;

	for (int i = 0; i < 10; i++) { // 20개 
		MoveConsole(23, 9 + i);
		SetColor(7);
		printf("%s", skin_list[i]);
		if (user_skin[cnt] == 0) {
			SetColor(4);
			printf(" *잠금*");
		}
		cnt++;
	}
	int y = 0, skin_num = 1;
	int prex = 0, prey = 0;
	while (1) {
		if (GetAsyncKeyState(VK_UP) & 0x8000 && y != 0) {
			y--;
			skin_num--;

		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && y != 9) {
			y++;
			skin_num++;

		}
		else if (GetAsyncKeyState(VK_BACK) & 0x8000) {
			MenuScreen();
			return 0;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (user_skin[skin_num] == 0) {
				BuySkin(skin_num);
			}
		}

		if (user_skin[y + 1] == 1) {// 보유할때
			SetColor(7);
			MoveConsole(prex-1, prey);
			printf("      ");
			MoveConsole(26, 9 + y);
			printf("◀");
			prex = 26;
			prey = 9 + y;
		}
		else if (user_skin[y + 1] == 0) {
			SetColor(7);
			MoveConsole(prex-1, prey);
			printf("      ");
			MoveConsole(32, 9 + y);
			printf("◀");
			prex = 32;
			prey = 9 + y;
		}
		Sleep(80);
	}
	Sleep(100000);
}


int BuySkin(int skin_num) {
	int flag = 0;
	MoveConsole(49, 6);
	SetColor(4);
	printf("※ 5골드 소모 ※");
	MoveConsole(47, 7);
	SetColor(11);
	printf("구매하시겠습니까?");
	SetColor(7);
	MoveConsole(51, 8);
	printf("Yes");
	SetColor(8);
	MoveConsole(57, 8);
	printf("No");
	Sleep(100);
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			SetColor(7);
			MoveConsole(51, 8);
			printf("Yes");
			SetColor(8);
			MoveConsole(57, 8);
			printf("No");
			flag = 0;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			SetColor(8);
			MoveConsole(51, 8);
			printf("Yes");
			SetColor(7);
			MoveConsole(57, 8);
			printf("No");
			flag = 1;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			MoveConsole(49, 6);
			printf("               ");
			MoveConsole(47, 7);
			printf("                      ");
			SetColor(7);
			MoveConsole(47, 8);
			printf("                  ");
			if (flag == 0) {
				user_skin[skin_num] = 1;
			}
			Sleep(100);
			return 0;
		}
	}
}

/*  color_num 색깔
0: Black
1 : Blue
2 : Green
3 : Aqua
4 : Red
5 : Purple
6 : Yellow
7 : White
8 : Gray
9 : Light Blue
10 (A) : Light Green
11 (B) : Light Aqua
12 (C) : Light Red
13 (D) : Light Purple
14 (E) : Light Yellow
15 (F) : Bright White
*/