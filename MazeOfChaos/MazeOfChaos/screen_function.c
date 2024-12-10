#include "MOC.h"

void CreateOutFrame(int x) {
	SetColor(x);
	MoveConsole(20, 0);
	for (int i = 0; i < 25; i++) {
		if (i == 0)
			printf("┏━");
		printf("━━");
		if (i == 24)
			printf("━┓");
	}
	for (int i = 0; i < 24; i++) {
		MoveConsole(20, i + 1);
		printf("┃ ");
		MoveConsole(72, i + 1);
		printf(" ┃");
	}
	MoveConsole(20, 24);
	for (int i = 0; i < 25; i++) {
		if (i == 0)
			printf("┗━");
		printf("━━");
		if (i == 24)
			printf("━┛");
	}
}

void ScreenReset(int x) {
	system("cls");
	CreateOutFrame(x);
}


void FinishGame() {
	ScreenReset(14);
	SetColor(7);

	MoveConsole(23, 6);
	printf("■■■■■");
	MoveConsole(23, 7);
	printf("  ■");
	MoveConsole(23, 8);
	printf("  ■");
	MoveConsole(23, 9);
	printf("  ■");
	MoveConsole(23, 10);
	printf("  ■");

	MoveConsole(30, 6);
	printf("■   ■");
	MoveConsole(30, 7);
	printf("■   ■");
	MoveConsole(30, 8);
	printf("■■■■■");
	MoveConsole(30, 9);
	printf("■   ■");
	MoveConsole(30, 10);
	printf("■   ■");

	MoveConsole(37, 6);
	printf(" ■■■");
	MoveConsole(37, 7);
	printf("■   ■");
	MoveConsole(37, 8);
	printf("■■■■■");
	MoveConsole(37, 9);
	printf("■   ■");
	MoveConsole(37, 10);
	printf("■   ■");

	MoveConsole(44, 6);
	printf("■   ■");
	MoveConsole(44, 7);
	printf("■■  ■");
	MoveConsole(44, 8);
	printf("■ ■ ■");
	MoveConsole(44, 9);
	printf("■  ■■");
	MoveConsole(44, 10);
	printf("■   ■");

	MoveConsole(51, 6);
	printf("■   ■");
	MoveConsole(51, 7);
	printf("■  ■");
	MoveConsole(51, 8);
	printf("■■■");
	MoveConsole(51, 9);
	printf("■  ■");
	MoveConsole(51, 10);
	printf("■   ■");

	MoveConsole(43, 13);
	printf("■   ■");
	MoveConsole(43, 14);
	printf(" ■ ■");
	MoveConsole(43, 15);
	printf("  ■");
	MoveConsole(43, 16);
	printf("  ■");
	MoveConsole(43, 17);
	printf("  ■");

	MoveConsole(49, 13);
	printf("  ■■■");
	MoveConsole(49, 14);
	printf(" ■   ■");
	MoveConsole(49, 15);
	printf("■     ■");
	MoveConsole(49, 16);
	printf(" ■   ■");
	MoveConsole(49, 17);
	printf("  ■■■");

	MoveConsole(58, 13);
	printf("■    ■");
	MoveConsole(58, 14);
	printf("■    ■");
	MoveConsole(58, 15);
	printf("■    ■");
	MoveConsole(58, 16);
	printf("■    ■");
	MoveConsole(58, 17);
	printf("  ■■");


	MoveConsole(0, 26);
	printf(" ");
	exit(0);
}


void FillEntireFrameRandomly(int x,int xx,int y) {

	int c = 1;
	int cnt = 0;
	while (1) {
		MoveConsole(xx, y);
		SetColor(c);
		printf("%s", now_skin);
		Sleep(10);
		c++;
		if (c == 10)
			c = 0;
		cnt++;

		if (cnt == 45) {
			MoveConsole(xx, y);
			SetColor(x);
			printf("%s", now_skin);
			Sleep(500);
			break;
		}
	}
	int positions[27 * 25][2];
	int count = 0;

	for (int y = 0; y < 25; y += 2) { // y 좌표는 2씩 증가 (두 줄 간격)
		for (int x = 0; x < 14; x++) {
			positions[count][0] = 19 + x * 4; // x 좌표는 동일
			positions[count][1] = y;         // y 좌표 저장
			count++;
		}
	}

	srand(time(NULL));
	int filled = 0;
	float t = 200;
	SetColor(x);
	while (filled < count) {
		int index = rand() % count;
		if (positions[index][0] != -1) {
			// 첫 번째 줄 출력
			MoveConsole(positions[index][0], positions[index][1]);
			printf("▒▒▒▒");
			// 두 번째 줄 출력
			MoveConsole(positions[index][0], positions[index][1] + 1);
			printf("▒▒▒▒");

			// 위치를 사용된 것으로 표시
			positions[index][0] = -1;
			filled++;
			if (filled == 10) {
				t = 50;
			}
			else if (filled == 25) {
				t = 1.0;
			}
			Sleep(t);
		}
	}
	Sleep(500);
	ScreenReset(x);
}
