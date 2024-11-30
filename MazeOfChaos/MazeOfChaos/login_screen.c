#include "MOC.h"

int user_record[6] = { 0, };
int user_info[12] = { 0, };
char user_name[20];

void ExplainGame() {
	ScreenReset();
	SetColor(7);
	MoveConsole(23, 5);
	char arr[100] = "★ Maze Of Chaos에 오신것을 환영합니다!";
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	Sleep(500);
	MoveConsole(23, 7);
	strcpy(arr, "↑ ↓ → ←");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 8);
	strcpy(arr, "방향키를 활용해서 보이지 않는 미로를 탈출하세요!");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	Sleep(500);
	MoveConsole(23, 10);
	strcpy(arr, "<<미니게임>>");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 11);
	strcpy(arr, "미로를 탈출하다가 랜덤하게 미니게임이 생성됩니다.");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 12);
	strcpy(arr, "미니게임에 성공하면 골드를 지급합니다.");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	Sleep(500);
	MoveConsole(23, 14);
	strcpy(arr, "<<아이템>>");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 15);
	strcpy(arr, "♥ : 추가생명");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 16);
	strcpy(arr, "P : 미니게임 패스권");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(23, 17);
	strcpy(arr, "G : 골드");
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
		Sleep(10);
	}
	MoveConsole(59, 2);
	printf("┃뒤로가기 ☜ ┃");
	MoveConsole(59, 1);
	printf("┏━━━━━━━━━━━┓");
	MoveConsole(59, 3);
	printf("┗━━━━━━━━━━━┛");
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
			printf("▶ 게임시작");
			SetColor(8);
			MoveConsole(41, 10);
			printf("  게임설명");
			SetColor(8);
			MoveConsole(41, 12);
			printf("  나가기");
		}
		else if (flag == 1) {
			SetColor(8);
			MoveConsole(41, 8);
			printf("  게임시작");
			SetColor(7);
			MoveConsole(41, 10);
			printf("▶ 게임설명");
			SetColor(8);
			MoveConsole(41, 12);
			printf("  나가기");
		}
		else if (flag == 2) {
			SetColor(8);
			MoveConsole(41, 8);
			printf("  게임시작");
			SetColor(8);
			MoveConsole(41, 10);
			printf("  게임설명");
			SetColor(7);
			MoveConsole(41, 12);
			printf("▶ 나가기");
		}
		Sleep(110);
	}
}

int CheckUserStatus() {
	ScreenReset();
	MoveConsole(38, 10);
	SetColor(15);
	printf("처음 접속하시나요?");
	int flag = 0;
	char new[20]; // 추가
	while (1) {
		Sleep(110);
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			flag = 0;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			flag = 1;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			fgets(new, 20, stdin);
			Sleep(100);
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
	else if (userinfo != NULL) { // 존재
		return 0;
	}
}

int EnterNickname() {
	while (1) {
		int size = 20;
		int flag = 0;
		char newline[20] = { 0, };

		int visit = CheckUserStatus();
		ScreenReset();
		MoveConsole(34, 10);
		SetColor(15);
		printf("당신의 이름을 입력해주세요");
		MoveConsole(34, 11);
		printf("이름 :                     ");

		SetColor(7);
		char name[20];

		while (1) {
			MoveConsole(41, 11);
			fgets(newline, size, stdin);
			if (newline[0] != '\n') {
				int len = strlen(newline);
				newline[len - 1] = '\0';
				strcpy(name, newline);
				break;
			}
		}

		int len = strlen(name); // 여기까지 1단계
		SetColor(4);

		
		if (len > 12) {
			MoveConsole(26, 13);
			printf("이름은 12글자 이내로 작성해주시길 바랍니다.");
			Sleep(2500);
			MoveConsole(26, 13);
			printf("                                           ");
		}
		else if (HasSpecialChar(name) == 1) {
			MoveConsole(31, 13);
			printf("이름에 특수기호는 사용이 불가합니다.");
			MoveConsole(29, 14);
			printf("특수기호 : /, \\, \', \", ?, :, *, <, > , |");
		}
		else if (FileCheck() == 1 && visit == 1) { // 존재할때 FileCheck() = 0 
			MoveConsole(35, 13);
			printf("존재하지 않는 이름입니다.");
			MoveConsole(38, 14);
			printf("다시 입력해주세요");
		}
		else if (FileCheck() == 1 && visit == 0) { // 성공
			strcpy(user_name, name);

			FILE* userinfo_w = fopen("UserInfo.txt", "w");
			fprintf(userinfo_w, "%s\n", name);
			fclose(userinfo_w);

			FILE* record = fopen("Record.txt", "w");
			fprintf(record,"%s %d %d %d %d %d\n", name, 0, 0, 0, 0, 0);
			fclose(record);

			char filename[30];
			snprintf(filename, 30, "%s.txt", name);
			FILE* in = fopen(filename, "w");
			for (int i = 0; i < 12; i++) {
				fprintf(in, "%d ", 0);
			}
			fclose(in);
			
			
			return 0;
		}
		else if (FileCheck() == 0) {
			char temp[20];
			char filename[30];

			FILE* userinfo_r = fopen("UserInfo.txt", "r");
			
			while (fscanf(userinfo_r, "%s", temp) != EOF) {
				if (visit == 0 && strcmp(temp, name) == 0) {
					MoveConsole(35, 13);
					printf("이미 존재하는 이름입니다.");
					MoveConsole(39, 14);
					printf("다시 입력해주세요");
					flag = 1;
					break;
				}
				else if (visit == 1 && strcmp(temp, name) == 0) { // 성공
				
					strcpy(user_name, name);
				
					snprintf(filename, 30, "%s.txt", name);
					FILE* in = fopen(filename, "r");
					for (int i = 0; i < 12; i++) {
						fscanf(in, "%d", &user_info[i]);
					}
					fclose(in);

					FILE* record = fopen("Record.txt", "r");
					while (fscanf(record,"%s %d %d %d %d %d", temp, &user_record[1], &user_record[2], &user_record[3], &user_record[4], &user_record[5]) != EOF) {
						if (strcmp(temp, name) == 0) {
							break;
						}
					}
					fclose(record);

					return 0;
				}
			}
			fclose(userinfo_r);
			if (flag == 0 && visit == 0) { // 성공 

				FILE* userinfo_a = fopen("UserInfo.txt", "a");
				strcpy(user_name, name);
				fprintf(userinfo_a, "%s\n", name);
				fclose(userinfo_a);

				snprintf(filename, 30, "%s.txt", name);
				FILE* in = fopen(filename, "w");
				for (int i = 0; i < 12; i++) {
					fprintf(in,"%d ", 0);
				}
				fclose(in);


				FILE* record = fopen("Record.txt", "a");
				fprintf(record,"%s %d %d %d %d %d\n", name, 0, 0, 0, 0, 0);
				fclose(record);

				return 0;
			}
			else if (flag == 0 && visit == 1) {
				MoveConsole(35, 13);
				printf("존재하지 않는 이름입니다.");
				MoveConsole(38, 14);
				printf("다시 입력해주세요");
			}
		}

		Sleep(2000);
	}
	return 0;
}
