#include "MOC.h"

int user_record[6]; // 1 2 3 4 5 �ܰ� ���
int user_skin[12]; // 1 2 3... 11 ��Ų
int user_coin;
char user_name[20];
int now_level;

int maze_size;
int player_x, player_y; //state������ �÷��̾� ��ġ
int x, y; //�÷��̾� �̵��� ����
int x_0, y_0; //state�� (0,0)�� �ܼ� ��ġ�� ��Ÿ�� ��
int h = 3; //��Ʈ ����
int skip = 0; //��ŵ�� ����
int coin = 0; //���� ����
int key = 0;
int line = 0;

int state[5][10][10] = {
	{//level 1
		{0,1,4,1,2},
		{0,1,0,1,0},
		{0,0,0,1,0},
		{1,1,0,0,0},
		{5,0,0,1,6}
},
	{//level 2
		{0,0,0,0,1,0,0,0},
		{1,1,1,0,1,0,1,5},
		{0,0,0,0,1,0,1,1},
		{0,1,1,0,0,0,0,6},
		{0,6,1,0,1,1,1,1},
		{1,1,1,0,0,0,0,0},
		{4,0,1,0,1,1,1,0},
		{1,0,0,0,1,2,0,0}
},
	{//level 3
		{0,0,0,0,0,0,1,6},
		{0,1,1,1,1,0,0,0},
		{0,1,0,0,0,1,0,1},
		{0,0,0,1,4,1,0,0},
		{0,1,1,1,1,1,1,0},
		{0,0,1,2,1,0,0,0},
		{1,0,1,0,1,0,1,0},
		{6,0,0,0,1,5,0,0}
},
	{//level 4
		{0,0,0,0,0,1,4,0,0,0},
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
		{0,0,0,1,6,1,8,0,0,0},
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

void maze_frame() {
	SetColor(4);  //�̷� Ʋ
	MoveConsole(47 - maze_size - 2, 12 - maze_size / 2 - 1);
	for (int i = 0; i < maze_size * 2 + 5; i++)printf("��");
	for (int i = 12 - maze_size / 2; i < 12 + maze_size / 2; i++) {
		MoveConsole(47 - maze_size - 2, i);
		printf("�Ƣ�");
		SetColor(8);
		printf(" ");
		for (int j = 0; j < maze_size; j++) printf("�� ");
		SetColor(4);
		printf("�Ƣ�");
	}
	MoveConsole(47 - maze_size - 2, 12 + maze_size / 2);
	for (int i = 0; i < maze_size * 2 + 5; i++)printf("��");
}

void movement() {
	while (1) {
		if (GetAsyncKeyState(VK_UP) & 0x8000 && player_y > 0) y = -1;
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && player_y < maze_size - 1) y = 1;
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && player_x > 0) x = -1;
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && player_x < maze_size - 1) x = 1;

		if (state[now_level - 1][player_x + x][player_y + y] == 0) { //���
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%s", user_skin);
		}
		else if (state[now_level - 1][player_x + x][player_y + y] == 1 || state[now_level - 1][player_x + x][player_y + y] == 3) { //��
			MoveConsole(x_0 + player_x * 2 + x * 2 , y_0 + player_y + y);
			printf("��");
			state[now_level - 1][player_x + x][player_y + y] = 3;
			if (state[now_level - 1][player_x + x + 1][player_y + y] == 3 || player_x + x== maze_size - 1) {
				MoveConsole(x_0 + player_x * 2 + x * 2 + 1, y_0 + player_y + y);
				printf("��");
			}
			if (state[now_level - 1][player_x + x - 1][player_y + y] == 3 || player_x + x== 0) {
				MoveConsole(x_0 + player_x * 2 + x * 2 - 1, y_0 + player_y + y);
				printf("��");
			}
			x = 0; y = 0;
		}
		else if (state[now_level - 1][player_x + x][player_y + y] == 2) { //�ⱸ
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%s", user_skin);
			MoveConsole(75, line);
			printf("�̷� Ż�� ����!");
			line++;
			break;
		}
		else if (state[now_level - 1][player_x + x][player_y + y] == 4) { //��Ʈ ȹ��
			h++;
			state[now_level - 1][player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%s", user_skin);
			MoveConsole(9, 2);
			printf("��Ʈ ����:%d",h);
			MoveConsole(75, line);
			printf("you find a life");
			line++;
		}
		else if (state[now_level - 1][player_x + x][player_y + y] == 5) { //��ŵ�� ȹ��
			skip++;
			state[now_level - 1][player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%s", user_skin);
			MoveConsole(7, 3);
			printf("��ŵ�� ����:%d", skip);
			MoveConsole(75, line);
			printf("you find a skip ticket");
			line++;
		}
		else if (state[now_level - 1][player_x + x][player_y + y] == 6) { //���� ȹ��
			coin++;
			state[now_level - 1][player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%s", user_skin);
			MoveConsole(9, 4);
			printf("���� ����:%d", coin);
			MoveConsole(75, line);
			printf("you find a coin");
			line++;
		}
		else if (state[now_level - 1][player_x + x][player_y + y] == 7) { //��
			if (key == 0) {
			MoveConsole(x_0 + player_x * 2 + x * 2, y_0 + player_y + y);
			SetColor(4);
			printf("��");
			x = 0; y = 0;
			SetColor(7);
				MoveConsole(75, line);
				printf("you need a key");
				line++;
			}
			else if (key == 1) {
				state[now_level - 1][player_x + x][player_y + y] = 0;
				MoveConsole(x_0 + player_x * 2, y_0 + player_y);
				printf(" ");
				player_x += x; player_y += y; x = 0; y = 0;
				MoveConsole(x_0 + player_x * 2, y_0 + player_y);
				printf("%s", user_skin);
				MoveConsole(75, line);
				printf("door open");
				line++;
			}
		}
		else if (state[now_level - 1][player_x + x][player_y + y] == 8) { //���� ȹ��
			key++;
			state[now_level - 1][player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%s", user_skin);
			MoveConsole(75, line);
			printf("you find a key");
			line++;
		}
		Sleep(110);
	}
}

void maze() {
	SetColor(7);
	MoveConsole(9, 2);
	printf("��Ʈ ����:%d",h);
	MoveConsole(7, 3);
	printf("��ŵ�� ����:%d", skip);
	MoveConsole(9, 4);
	printf("���� ����:%d", coin);

	maze_frame();
	SetColor(7);
	player_x = 0; player_y = 0; x = 0; y = 0; //�÷��̾� �ʱ� ��ġ
	movement();
}

void maze_game() {
	now_level = 4;
	strcpy(user_skin, "x");
	ScreenReset();
	MoveConsole(22, 2);
	printf("Name : %s", user_name);

	MoveConsole(59, 2);
	printf("���ڷΰ��� �� ��");
	MoveConsole(59, 1);
	printf("��������������������������");
	MoveConsole(59, 3);
	printf("��������������������������");

	MoveConsole(75, 0);
	printf("inform");
	line++;
	if (now_level == 1)	maze_size = 5;
	else if (now_level == 2) maze_size = 8;
	else if (now_level == 3) maze_size = 8;
	else if (now_level == 4) maze_size = 10;
	else if (now_level == 5) maze_size = 10;
	x_0 = 49 - maze_size - 1; y_0 = 12 - maze_size / 2; //(0,0)�� �ܼ� ��ġ
	maze();
}