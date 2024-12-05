#include "MOC.h"

int user_record[6]; // 1 2 3 4 5 단계 기록
int user_skin[18]; // 1 2 3... 11 스킨
int user_coin;
char user_name[20];
int now_level;

int maze_size;
char player_skin;
int player_x, player_y; //state1에서의 플레이어 위치
int x, y; //플레이어 이동을 감지
int x_0, y_0; //state의 (0,0)의 콘솔 위치를 나타낼 값
int h = 0; //하트 개수
int skip = 0; //스킵권 개수
int coin = 0; //코인 개수

void maze1() {
	int state1[10][10] = { //앞의 항이 y값, 뒤의 항이 x값
	{0,1,4,1,2},
	{0,1,0,1,0},
	{0,0,0,1,0},
	{1,1,0,0,0},
	{5,0,0,1,6}
	};
	x_0 = 43; y_0 = 10; //(0,0)의 콘솔 위치
	
	SetColor(7);
	MoveConsole(76, 2);
	printf("하트 개수:%d",h);
	MoveConsole(76, 3);
	printf("스킵권 개수:%d", skip);
	MoveConsole(76, 4);
	printf("코인 개수:%d", coin);
	SetColor(4);  //미로 틀
	MoveConsole(40, 9);
	printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	for (int i = 10; i <= 14; i++) {
		MoveConsole(40, i);
		printf("▒▒           ▒▒");
	}
	MoveConsole(40, 15);
	printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");

	SetColor(8); //암흑 시야
	for (int i = 10; i <= 14; i++) {
		MoveConsole(43, i);
		printf("■ ■ ■ ■ ■ ");
	}
	SetColor(7);
	player_x = 0; player_y = 0; x = 0; y = 0; player_skin = 'x'; //플레이어 초기 위치
	while (1) {
		if (GetAsyncKeyState(VK_UP) && player_y > 0) y = -1;
		else if (GetAsyncKeyState(VK_DOWN) && player_y < 4) y = 1;
		else if (GetAsyncKeyState(VK_LEFT) && player_x > 0) x = -1;
		else if (GetAsyncKeyState(VK_RIGHT) && player_x < 4) x = 1;

		if (state1[player_x + x][player_y + y] == 0) { //통로
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c",  player_skin);
		}
		else if (state1[player_x + x][player_y + y] == 1) { //벽
			MoveConsole(x_0 + player_x * 2 + x * 2, y_0 + player_y + y);
			printf("▒");
			x = 0; y = 0;
		}
		else if (state1[player_x + x][player_y + y] == 2) { //출구
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c", player_skin);
			MoveConsole(0, 0);
			printf("미로 탈출 성공!");
			break;
		}
		else if (state1[player_x + x][player_y + y] == 4) { //하트 획득
			h++;
			state1[player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c", player_skin);
			MoveConsole(76, 2);
			printf("하트 개수:%d",h);
		}
		else if (state1[player_x + x][player_y + y] == 5) { //스킵권 획득
			skip++;
			state1[player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c", player_skin);
			MoveConsole(76, 3);
			printf("스킵권 개수:%d", skip);
		}
		else if (state1[player_x + x][player_y + y] == 6) { //코인 획득
			coin++;
			state1[player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c", player_skin);
			MoveConsole(76, 4);
			printf("코인 개수:%d", coin);
		}
		Sleep(100);
	}
}

void maze_game() {
	now_level = 1;
	ScreenReset();
	MoveConsole(22, 2);
	strcpy(user_name, "kbg");
	printf("Name : %s", user_name);

	MoveConsole(59, 2);
	printf("┃뒤로가기 ☜ ┃");
	MoveConsole(59, 1);
	printf("┏━━━━━━━━━━━┓");
	MoveConsole(59, 3);
	printf("┗━━━━━━━━━━━┛");

	if (now_level == 1)maze1();

	MoveConsole(0, 20);
}