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
void minigame_pop();

// ******* cursor_function.c에 존재 ******* //
void MoveConsole();
void RemoveCursor();
void SetColor();

// *************************************** //

// ******* screen_function.c에 존재 ******* //
void CreateOutFrame();
void ScreenReset();
void FinishGame();
void FillEntireFrameRandomly();
// *************************************** //

// ******* login_screen.c에 존재 ********* //
extern int now_color_num;
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

// *************************************** //


// ******* main_screen_screen.c에 존재 ********* //
void ranking();
void MenuScreenFrame();
void MenuScreen();
void Level();
// ************************************** //

// *******minigame_syb.c에 존재 ********* //
void PrintAttempts();
int random_number();
// ************************************** //

// ********mini2_syb.c에 존재*********** //
void ChooseRandomWord();
void PrintHearts();
int PlayHangman();
// ************************************ //

// ********mini3_syb.c에 존재*********** //
int Countdown();
void GenerateMathProblem();
int PlayMathGame();
// ************************************ //

// ********mini4_syb.c에 존재*********** //
int GetAlphabetCount();
void GenerateRandomAlphabets();
void GetUserInput();
int PlayMemoryGame();
// ************************************ //

// ********mini5_syb.c에 존재*********** //
int GetRandomColor();
int PlayReflexGame();
// ************************************ //
// 
// ********mini1_rhs.c에 존재*********** //
void InputWithoutTimeout();
int PlayGreenFrogRPS();
// ************************************ //

// ********mini2_rhs.c에 존재*********** //
int InputWithCount();
int PlayAscendingGame();
// ************************************ //

// ********mini3_rhs.c에 존재*********** //
int InputWithCountdown();
int PlayTriviaQuizGame();
// ************************************ //

// ********mini4_rhs.c에 존재*********** //
void DisplayUserInfo();
int InputWithcnt3();
int PlayArrowGame();
// ************************************ //

// ******* manage_info.c에 존재 ********* //
void UpdateUserInfo();
// ************************************ //

// // ********manage_newline.c에 존재*********** //
void RemoveGarbageChar();
// ************************************ //

// ********introduce.c에 존재*********** //
int ShowInstructionsAndMenu();
// ************************************ //