#include "MOC.h"

char user_name[20];

void MenuScreenFrame() {
	CreateOutFrame();
	SetColor(7);
	MoveConsole(22, 2);
	printf("Name : %s", user_name);

	MoveConsole(61, 2);
	printf("早 鼻薄 P  早");
	MoveConsole(61, 1);
	printf("旨收收收收收收收收收旬");
	MoveConsole(61, 3);
	printf("曲收收收收收收收收收旭");

	SetColor(13);
	MoveConsole(36, 5);
	printf("旨收收收收收收收收收收收收收收收收收收收收旬");

	for (int i = 0; i < 10; i++) {
		MoveConsole(36, i + 6);
		printf("早");
		MoveConsole(57, i + 6);
		printf("早");
	}

	MoveConsole(36, 16);
	printf("曲收收收收收收收收收收收收收收收收收收收收旭");
	SetColor(7);
	MoveConsole(36, 17);
	printf("1. ");
	MoveConsole(36, 18);
	printf("2. ");
	MoveConsole(36, 19);
	printf("3. ");
	MoveConsole(36, 20);
	printf("4. ");
	MoveConsole(36, 21);
	printf("5. ");
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
	}
}

int ShopScreen() {

}

void MenuScreen() {
	int flag = 1;
	ScreenReset();
	MenuScreenFrame();
	Sleep(100);
	while (1) {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && flag != 5) {
			ScreenReset();
			MenuScreenFrame();
			flag++;
			Sleep(110);
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && flag != 1) {
			ScreenReset();
			MenuScreenFrame();
			flag--;
			Sleep(110);
		}
		else if (GetAsyncKeyState(0x50) & 0x8000) {
			ShopScreen();
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			return 0;
		}
		Level(flag);
	}
}