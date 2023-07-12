#include "game.h"


//初始化
void InitBoard(char arr[ROWS][COLS], int row, int col, char set)
{
	int a = 0;
	int b = 0;
	for (a = 1; a <= ROW; a++)
	{
		for (b = 1; b <= ROW; b++)
		{
			arr[a][b] = set;
		}
	}
}

//打印棋盘
void Board(char arr[ROWS][COLS], int row, int col)
{
	int a = 0;
	int b = 0;
	printf("——————扫雷——————\n");
	for (a = 0; a <= ROW; a++)
	{
		printf("%d ", a);
	}
	printf("\n");
	for (a = 1; a <= ROW; a++)
	{
		printf("%d ", a);
		for (b = 1; b <= COL; b++)
		{
			printf("%c ", arr[a][b]);
		}
		printf("\n");
	}
	printf("——————扫雷——————\n");
}

//布置雷
void Mine(char mine[ROWS][COLS], int row, int col)
{
	int count = Mine_count;
	while (count)
	{
		int a = rand() % ROW + 1;
		int b = rand() % COL + 1;
		if (mine[a][b] != '1')
		{
			mine[a][b] = '1';
			count--;
		}
	}
}

//获取周围雷的数量
int GetMine(char mine[ROWS][COLS], char show[ROWS][COLS], int a, int b)
{
	int x = 0;
	int y = 0;
	int m = 0;
	for (x = -1; x <= 1; x++)
	{
		for (y = -1; y <= 1; y++)
		{
			if (mine[a + x][b + y] == '1')
			{
				m++;
			}
		}
	}
	show[a][b] = m + '0';
	return 1;
}

//排查雷
void Find(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int F_count = 0;
	while (F_count < ROW * COL - Mine_count)
	{
		printf("请输入坐标：");
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		if (a >= 1 && a <= ROW && b >= 1 && b <= COL)
		{
			if (mine[a][b] == '0')
			{
				F_count = F_count + GetMine(mine, show, a, b);
				Board(show, ROW, COL);

			}
			else if (mine[a][b] == '1')
			{
				printf("\n很遗憾，你踩到了雷！\n");
				Board(mine, ROW, COL);
				break;
			}
			else
			{
				;
			}
		}
		else
		{
			printf("错误坐标，请重新输入！\n");
		}
	}
	if (F_count == ROW * COL - Mine_count)
	{
		printf("\n恭喜您，取得胜利！\n");
		Board(mine, ROW, COL);
	}
}