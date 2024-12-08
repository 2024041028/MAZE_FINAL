#include "MOC.h"


int maze_size;
int player_x, player_y; //state에서의 플레이어 위치
int x, y; //플레이어 이동을 감지
int x_0, y_0; //state의 (0,0)의 콘솔 위치를 나타낼 값
int h = 3; //하트 개수
int skip = 0; //스킵권 개수
int coin = 0; //코인 개수
int key = 0;
int line = 0;
int minigame_prob;
char inform[100][100];

void minigame_pop() {
	int random = 0;
	random = rand() % 6;
	FillEntireFrameRandomly(random);
	switch (random) {
	case 0:
		random_number();
		break;
	case 1:
		PlayHangman();
		break;
	case 2:
		PlayMemoryGame();
		break;
	case 3:
		PlayGreenFrogRPS();
		break;
	case 4:
		PlayAscendingGame();
		break;
	case 5:
		PlayTriviaQuizGame();
		break;
	//case 6:
	//	
	//	break;
	//case 7:

	//	break;
	//case 8:

	//	break;
	}
	/*if (미니게임 실패) {
		h--;
	}*/
	ScreenReset();
	maze_frame();
}

int state[5][10][10] = {
	{//level 1
		{9,1,4,1,2},
		{0,1,0,1,0},
		{0,0,0,1,0},
		{1,1,0,0,0},
		{5,0,0,1,6}
},
	{//level 2
		{9,0,0,0,1,0,0,0},
		{1,1,1,0,1,0,1,5},
		{0,0,0,0,1,0,1,1},
		{0,1,1,0,0,0,0,6},
		{0,6,1,0,1,1,1,1},
		{1,1,1,0,0,0,0,0},
		{4,0,1,0,1,1,1,0},
		{1,0,0,0,1,2,0,0}
},
	{//level 3
		{9,0,0,0,0,0,1,6},
		{0,1,1,1,1,0,0,0},
		{0,1,0,0,0,1,0,1},
		{0,0,0,1,4,1,0,0},
		{0,1,1,1,1,1,1,0},
		{0,0,1,2,1,0,0,0},
		{1,0,1,0,1,0,1,0},
		{6,0,0,0,1,5,0,0}
},
	{//level 4
		{9,0,0,0,0,1,4,0,0,0},
		{0,1,1,1,0,1,1,1,1,0},
		{0,1,6,1,0,0,0,0,0,0},
		{0,1,0,1,1,1,0,1,1,1},
		{0,1,0,0,0,1,0,0,0,0},
		{0,0,0,1,0,1,1,0,1,0},
		{1,1,1,1,5,1,0,0,1,0},
		{0,0,0,0,1,1,6,1,1,0},
		{0,1,1,0,0,1,1,0,0,0},
		{0,0,2,1,0,0,0,0,1,0}
},
	{//level 5
		{9,0,0,1,6,1,8,0,0,0},
		{0,1,0,1,0,1,1,1,1,0},
		{0,1,0,0,0,1,0,0,0,0},
		{0,1,1,1,0,1,0,1,1,0},
		{0,1,0,1,6,1,0,0,1,7},
		{0,0,0,0,1,1,1,0,1,2},
		{1,1,1,0,0,0,1,0,1,1},
		{4,1,6,0,1,5,1,0,1,4},
		{0,1,1,0,1,1,1,0,1,0},
		{0,0,0,0,0,0,0,0,0,0}
}
};

int now_state[10][10];

