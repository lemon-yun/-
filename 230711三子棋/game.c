#include "game.h"

//菜单
void meun()
{
	printf("*************************\n");
	printf("*********三子棋**********\n");
	printf("*********1.play**********\n");
	printf("*********2.exit**********\n");
	printf("*************************\n");
}

//初始化棋盘
void InitBoard(char arr[ROW][COL], int row, int col)
{
	int a, b;
	for (a = 0; a < ROW; a++)
	{
		for (b = 0; b < COL; b++)
		{
			arr[a][b] = ' ';
		}
	}
}

//打印棋盘
void Board(char arr[ROW][COL], int row, int col)
{
	int a, b;
	for (a = 0; a < ROW; a++)
	{
		for (b = 0; b < COL; b++)
		{
			printf(" %c ", arr[a][b]);
			if (b < COL - 1)
				printf("|");
		}
		printf("\n");
		if (a < ROW - 1)
		{
			for (b = 0; b < COL; b++)
			{
				printf("---");
				if (b < COL - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

//玩家操作
void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;

	while (1)
	{
		printf("请输入坐标：");
		scanf("%d %d", &a, &b);
		if (a >= 1 && a <= ROW && b >= 1 && b <= COL)
		{
			if(arr[a -1][b - 1] == ' ')
			{
				arr[a - 1][b - 1] = '*';
				break;
			}
			else
			{
				printf("此处已有子，请重新输入！\n");
			}
		}
		else
		{
			printf("错误坐标，请重新输入!\n");
		}
	}

}

//电脑操作
void ComputerMove(char arr[ROW][COL], int row, int col)
{
	printf("电脑走：\n");
	while (1)
	{
		int a = rand() % ROW;
		int b = rand() % COL;
		if (arr[a][b] == ' ')
		{
			arr[a][b] = '#';
			break;
		}
	}

}

//判断状态
char IsWin(char arr[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < ROW; a++)
	{
		if (arr[a][0] == arr[a][1] && arr[a][1] == arr[a][2] && arr[a][1] != ' ')
		{
			return arr[a][0];
			break;
		}
	}
	for (b = 0; b < COL; b++)
	{
		if (arr[0][b] == arr[1][b] && arr[1][b] == arr[2][b] && arr[1][b] != ' ')
		{
			return arr[0][b];
			break;
		}

	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	for (a = 0; a < ROW; a++)
	{
		for (b = 0; b < COL; b++)
		{
			if (arr[a][b] == ' ')
			{
				return 'C';
				break;
			}
		}
	}
	return 'D';
}
