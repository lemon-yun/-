#include "game.h"


//��ʼ��
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

//��ӡ����
void Board(char arr[ROWS][COLS], int row, int col)
{
	int a = 0;
	int b = 0;
	printf("������������ɨ�ס�����������\n");
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
	printf("������������ɨ�ס�����������\n");
}

//������
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

//��ȡ��Χ�׵�����
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

//�Ų���
void Find(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int F_count = 0;
	while (F_count < ROW * COL - Mine_count)
	{
		printf("���������꣺");
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
				printf("\n���ź�����ȵ����ף�\n");
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
			printf("�������꣬���������룡\n");
		}
	}
	if (F_count == ROW * COL - Mine_count)
	{
		printf("\n��ϲ����ȡ��ʤ����\n");
		Board(mine, ROW, COL);
	}
}