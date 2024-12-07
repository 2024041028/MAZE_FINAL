#include "MOC.h"

int user_record[6]; // 1 2 3 4 5 �ܰ� ���
int user_skin[21]; // 1 2 3... 11 ��Ų X �� �� �� �� �� �� �� �� �� �� �� �� ? �� �� �� �� �� // 19��      <�� �� ��>
char now_skin[10];
int user_coin;
char user_name[20];
char skin_list[20][10];
int now_level;

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
			RemoveGarbageChar();
			if (flag == 0)
				EnterNickname();
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
		SetColor(7);
		MoveConsole(75, 1);
		printf("<<�⺻����>>");
		MoveConsole(75, 2);
		printf("  ��");
		MoveConsole(75, 3);
		printf(" �� ��  �� Enter�� ���� �����Ͻʽÿ�");
		MoveConsole(75, 4);
		printf("  ��");
		MoveConsole(75, 6);
		printf("�ڷΰ��� : Backspace");
		MoveConsole(75, 7);
		printf("�������� : pŰ");
		MoveConsole(75, 8);
		printf("�������� : ���ϴ� �ܰ迡�� Enter");
		MoveConsole(75, 9);
		printf("�������� : ESC");
		Sleep(100);
	}
}

int CheckUserStatus() {
	ScreenReset();
	MoveConsole(38, 10);
	SetColor(15);
	printf("ó�� �����Ͻó���?");
	Sleep(100);
	int flag = 0;
	while (1) {
		Sleep(110);
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			flag = 0;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			flag = 1;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			RemoveGarbageChar();
			return flag;
		}

		if (flag == 0) {
			MoveConsole(42, 11);
			SetColor(7);
			printf("Yes");
			SetColor(8);
			printf("    No");
		}
		else if (flag == 1) {
			MoveConsole(42, 11);
			SetColor(8);
			printf("Yes");
			SetColor(7);
			printf("    No");
		}

	}
}

int HasSpecialChar(char name[100]) {
	for (int i = 0; name[i] != '\0'; i++) {
		if (name[i] == '\\' || name[i] == '\'' || name[i] == '\"' || name[i] == '/' || name[i] == ':' || name[i] == '*' || name[i] == '?' || name[i] == '>' || name[i] == '<' || name[i] == '|')
			return 1;
	}
	return 0;
}

int FileCheck() {
	FILE* userinfo = fopen("Userinfo.txt", "r");
	if (userinfo == NULL) {
		return 1;
	}
	else if (userinfo != NULL) { // ����
		return 0;
	}
}

int EnterNickname() {
	while (1) {
		int size = 20;
		int flag = 0;

		int visit = CheckUserStatus();
		ScreenReset();
		MoveConsole(34, 10);
		SetColor(15);
		printf("����� �̸��� �Է����ּ���");
		MoveConsole(34, 11);
		printf("�̸� :                     ");

		SetColor(7);
		char name[20];
		MoveConsole(41, 11);
		fgets(name, size, stdin);
		int len = strlen(name);
		name[len - 1] = '\0';

		SetColor(4);

		if (len > 12) {
			MoveConsole(26, 13);
			printf("�̸��� 12���� �̳��� �ۼ����ֽñ� �ٶ��ϴ�.");
			Sleep(2500);
			MoveConsole(26, 13);
			printf("                                           ");
		}
		else if (HasSpecialChar(name) == 1) {
			MoveConsole(31, 13);
			printf("�̸��� Ư����ȣ�� ����� �Ұ��մϴ�.");
			MoveConsole(29, 14);
			printf("Ư����ȣ : /, \\, \', \", ?, :, *, <, > , |");
		}
		else if (FileCheck() == 1 && visit == 1) { // �����Ҷ� FileCheck() = 0 
			MoveConsole(35, 13);
			printf("�������� �ʴ� �̸��Դϴ�.");
			MoveConsole(38, 14);
			printf("�ٽ� �Է����ּ���");
		}
		else if (FileCheck() == 1 && visit == 0) { // ����
			strcpy(user_name, name);

			FILE* userinfo_w = fopen("UserInfo.txt", "w");
			fprintf(userinfo_w, "%s\n", name);
			fclose(userinfo_w);

			FILE* record = fopen("Record.txt", "w");
			fprintf(record, "%s ", name);
			for (int i = 0; i < 26; i++) {
				if (i == 6) {
					fprintf(record, "%d ", 1);
					user_skin[1] = 1;
					continue;
				}
				fprintf(record, "%d ", 0);
			}
			fprintf(record, "\n");
			fclose(record);

			/*char filename[30];
			snprintf(filename, 30, "%s.txt", name);
			FILE* in = fopen(filename, "w");
			for (int i = 0; i < 12; i++) {
				fprintf(in, "%d ", 0);
			}
			fclose(in);*/


			return 0;
		}
		else if (FileCheck() == 0) {
			char temp[20];
			char filename[30];

			FILE* userinfo_r = fopen("UserInfo.txt", "r");

			while (fscanf(userinfo_r, "%s", temp) != EOF) {
				if (visit == 0 && strcmp(temp, name) == 0) {
					MoveConsole(35, 13);
					printf("�̹� �����ϴ� �̸��Դϴ�.");
					MoveConsole(39, 14);
					printf("�ٽ� �Է����ּ���");
					flag = 1;
					break;
				}
				else if (visit == 1 && strcmp(temp, name) == 0) { // ����

					strcpy(user_name, name);

					/*snprintf(filename, 30, "%s.txt", name);
					FILE* in = fopen(filename, "r");
					for (int i = 0; i < 12; i++) {
						fscanf(in, "%d", &user_info[i]);
					}
					fclose(in);*/

					FILE* record = fopen("Record.txt", "r");
					while (1) {
						int result = fscanf(record, "%s", temp);
						int cnt = 1;
						if (result == EOF)
							break;

						for (int i = 0; i < 26; i++) {
							if (i == 0)
								fscanf(record, "%d", &user_coin);
							else if (i > 0 && i < 6) {
								fscanf(record, "%d", &user_record[i]);
							}
							else {
								fscanf(record, "%d", &user_skin[cnt]);
								cnt++;
							}
						}

						if (strcmp(temp, name) == 0) {
							break;
						}

					}
					fclose(record);

					return 0;
				}
			}
			fclose(userinfo_r);
			if (flag == 0 && visit == 0) { // ���� 

				FILE* userinfo_a = fopen("UserInfo.txt", "a");
				strcpy(user_name, name);
				fprintf(userinfo_a, "%s\n", name);
				fclose(userinfo_a);

				/*snprintf(filename, 30, "%s.txt", name);
				FILE* in = fopen(filename, "w");
				for (int i = 0; i < 12; i++) {
					fprintf(in,"%d ", 0);
				}
				fclose(in);*/

				FILE* record = fopen("Record.txt", "a");
				fprintf(record, "%s ", name);
				for (int i = 0; i < 26; i++) {
					if (i == 6) {
						fprintf(record, "%d ", 1);
						user_skin[1] = 1;
						continue;
					}
					fprintf(record, "%d ", 0);
				}
				fprintf(record, "\n");
				fclose(record);

				return 0;
			}
			else if (flag == 0 && visit == 1) {
				MoveConsole(35, 13);
				printf("�������� �ʴ� �̸��Դϴ�.");
				MoveConsole(38, 14);
				printf("�ٽ� �Է����ּ���");
			}
		}

		Sleep(2000);
	}
	return 0;
}
