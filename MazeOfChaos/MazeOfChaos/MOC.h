#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h> //�߰�


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

// ******* screen_YHU.c�� ���� *********** //

extern int user_recode[5]; // 1 2 3 4 5 �ܰ� ���
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

