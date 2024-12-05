#include "MOC.h"

int user_record[6]; // 1 2 3 4 5 �ܰ� ���
int user_skin[18]; // 1 2 3... 11 ��Ų
int user_coin;
char user_name[20];
int now_level;

int maze_size;
char player_skin;
int player_x, player_y; //state1������ �÷��̾� ��ġ
int x, y; //�÷��̾� �̵��� ����
int x_0, y_0; //state�� (0,0)�� �ܼ� ��ġ�� ��Ÿ�� ��
int h = 0; //��Ʈ ����
int skip = 0; //��ŵ�� ����
int coin = 0; //���� ����

void maze1() {
	int state1[10][10] = { //���� ���� y��, ���� ���� x��
	{0,1,4,1,2},
	{0,1,0,1,0},
	{0,0,0,1,0},
	{1,1,0,0,0},
	{5,0,0,1,6}
	};
	x_0 = 43; y_0 = 10; //(0,0)�� �ܼ� ��ġ
	
	SetColor(7);
	MoveConsole(76, 2);
	printf("��Ʈ ����:%d",h);
	MoveConsole(76, 3);
	printf("��ŵ�� ����:%d", skip);
	MoveConsole(76, 4);
	printf("���� ����:%d", coin);
	SetColor(4);  //�̷� Ʋ
	MoveConsole(40, 9);
	printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
	for (int i = 10; i <= 14; i++) {
		MoveConsole(40, i);
		printf("�Ƣ�           �Ƣ�");
	}
	MoveConsole(40, 15);
	printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");

	SetColor(8); //���� �þ�
	for (int i = 10; i <= 14; i++) {
		MoveConsole(43, i);
		printf("�� �� �� �� �� ");
	}
	SetColor(7);
	player_x = 0; player_y = 0; x = 0; y = 0; player_skin = 'x'; //�÷��̾� �ʱ� ��ġ
	while (1) {
		if (GetAsyncKeyState(VK_UP) && player_y > 0) y = -1;
		else if (GetAsyncKeyState(VK_DOWN) && player_y < 4) y = 1;
		else if (GetAsyncKeyState(VK_LEFT) && player_x > 0) x = -1;
		else if (GetAsyncKeyState(VK_RIGHT) && player_x < 4) x = 1;

		if (state1[player_x + x][player_y + y] == 0) { //���
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c",  player_skin);
		}
		else if (state1[player_x + x][player_y + y] == 1) { //��
			MoveConsole(x_0 + player_x * 2 + x * 2, y_0 + player_y + y);
			printf("��");
			x = 0; y = 0;
		}
		else if (state1[player_x + x][player_y + y] == 2) { //�ⱸ
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c", player_skin);
			MoveConsole(0, 0);
			printf("�̷� Ż�� ����!");
			break;
		}
		else if (state1[player_x + x][player_y + y] == 4) { //��Ʈ ȹ��
			h++;
			state1[player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c", player_skin);
			MoveConsole(76, 2);
			printf("��Ʈ ����:%d",h);
		}
		else if (state1[player_x + x][player_y + y] == 5) { //��ŵ�� ȹ��
			skip++;
			state1[player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c", player_skin);
			MoveConsole(76, 3);
			printf("��ŵ�� ����:%d", skip);
		}
		else if (state1[player_x + x][player_y + y] == 6) { //���� ȹ��
			coin++;
			state1[player_x + x][player_y + y] = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf(" ");
			player_x += x; player_y += y; x = 0; y = 0;
			MoveConsole(x_0 + player_x * 2, y_0 + player_y);
			printf("%c", player_skin);
			MoveConsole(76, 4);
			printf("���� ����:%d", coin);
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
	printf("���ڷΰ��� �� ��");
	MoveConsole(59, 1);
	printf("��������������������������");
	MoveConsole(59, 3);
	printf("��������������������������");

	if (now_level == 1)maze1();

	MoveConsole(0, 20);
}