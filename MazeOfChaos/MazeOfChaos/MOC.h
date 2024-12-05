#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h> 

//******** main_maze_game.c에 존재 ********//
void maze1();
void maze_game();

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
extern int user_skin[18]; // 1 2 3... 11 스킨 ※ ★ ♥ ♣ ♠ ◆ ▲ ♪ ♬ ◈ ▣ ⊙ ? ℡ φ Ψ Ø Ω // 17개      <♬ ℡ ★>
extern char now_skin;
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

// ******* main_screen_screen.c에 존재 ********* //
void MenuScreenFrame();
void MenuScreen();
void Level();
// ************************************** //

// *******minigame_syb.c에 존재 ********* //
void PrintAttempts();
void random_number();
// ************************************** //

// // ********mini2_syb.c에 존재*********** //
void ChooseRandomWord();
void PrintHearts();
void PlayHangman();
// ************************************ //

// ********mini1_rhs.c에 존재*********** //
void InputWithoutTimeout();
// ************************************ //




