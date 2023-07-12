#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define Mine_count 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//初始化
void InitBoard(char arr[ROWS][COLS], int row, int col, char set);
//打印棋盘
void Board(char arr[ROWS][COLS], int row, int col);
//布置雷
void Mine(char mine[ROWS][COLS], int row, int col);
//排查雷
void Find(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);