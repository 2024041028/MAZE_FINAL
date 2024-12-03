#include "MOC.h"

int now_level;

void main_maze_game() {
	if (now_level == 1) {
		CreateOutFrame();
		SetColor(7);

		MoveConsole(22, 2);
		printf("Name : %s", user_name);

		MoveConsole(61, 2);
		printf("早 level 1 早");
		MoveConsole(61, 1);
		printf("旨收收收收收收收收收旬");
		MoveConsole(61, 3);
		printf("曲收收收收收收收收收旭");
	}
	else if (now_level == 2) {
		return 0;
	}
	else if (now_level == 3) {
		return 0;
	}
	else if (now_level == 4) {
		return 0;
	}
	else if (now_level == 5) {
		return 0;
	}
	else {
		return 0;
	}
}