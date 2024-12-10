#include "MOC.h"


int maze_size;
int player_x, player_y; //state������ �÷��̾� ��ġ
int x, y; //�÷��̾� �̵��� ����
int x_0, y_0; //state�� (0,0)�� �ܼ� ��ġ�� ��Ÿ�� ��
int h = 3; //��Ʈ ����
int skip = 0; //��ŵ�� ����
int key = 0; //���� ȹ�� ����
int line = 0; //inform �� �� ���
int minigame_prob; //�̴ϰ��� ȣ�� Ȯ��
char inform[100][100]; //�ȳ� ���� ���
int clear = 0; //�̷� ���� ����

void minigame_pop(int random,int x,int y) {
	FillEntireFrameRandomly(random, x, y);
	int what_game = random % 10;
	int result;
	if (what_game == 0) result = random_number();
	else if (what_game == 1) result = PlayHangman();
	else if (what_game == 2) result = PlayMathGame();
	else if (what_game == 3) result = PlayMemoryGame();
	else if (what_game == 4) result = PlayReflexGame();
	else if (what_game == 5) result = PlayGreenFrogRPS();
	else if (what_game == 6) result = PlayAscendingGame();
	else if (what_game == 7) result = PlayTriviaQuizGame();
	else if (what_game == 8) result = PlayArrowGame();
	
	if (result == 1) {
		user_coin += 2;
	}
	else {
		h--;
	}
	ScreenReset();
	SetColor(7);
	for (int i = 0; i < line; i++) {
		MoveConsole(75, i);
		printf("%s", inform[i]);
	}
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
	printf("���ڷΰ��� �� ��");
	MoveConsole(59, 1);
	printf("��������������������������");
	MoveConsole(59, 3);
	printf("��������������������������");

	SetColor(4);
	MoveConsole(22, 3);
	for (int i = 0; i < h; i++)printf("�� ");
	for (int i = 0; i < 3 - h; i++)printf("�� ");
	SetColor(7);
	MoveConsole(22, 4);
	printf("��ŵ�� ����:%d", skip);
	MoveConsole(22, 5);
	printf("���� ����:%d", user_coin);

	SetColor(4);  //�̷� Ʋ
	MoveConsole(47 - maze_size - 2, 12 - maze_size / 2 - 1);
	for (int i = 0; i < maze_size * 2 + 5; i++)printf("��");
	for (int i = 12 - maze_size / 2; i < 12 + (maze_size + 1) / 2 + 1; i++) {
		MoveConsole(47 - maze_size - 2, i);
		printf("�Ƣ�");
		SetColor(8);
		for (int j = 0; j < maze_size; j++) {
			if (now_state[j][i - 12 + maze_size / 2] == 3) {
				if (j == 0) {
					SetColor(7);
					printf("�Ƣ�");
				}
				if (now_state[j + 1][i - 12 + maze_size / 2] == 3 || j == maze_size - 1) {
					SetColor(7);
					MoveConsole(x_0 + j * 2, y_0 + i - 12 + maze_size / 2);
					printf("�Ƣ�");
				}
				else if (now_state[j - 1][i - 12 + maze_size / 2] == 3) {
					SetColor(7);
					MoveConsole(x_0 + j * 2 - 1, y_0 + i - 12 + maze_size / 2);
					printf("�Ƣ� ");
				}
				else {
					SetColor(7);
					MoveConsole(x_0 + j * 2, y_0 + i - 12 + maze_size / 2);
					printf("�� ");
				}
			}
			else if (now_state[j][i - 12 + maze_size / 2] == 10) {
				MoveConsole(x_0 + j * 2, y_0 + i - 12 + maze_size / 2);
				printf("  ");
			}
			else if (j == 0) {
				printf(" �� ");
			}
			else {
				SetColor(8);
				printf("�� ");
			}

		}
		SetColor(4);
		printf("�Ƣ�");
	}
	MoveConsole(47 - maze_size - 2, 12 + (maze_size + 1)/ 2);
	for (int i = 0; i < maze_size * 2 + 5; i++)printf("��");
	SetColor(7);
}

