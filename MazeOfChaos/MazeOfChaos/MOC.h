#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h> 

//******** main_maze_game.c�� ���� ********//
void maze_game();

// ******* cursor_function.c�� ���� ******* //
void MoveConsole();
void RemoveCursor();
void SetColor();

// *************************************** //

// ******* screen_function.c�� ���� ******* //
void CreateOutFrame();
void ScreenReset();
void FinishGame();
// *************************************** //

// ******* login_screen.c�� ���� ********* //

extern int user_record[6]; // 1 2 3 4 5 �ܰ� ���
extern int user_skin[12]; // 1 2 3... 11 ��Ų
extern int user_coin;
extern char user_name[20];
extern int now_level;

void ExplainGame();
void StartScreen();

int CheckUserStatus();
int HasSpecialChar();
int FileCheck();
int EnterNickname();

// ************************************** //

// ******* main_screen_screen.c�� ���� ********* //
void MenuScreenFrame();
void MenuScreen();
void Level();
// ************************************** //

// ******* Minigame1SYB.c�� ���� ********* //
void random_number();
// ************************************** //



