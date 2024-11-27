#include "MOC.h"

// �ܼ��� ��ġ�� �ٲ�
void MoveConsole(int x, int y) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(console, coord);
}

// Ŀ���� �������� ����
void RemoveCursor() {
	CONSOLE_CURSOR_INFO current_info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &current_info);
	current_info.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &current_info);
}
// ��µǴ� ������ ���� �ٲ�
void SetColor(int color_num) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_num);
}


/*  color_num ����
0: Black
1 : Blue
2 : Green
3 : Aqua
4 : Red
5 : Purple
6 : Yellow
7 : White
8 : Gray
9 : Light Blue
10 (A) : Light Green
11 (B) : Light Aqua
12 (C) : Light Red
13 (D) : Light Purple
14 (E) : Light Yellow
15 (F) : Bright White
*/
