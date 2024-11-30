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

// ******* screen_YHU.c에 존재 *********** //

extern int user_recode[5]; // 1 2 3 4 5 단계 기록
extern int userskin[11];
extern int coin;
extern char user_name[20];

void ExplainGame();
void StartScreen();
void Gamestart();

void stratgame();
int CheckUserStatus();
int HasSpecialChar();
int FileCheck();
int EnterNickname();

// ************************************** //

