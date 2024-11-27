#include "MOC.h"

void CreateOutFrame() {
	SetColor(14);
	MoveConsole(20, 0);
	for (int i = 0; i < 25; i++) {
		if (i == 0)
			printf("旨收");
		printf("收收");
		if (i == 24)
			printf("收旬");
	}
	for (int i = 0; i < 24; i++) {
		MoveConsole(20, i + 1);
		printf("早 ");
		MoveConsole(72, i + 1);
		printf(" 早");
	}
	MoveConsole(20, 24);
	for (int i = 0; i < 25; i++) {
		if (i == 0)
			printf("曲收");
		printf("收收");
		if (i == 24)
			printf("收旭");
	}
}

void ScreenReset() {
	system("cls");
	OutFrame();
}


void FinishGame() {
	ScreenReset();
	SetColor(7);
	MoveConsole(0, 35);
	exit(0);
}