void maze_frame() {
	SetColor(14);
	MoveConsole(22, 2);
	printf("Name : %s", user_name);
	MoveConsole(59, 2);
	printf("┃뒤로가기 ☜ ┃");
	MoveConsole(59, 1);
	printf("┏━━━━━━━━━━━┓");
	MoveConsole(59, 3);
	printf("┗━━━━━━━━━━━┛");

	SetColor(4);
	MoveConsole(22, 3);
	for (int i = 0; i < h; i++)printf("♥ ");
	for (int i = 0; i < 3 - h; i++)printf("♡ ");
	SetColor(7);
	MoveConsole(22, 4);
	printf("스킵권 개수:%d", skip);
	MoveConsole(22, 5);
	printf("코인 개수:%d", user_coin);

	SetColor(4);  //미로 틀
	MoveConsole(47 - maze_size - 2, 12 - maze_size / 2 - 1);
	for (int i = 0; i < maze_size * 2 + 5; i++)printf("▒");
	for (int i = 12 - maze_size / 2; i < 12 + (maze_size + 1) / 2 + 1; i++) {
		MoveConsole(47 - maze_size - 2, i);
		printf("▒▒");
		SetColor(8);
		for (int j = 0; j < maze_size; j++) {
			if (now_state[j][i - 12 + maze_size / 2] == 3) {
				if (j == 0) {
					SetColor(7);
					printf("▒▒");
				}
				if (now_state[j + 1][i - 12 + maze_size / 2] == 3 || j == maze_size - 1) {
					SetColor(7);
					MoveConsole(x_0 + j * 2, y_0 + i - 12 + maze_size / 2);
					printf("▒▒");
				}
				else if (now_state[j - 1][i - 12 + maze_size / 2] == 3) {
					SetColor(7);
					MoveConsole(x_0 + j * 2 - 1, y_0 + i - 12 + maze_size / 2);
					printf("▒▒ ");
				}
				else {
					SetColor(7);
					MoveConsole(x_0 + j * 2, y_0 + i - 12 + maze_size / 2);
					printf("▒ ");
				}
			}
			else if (now_state[j][i - 12 + maze_size / 2] == 10) {
				MoveConsole(x_0 + j * 2, y_0 + i - 12 + maze_size / 2);
				printf("  ");
			}
			else if (j == 0) {
				printf(" ■ ");
			}
			else {
				SetColor(8);
				printf("■ ");
			}

		}
		SetColor(4);
		printf("▒▒");
	}
	MoveConsole(47 - maze_size - 2, 12 + (maze_size + 1)/ 2);
	for (int i = 0; i < maze_size * 2 + 5; i++)printf("▒");
	SetColor(7);
}

