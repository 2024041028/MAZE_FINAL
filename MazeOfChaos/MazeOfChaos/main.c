#include "MOC.h"

char user_name[20];
int user_info[12];
int user_record[6];

int main() {
	system("title Maze of Chaos");
	RemoveCursor();
	StartScreen();
	MenuScreen();
	FinishGame();
}