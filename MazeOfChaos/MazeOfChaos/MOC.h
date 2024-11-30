#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h> //추가


// ******* cursor_function.c에 존재 ******* //
void MoveConsole();
void RemoveCursor();
void SetColor();

// *************************************** //

// ******* screen_function.c에 존재 ******* //
void CreateOutFrame();
void ScreenReset();
void FinishGame();
// *************************************** //

// ******* login_screen.c에 존재 ********* //

extern int user_record[6]; // 1 2 3 4 5 단계 기록
extern int user_info[12]; // 0 에 코인 나머지부터 스킨
extern char user_name[20];

void ExplainGame();
void StartScreen();

int CheckUserStatus();
int HasSpecialChar();
int FileCheck();
int EnterNickname();

// ************************************** //

// ******* main_screen_screen.c에 존재 ********* //
void MenuScreenFrame();
void MenuScreen();
void Level();



