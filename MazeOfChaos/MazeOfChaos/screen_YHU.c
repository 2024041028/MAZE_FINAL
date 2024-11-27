#include "MOC.h"

void ExplainGame() {
	ScreenReset();
	SetColor(7);
	MoveConsole(23, 5);
	char arr[100] = "�� Maze Of Chaos�� ���Ű��� ȯ���մϴ�!";
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	Sleep(500);
	MoveConsole(23, 7);
	strcpy(arr, "�� �� �� ��");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 8);
	strcpy(arr, "����Ű�� Ȱ���ؼ� ������ �ʴ� �̷θ� Ż���ϼ���!");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	Sleep(500);
	MoveConsole(23, 10);
	strcpy(arr, "<<�̴ϰ���>>");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 11);
	strcpy(arr, "�̷θ� Ż���ϴٰ� �����ϰ� �̴ϰ����� �����˴ϴ�.");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 12);
	strcpy(arr, "�̴ϰ��ӿ� �����ϸ� ��带 �����մϴ�.");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	Sleep(500);
	MoveConsole(23, 14);
	strcpy(arr, "<<������>>");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 15);
	strcpy(arr, "�� : �߰�����");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 16);
	strcpy(arr, "P : �̴ϰ��� �н���");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 17);
	strcpy(arr, "G : ���");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(59, 2);
	printf("���ڷΰ��� �� ��");
	MoveConsole(59, 1);
	printf("��������������������������");
	MoveConsole(59, 3);
	printf("��������������������������");
	while (1) {
		if (GetAsyncKeyState(VK_BACK) & 0x8000) {
			StartScreen();
			return 0;
		}
	}
}


void StartScreen() {
	ScreenReset();
	int flag = 0;
	while (1) {
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (flag == 0)
				flag = 1;
			else if (flag == 1)
				flag = 2;
		}
		else if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (flag == 2)
				flag = 1;
			else if (flag == 1)
				flag = 0;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (flag == 0)
				Gamestart();
			else if (flag == 1)
				ExplainGame();
			else
				FinishGame();
			break;
		}

		if (flag == 0) {
			SetColor(7);
			MoveConsole(41, 8);
			printf("�� ���ӽ���");
			SetColor(8);
			MoveConsole(41, 10);
			printf("  ���Ӽ���");
			SetColor(8);
			MoveConsole(41, 12);
			printf("  ������");
		}
		else if (flag == 1) {
			SetColor(8);
			MoveConsole(41, 8);
			printf("  ���ӽ���");
			SetColor(7);
			MoveConsole(41, 10);
			printf("�� ���Ӽ���");
			SetColor(8);
			MoveConsole(41, 12);
			printf("  ������");
		}
		else if (flag == 2) {
			SetColor(8);
			MoveConsole(41, 8);
			printf("  ���ӽ���");
			SetColor(8);
			MoveConsole(41, 10);
			printf("  ���Ӽ���");
			SetColor(7);
			MoveConsole(41, 12);
			printf("�� ������");
		}
		Sleep(110);
	}
}

void Gamestart() {
	FinishGame();
}