void movement() {
	int random_color = 0;
	while (1) {
		int random;
		SetColor(7);
		if (GetAsyncKeyState(VK_UP) & 0x0001 && player_y > 0) {
			y = -1;
			random = rand() % 100;
			if (random <= minigame_prob && random != 0) {
				random_color = rand() % 7;
				minigame_pop(random_color, x_0 + player_x * 2, y_0 + player_y);
				minigame_prob = 0;
			}
			if (now_state[player_x + x][player_y + y] != 1 && now_state[player_x + x][player_y + y] != 3)minigame_prob++;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && player_y < maze_size - 1) {
			y = 1;
			random = rand() % 100;
			if (random <= minigame_prob && random != 0) {
				random_color = rand() % 7;
				minigame_pop(random_color, x_0 + player_x * 2, y_0 + player_y);
				minigame_prob = 0;
			}
			if (now_state[player_x + x][player_y + y] != 1 && now_state[player_x + x][player_y + y] != 3)minigame_prob++;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && player_x > 0) {
			x = -1;
			random = rand() % 100;
			if (random <= minigame_prob && random != 0) {
				random_color = rand() % 7;
				minigame_pop(random_color, x_0 + player_x * 2, y_0 + player_y);
				minigame_prob = 0;
			}
			if (now_state[player_x + x][player_y + y] != 1 && now_state[player_x + x][player_y + y] != 3)minigame_prob++;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && player_x < maze_size - 1) {
			x = 1;
			random = rand() % 100;
			if (random <= minigame_prob && random != 0) {
				random_color = rand() % 7;
				minigame_pop(random_color, x_0 + player_x * 2, y_0 + player_y);
				minigame_prob = 0;
			}
			if (now_state[player_x + x][player_y + y] != 1 && now_state[player_x + x][player_y + y] != 3)minigame_prob++;
		}
		else if (GetAsyncKeyState(VK_BACK) & 0x8000) break;
		if (h == 0) {
			ScreenReset();
			MoveConsole(40, 10);
			printf("�̷� Ż�� ����!");
			MoveConsole(25, 2);
			printf("���� ȭ������ ���ư����� BACKSPACE�� �����ÿ�");
			while (1) {
				if (GetAsyncKeyState(VK_BACK) & 0x8000) break;
				Sleep(10);
			}
		}
		if (now_state[player_x + x][player_y + y] == 0 || now_state[player_x + x][player_y + y] == 10) { //���
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 10;
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
		}
		else if (now_state[player_x + x][player_y + y] == 1 || now_state[player_x + x][player_y + y] == 3) { //��
			MoveConsole(x_0 + player_x * 2 + x * 2 , y_0 + player_y + y);
			printf("��");
			now_state[player_x + x][player_y + y] = 3;
			if (now_state[player_x + x + 1][player_y + y] == 3 || player_x + x== maze_size - 1) {
				MoveConsole(x_0 + player_x * 2 + x * 2 + 1, y_0 + player_y + y);
				printf("��");
			}
			if (now_state[player_x + x - 1][player_y + y] == 3 || player_x + x== 0) {
				MoveConsole(x_0 + player_x * 2 + x * 2 - 1, y_0 + player_y + y);
				printf("��");
			}
			x = 0; y = 0;
		}
		else if (now_state[player_x + x][player_y + y] == 2) { //�ⱸ
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 10;
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			MoveConsole(75, line);
			strcpy(inform[line], "�̷� Ż�� ����!");
			printf("�̷� Ż�� ����!");
			line++;
			clear = 1;
			UpdateUserInfo();
			break;
		}
		else if (now_state[player_x + x][player_y + y] == 4) { //��Ʈ ȹ��
			if (h < 3) {
				h++;
				MoveConsole(75, line);
				strcpy(inform[line], "you find a life");
				printf("you find a life");
				line++;
			}
			else if(h==3){
				MoveConsole(75, line);
				strcpy(inform[line], "you have all life");
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
			for (int i = 0; i < h; i++)printf("�� ");
			for (int i = 0; i < 3 - h; i++)printf("�� ");
		}
		else if (now_state[player_x + x][player_y + y] == 5) { //��ŵ�� ȹ��
			skip++;
			now_state[player_x][player_y] = 10;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			MoveConsole(22, 4);
			printf("��ŵ�� ����:%d", skip);
			MoveConsole(75, line);
			strcpy(inform[line], "you find a skip ticket");
			printf("you find a skip ticket");
			line++;
		}
		else if (now_state[player_x + x][player_y + y] == 6) { //���� ȹ��
			user_coin++;
			now_state[player_x][player_y] = 10;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			MoveConsole(22, 5);
			printf("���� ����:%d", user_coin);
			MoveConsole(75, line);
			strcpy(inform[line], "you find a coin");
			printf("you find a coin");
			line++;
		}
		else if (now_state[player_x + x][player_y + y] == 7) { //��
			if (key == 0) {
			MoveConsole(x_0 + player_x * 2 + x * 2, y_0 + player_y + y);
			SetColor(4);
			printf("��");
			x = 0; y = 0;
			SetColor(7);
				MoveConsole(75, line);
				strcpy(inform[line], "you need a key");
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
		else if (now_state[player_x + x][player_y + y] == 8) { //���� ȹ��
			key++;
			now_state[player_x][player_y] = 10;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			now_state[player_x][player_y] = 9;
			printf("%s", now_skin);
			MoveConsole(75, line);
			strcpy(inform[line], "you find a key");
			printf("you find a key");
			line++;
		}
		else if (now_state[player_x + x][player_y + y] == 9) { //�÷��̾� ��ġ
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
	player_x = 0; player_y = 0; x = 0; y = 0; //�÷��̾� �ʱ� ��ġ
	movement();
}

void maze_game() {
	h = 3;
	time_t start = time(NULL);
	srand(time(NULL));
	minigame_prob = 0;
	ScreenReset();
	MoveConsole(75, 0);
	SetColor(7);
	strcpy(inform[line], "inform");
	printf("inform");
	line++;
	if (now_level == 1)	maze_size = 5;
	else if (now_level == 2) maze_size = 8;
	else if (now_level == 3) maze_size = 8;
	else if (now_level == 4) maze_size = 10;
	else if (now_level == 5) maze_size = 10;
	x_0 = 49 - maze_size - 1; y_0 = 12 - maze_size / 2; //(0,0)�� �ܼ� ��ġ
	maze();
	time_t end = time(NULL);
	int record = end - start;
	ScreenReset();
	if (clear == 1) {
		MoveConsole(40, 10);
		printf("�̷� Ż�� ����!");
		MoveConsole(44, 12);
		printf("���:%d", record);
		if (user_record[now_level] == 0 || user_record[now_level] > record) {
			MoveConsole(32, 14);
			printf("�ű��! �� ������� ��ϵ˴ϴ�.");
			MoveConsole(38, 16);
			printf("����� %d���Դϴ�!", 1);
			user_record[now_level] = record;
			MoveConsole(0, 0);
			printf("%d", user_record[now_level]);
			UpdateUserInfo();
		}
		MoveConsole(25, 2);
		printf("���� ȭ������ ���ư����� BACKSPACE�� �����ÿ�");
		clear = 0;
		while (1) {
			if (GetAsyncKeyState(VK_BACK) & 0x8000) break;
			Sleep(10);
		}
	}
	skip = 0;
	line = 0;
	clear = 0;
	UpdateUserInfo();
	ScreenReset();
}