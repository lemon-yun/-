#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//�˵�
void meun();
//��Ϸ
void game();
//��ʼ������
void InitBoard(char arr[ROW][COL],int row,int col);
//��ӡ����
void Board(char arr[ROW][COL], int row, int col);
//��Ҳ���
void PlayerMove(char arr[ROW][COL], int row, int col);
//���Բ���
void ComputerMove(char arr[ROW][COL], int row, int col);
//�ж�״̬
char IsWin(char arr[ROW][COL], int row, int col);


