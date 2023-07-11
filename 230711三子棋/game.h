#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//菜单
void meun();
//游戏
void game();
//初始化棋盘
void InitBoard(char arr[ROW][COL],int row,int col);
//打印棋盘
void Board(char arr[ROW][COL], int row, int col);
//玩家操作
void PlayerMove(char arr[ROW][COL], int row, int col);
//电脑操作
void ComputerMove(char arr[ROW][COL], int row, int col);
//判断状态
char IsWin(char arr[ROW][COL], int row, int col);


