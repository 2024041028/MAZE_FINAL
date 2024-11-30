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
	CreateOutFrame();
}


void FinishGame() {
	ScreenReset();
	SetColor(7);

	MoveConsole(23, 6);
	printf("﹥﹥﹥﹥﹥");
	MoveConsole(23, 7);
	printf("  ﹥");
	MoveConsole(23, 8);
	printf("  ﹥");
	MoveConsole(23, 9);
	printf("  ﹥");
	MoveConsole(23, 10);
	printf("  ﹥");

	MoveConsole(30, 6);
	printf("﹥   ﹥");
	MoveConsole(30, 7);
	printf("﹥   ﹥");
	MoveConsole(30, 8);
	printf("﹥﹥﹥﹥﹥");
	MoveConsole(30, 9);
	printf("﹥   ﹥");
	MoveConsole(30, 10);
	printf("﹥   ﹥");

	MoveConsole(37, 6);
	printf(" ﹥﹥﹥");
	MoveConsole(37, 7);
	printf("﹥   ﹥");
	MoveConsole(37, 8);
	printf("﹥﹥﹥﹥﹥");
	MoveConsole(37, 9);
	printf("﹥   ﹥");
	MoveConsole(37, 10);
	printf("﹥   ﹥");

	MoveConsole(44, 6);
	printf("﹥   ﹥");
	MoveConsole(44, 7);
	printf("﹥﹥  ﹥");
	MoveConsole(44, 8);
	printf("﹥ ﹥ ﹥");
	MoveConsole(44, 9);
	printf("﹥  ﹥﹥");
	MoveConsole(44, 10);
	printf("﹥   ﹥");

	MoveConsole(51, 6);
	printf("﹥   ﹥");
	MoveConsole(51, 7);
	printf("﹥  ﹥");
	MoveConsole(51, 8);
	printf("﹥﹥﹥");
	MoveConsole(51, 9);
	printf("﹥  ﹥");
	MoveConsole(51, 10);
	printf("﹥   ﹥");

	MoveConsole(43, 13);
	printf("﹥   ﹥");
	MoveConsole(43, 14);
	printf(" ﹥ ﹥");
	MoveConsole(43, 15);
	printf("  ﹥");
	MoveConsole(43, 16);
	printf("  ﹥");
	MoveConsole(43, 17);
	printf("  ﹥");

	MoveConsole(49, 13);
	printf("  ﹥﹥﹥");
	MoveConsole(49, 14);
	printf(" ﹥   ﹥");
	MoveConsole(49, 15);
	printf("﹥     ﹥");
	MoveConsole(49, 16);
	printf(" ﹥   ﹥");
	MoveConsole(49, 17);
	printf("  ﹥﹥﹥");

	MoveConsole(58, 13);
	printf("﹥    ﹥");
	MoveConsole(58, 14);
	printf("﹥    ﹥");
	MoveConsole(58, 15);
	printf("﹥    ﹥");
	MoveConsole(58, 16);
	printf("﹥    ﹥");
	MoveConsole(58, 17);
	printf("  ﹥﹥");


	MoveConsole(0, 26);
	printf(" ");
	exit(0);
}