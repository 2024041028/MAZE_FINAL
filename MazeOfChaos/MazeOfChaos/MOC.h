#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

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
void ExplainGame();
void StartScreen();
void Gamestart();
// ************************************** //

