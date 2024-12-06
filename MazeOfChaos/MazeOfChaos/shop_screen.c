#include "MOC.h"

char skin_list[20][10] = { "X","※", "★", "♥", "♣", "♠", "◆", "▲", "♪", "♬", "◈", "▣", "⊙", "?", "℡", "φ", "Ψ", "Ø", "Ω","@" };

int ShopScreen() {

	ScreenReset();

	Donate();

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
	printf("현재 스킨 : %s", now_skin);
	MoveConsole(22, 4);
	printf("코인 : %d", user_coin);

	SetColor(11);
	MoveConsole(22, 6);
	printf("<Skin List>");
	SkinPage1();

	int y = 0, skin_num = 1;
	int prex = 0, prey = 0;
	int flag = 1;
	while (1) {
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (flag == 1 && y == 0) {
				continue;
			}
			else {
				y--;
				skin_num--;
			}
			if (y == -1 && flag == 2) {
				SkinPage1();
				y = 9;
				flag = 1;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (flag == 2 && y == 9) {
				continue;
			}
			else {
				y++;
				skin_num++;
			}

			if (y == 10 && flag == 1) {
				SkinPage2();
				y = 0;
				flag = 2;
			}
		}

		else if (GetAsyncKeyState(VK_BACK) & 0x8000) {
			MenuScreen();
			return 0;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (user_skin[skin_num] == 0) {
				Sleep(150);
				BuySkin(skin_num);
			}
			else if (user_skin[skin_num] == 1) {
				strcpy(now_skin, skin_list[skin_num - 1]);
				MoveConsole(22, 3);
				printf("현재 스킨 : %s", now_skin);
			}
		}
		if (flag == 1) {
			if (user_skin[y + 1] == 1) {// 보유할때
				SetColor(7);
				MoveConsole(prex - 1, prey);
				printf("      ");
				MoveConsole(26, 9 + y);
				printf("◀");
				prex = 26;
				prey = 9 + y;
			}
			else if (user_skin[y + 1] == 0) {
				SetColor(7);
				MoveConsole(prex - 1, prey);
				printf("      ");
				MoveConsole(32, 9 + y);
				printf("◀");
				prex = 32;
				prey = 9 + y;
			}
		}
		else if (flag == 2) {
			if (user_skin[y + 11] == 1) {// 보유할때
				SetColor(7);
				MoveConsole(prex - 1, prey);
				printf("      ");
				MoveConsole(26, 9 + y);
				printf("◀");
				prex = 26;
				prey = 9 + y;
			}
			else if (user_skin[y + 11] == 0) {
				SetColor(7);
				MoveConsole(prex - 1, prey);
				printf("      ");
				MoveConsole(32, 9 + y);
				printf("◀");
				prex = 32;
				prey = 9 + y;
			}
		}
		Sleep(80);
	}
	Sleep(100000);
}

void SkinPage1() {
	ResetSkinPage();
	int cnt = 1;
	for (int i = 0; i < 10; i++) { // 20개  // 10개만 
		MoveConsole(23, 9 + i);
		SetColor(7);
		printf("%s", skin_list[i]);
		if (user_skin[cnt] == 0) {
			SetColor(4);
			printf(" *잠금*");
		}
		cnt++;
	}
	MoveConsole(26, 19);
	SetColor(7);
	printf("↓");
	return 0;
}

void SkinPage2() {
	ResetSkinPage();
	int cnt = 10;
	for (int i = 0; i < 10; i++) { // 20개  // 10개만 
		MoveConsole(23, 9 + i);
		SetColor(7);
		printf("%s", skin_list[cnt]);
		if (user_skin[cnt + 1] == 0) {
			SetColor(4);
			printf(" *잠금*");
		}
		cnt++;
	}
	MoveConsole(26, 8);
	SetColor(7);
	printf("↑");
	return 0;
}

void ResetSkinPage() {
	for (int i = 0; i < 12; i++) {
		MoveConsole(23, 8 + i);
		printf("                  ");
	}
	return 0;
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
			if (flag == 0 && user_coin>=5) {
				user_skin[skin_num] = 1;
				user_coin -= 5;
				MoveConsole(22, 4);
				printf("코인 : %d", user_coin);
				UpdateUserInfo();
			}
			else if (flag == 0 && user_coin < 5) {
				MoveConsole(46, 7);
				SetColor(4);
				printf("※ 골드가 부족합니다! ※");
				Sleep(2000);
			}
			MoveConsole(46, 7);
			printf("                          ");
			Sleep(100);
			return 0;
		}
	}
}

void Donate() {
	
	SetColor(7);
	MoveConsole(42, 10);
	printf("[상점 안내]");
	MoveConsole(42, 11);
	printf("스킨은 순수한 장식용입니다.");
	MoveConsole(42, 12);
	printf("마음에 드는 스킨을 선택하세요!");

	SetColor(7);
	MoveConsole(42, 14);
	printf("후원은 게임 개발에 큰 도움을");
	MoveConsole(42, 15);
	printf("줍니다.");
	SetColor(8);
	printf(" 그리고 가끔 야식..");
	SetColor(7);
	MoveConsole(42, 17);
	printf("토스뱅크 1000-9085-0365");
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