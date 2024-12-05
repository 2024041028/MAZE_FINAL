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
void maze_frame();
void movement();
void maze();
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
extern int user_skin[21]; // 1 2 3... 11 스킨 X ※ ★ ♥ ♣ ♠ ◆ ▲ ♪ ♬ ◈ ▣ ⊙ ? ℡ φ Ψ Ø Ω // 19개      <♬ ℡ ★>
extern char now_skin[10];
extern int user_coin;
extern char user_name[20];
extern char skin_list[20][10];
extern int now_level;

void ExplainGame();
void StartScreen();

int CheckUserStatus();
int HasSpecialChar();
int FileCheck();
int EnterNickname();

// ************************************** //

// ******* shop_screen.c에 존재 ********* //
int ShopScreen();
int BuySkin();
void SkinPage1();
void SkinPage2();
void ResetSkinPage();
void Donate();

// ******* login_screen.c에 존재 ********* //
// 
// 
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