void movement() {
	while (1) {
		int random;
		SetColor(7);
		if (GetAsyncKeyState(VK_UP) & 0x8000 && player_y > 0) {
			y = -1;
			random = rand() % 100;
			if (random <= minigame_prob && random != 0) {
				minigame_pop();
				minigame_prob = 0;
			}
			minigame_prob++;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && player_y < maze_size - 1) {
			y = 1;
			random = rand() % 100;
			if (random <= minigame_prob && random != 0) {
				minigame_pop();
				minigame_prob = 0;
			}
			minigame_prob++;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && player_x > 0) {
			x = -1;
			random = rand() % 100;
			if (random <= minigame_prob && random != 0) {
				minigame_pop();
				minigame_prob = 0;
			}
			minigame_prob++;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && player_x < maze_size - 1) {
			x = 1;
			random = rand() % 100;
			if (random <= minigame_prob && random != 0) {
				minigame_pop();
				minigame_prob = 0;
			}
			minigame_prob++;
		}
		else if (GetAsyncKeyState(VK_BACK) & 0x8000) return 0;

		if (now_state[player_x + x][player_y + y] == 0 || now_state[player_x + x][player_y + y] == 10) { //통로
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 10;
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
		}
		else if (now_state[player_x + x][player_y + y] == 1 || now_state[player_x + x][player_y + y] == 3) { //벽
			MoveConsole(x_0 + player_x * 2 + x * 2 , y_0 + player_y + y);
			printf("▒");
			now_state[player_x + x][player_y + y] = 3;
			if (now_state[player_x + x + 1][player_y + y] == 3 || player_x + x== maze_size - 1) {
				MoveConsole(x_0 + player_x * 2 + x * 2 + 1, y_0 + player_y + y);
				printf("▒");
			}
			if (now_state[player_x + x - 1][player_y + y] == 3 || player_x + x== 0) {
				MoveConsole(x_0 + player_x * 2 + x * 2 - 1, y_0 + player_y + y);
				printf("▒");
			}
			x = 0; y = 0;
		}
		else if (now_state[player_x + x][player_y + y] == 2) { //출구
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 10;
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			MoveConsole(75, line);
			printf("미로 탈출 성공!");
			line++;
			user_record[now_level] = 1;
			break;
		}
		else if (now_state[player_x + x][player_y + y] == 4) { //하트 획득
			if (h < 3) {
				h++;
				MoveConsole(75, line);
				printf("you find a life");
				line++;
			}
			else if(h==3){
				MoveConsole(75, line);
				printf("you have all life");
				line++;
			}
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 10;
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			SetColor(4);
			MoveConsole(22, 3);
			for (int i = 0; i < h; i++)printf("♥ ");
			for (int i = 0; i < 3 - h; i++)printf("♡ ");
		}
		else if (now_state[player_x + x][player_y + y] == 5) { //스킵권 획득
			skip++;
			now_state[player_x][player_y] = 10;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			MoveConsole(22, 4);
			printf("스킵권 개수:%d", skip);
			MoveConsole(75, line);
			printf("you find a skip ticket");
			line++;
		}
		else if (now_state[player_x + x][player_y + y] == 6) { //코인 획득
			coin++;
			now_state[player_x][player_y] = 10;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			MoveConsole(22, 5);
			printf("코인 개수:%d", user_coin);
			MoveConsole(75, line);
			printf("you find a coin");
			line++;
		}
		else if (now_state[player_x + x][player_y + y] == 7) { //문
			if (key == 0) {
			MoveConsole(x_0 + player_x * 2 + x * 2, y_0 + player_y + y);
			SetColor(4);
			printf("▒");
			x = 0; y = 0;
			SetColor(7);
				MoveConsole(75, line);
				printf("you need a key");
				line++;
			}
			else if (key == 1) {
				now_state[player_x][player_y] = 10;
				MoveConsole(x_0 + player_x * 2, y_0 + player_y);
				printf(" ");
				player_x += x; player_y += y; x = 0; y = 0;
				MoveConsole(x_0 + player_x * 2, y_0 + player_y);
				now_state[player_x][player_y] = 9;
				printf("%s", now_skin);
				MoveConsole(75, line);
				printf("door open");
				line++;
			}
		}
		else if (now_state[player_x + x][player_y + y] == 8) { //열쇠 획득
			key++;
			now_state[player_x][player_y] = 10;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			MoveConsole(75, line);
			printf("you find a key");
			line++;
		}
		else if (now_state[player_x + x][player_y + y] == 9) { //플레이어 위치
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%s", now_skin);
			}
		Sleep(110);
	}
}

void maze() {
	for (int i = 0; i < maze_size; i++) {
		for (int j = 0; j < maze_size; j++) {
			now_state[i][j] = state[now_level - 1][i][j];
		}
	}
	maze_frame();
	SetColor(7);
	player_x = 0; player_y = 0; x = 0; y = 0; //플레이어 초기 위치
	movement();
}

void maze_game() {
	time_t start = time(NULL);
	srand(time(NULL));
	minigame_prob = 0;
	ScreenReset();
	MoveConsole(75, 0);
	SetColor(7);
	strcpy(inform[0], "inform");
	printf("inform");
	line++;
	if (now_level == 1)	maze_size = 5;
	else if (now_level == 2) maze_size = 8;
	else if (now_level == 3) maze_size = 8;
	else if (now_level == 4) maze_size = 10;
	else if (now_level == 5) maze_size = 10;
	x_0 = 49 - maze_size - 1; y_0 = 12 - maze_size / 2; //(0,0)의 콘솔 위치
	maze();
	time_t end = time(NULL);
	//기록 = end - start;
	ScreenReset();
}