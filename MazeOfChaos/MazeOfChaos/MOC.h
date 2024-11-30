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

// ******* login_screen.c�� ���� ********* //

extern int user_record[6]; // 1 2 3 4 5 �ܰ� ���
extern int user_info[12]; // 0 �� ���� ���������� ��Ų
extern char user_name[20];

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



