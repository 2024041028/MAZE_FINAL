#include "MOC.h"

void CreateOutFrame() {
	SetColor(14);
	MoveConsole(20, 0);
	for (int i = 0; i < 25; i++) {
		if (i == 0)
			printf("����");
		printf("����");
		if (i == 24)
			printf("����");
	}
	for (int i = 0; i < 24; i++) {
		MoveConsole(20, i + 1);
		printf("�� ");
		MoveConsole(72, i + 1);
		printf(" ��");
	}
	MoveConsole(20, 24);
	for (int i = 0; i < 25; i++) {
		if (i == 0)
			printf("����");
		printf("����");
		if (i == 24)
			printf("����");
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