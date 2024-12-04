#include "MOC.h"

int user_record[6]; // 1 2 3 4 5 단계 기록
int user_skin[12]; // 1 2 3... 11 스킨
int user_coin;
char user_name[20];
int now_level;

int maze_size;
int player_x;
int player_y;
char player_skin;
int x;
int y;
int x_0 = 43;
int y_0 = 10;


void maze1() {
	int state1[10][10] = {
	{0,1,4,1,8},
	{0,1,0,1,0},
	{0,0,0,1,0},
	{1,1,0,0,0},
	{5,0,0,1,6}
	};
	SetColor(4);
	MoveConsole(40, 9);
	printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	for (int i = 10; i <= 14; i++) {
		MoveConsole(40, i);
		printf("▒▒           ▒▒");
	}
	MoveConsole(40, 15);
	printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");

	SetColor(8);
	for (int i = 10; i <= 14; i++) {
		MoveConsole(42, i);
		printf(" ■ ■ ■ ■ ■ ");
	}
	SetColor(7);
	player_x = 0; player_y = 0; player_skin = 'x';
	MoveConsole(x_0 + player_x, y_0 + player_y);
	printf("%c ",player_skin);
	x = 0; y = 0;
	while (1) {
		if ((GetAsyncKeyState(VK_UP) & 0x8000) && player_y > 0) y = -1;
		else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && player_y < 5) y = 1;
		else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && player_x > 0) x = -1;
		else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && player_x < 5) x = 1;			
		
		/*MoveConsole(0, 0);
		printf("%d %d", player_y - 10 + y, player_x - 43 + (x / 2));
		MoveConsole(player_x, player_y);
		printf("  ");
		player_x += x;
		player_y += y;
		x = 0;
		y = 0;
		MoveConsole(player_x, player_y);
		printf("%c", player_skin);*/

		Sleep(110);
	}
}

void maze_game() {
	now_level = 1;
	ScreenReset();
	MoveConsole(22, 2);
	printf("Name : %s", user_name);

	MoveConsole(59, 2);
	printf("┃뒤로가기 ☜ ┃");
	MoveConsole(59, 1);
	printf("┏━━━━━━━━━━━┓");
	MoveConsole(59, 3);
	printf("┗━━━━━━━━━━━┛");

	if (now_level == 1)maze1();

	for (int i = 0; i < 12; i++) {
		printf("\n");
	}
}