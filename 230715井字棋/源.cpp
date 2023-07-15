#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <graphics.h>

#define SIZE 600
#define MAN 1
#define AI -1
IMAGE Man, Ai;

int board[3][3] = { 0 };
int win[8][3][2] = {
	0,0, 0,1, 0,2,
	1,0, 1,1, 1,2,
	2,0, 2,1, 2,2,
	0,0, 1,0, 2,0,
	0,1, 1,1, 2,1,
	0,2, 1,2, 2,2,
	0,0, 1,1, 2,2,
	0,2, 1,1, 2,0
};

void Initboard()
{

	int a = 0, b = 0;
	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			board[a][b] = 0;
		}
	}
	loadimage(&Man, L"zy/man.jpg", SIZE / 6, SIZE / 6);
	loadimage(&Ai, L"zy/ai.jpg", SIZE / 6, SIZE / 6);
}

void Mango(MOUSEMSG* msg)
{
	int col = msg->x / (SIZE / 3);
	int row = msg->y / (SIZE / 3);
	if (board[row][col] == 0)
	{
		board[row][col] = MAN;
		putimage(col * (SIZE / 3) + SIZE / 12, row * (SIZE / 3) + SIZE / 12, &Man);
	}
}


void Aigo()
{
	int a = 0, b = 0, step = 0;
	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			if (board[a][b] != 0)
			{
				step++;
			}
		}
	}
	int row, col;
	if (step == 0)
	{
		row = col = 1;
	}
	else if (step == 1)
	{
		if (board[1][1] == 1)
		{
			int u = rand() % 2;
			if (u == 1)
			{
				row = 2;
			}
			else
			{
				row = 0;
			}
			int v = rand() % 2;
			if (v == 1)
			{
				col = 2;
			}
			else
			{
				col = 0;
			}
		}
		else if (board[1][1] == 0)
		{
			row = col = 1;
		}
	}
	else if (step >= 2)
	{
		int i = 0, j = 0 , k = 0;
		for (i = 0; i < 8; i++)
		{
			int c = 0;
			for (j = 0; j < 3; j++)
			{
				c = c + board[win[i][j][0]][win[i][j][1]];
				k++;
			}
			if (c == -2)
			{
				for (j = 0; j < 3; j++)
				{
					if (board[win[i][j][0]][win[i][j][1]] == 0)
					{
						row = win[i][j][0];
						col = win[i][j][1];
						goto here1;
					}
				}
			}
			else if (c == 2)
			{
				for (j = 0; j < 3; j++)
				{
					if (board[win[i][j][0]][win[i][j][1]] == 0)
					{
						row = win[i][j][0];
						col = win[i][j][1];
						goto here2;
					}
				}
			}
		}
		for (i = 6; i < 8; i++)
		{
			int c = 0;
			for (j = 0; j < 3; j++)
			{
				c = c + board[win[i][j][0]][win[i][j][1]];
			}
			if (c == -1)
			{
				if (board[win[i][0][0]][win[i][0][1]] != 0 && board[win[i][1][0]][win[i][1][1]] != 0 && board[win[i][2][0]][win[i][2][1]] != 0)
				{
					for (int l = 0; l < 3; l++)
					{
						if (board[win[i][l][0]][win[i][l][1]] == 0)
						{
							row = win[i][l][0];
							col = win[i][l][1];
							goto here3;
						}
					}
				}
				else
				{
					break;
				}
			}
		}
		if (k == 24)
		{
			while (1)
			{
				int x = rand() % 3;
				int y = rand() % 3;
				if (board[x][y] == 0)
				{
					row = x;
					col = y;
					break;
				}
			}
		}
	}
here1:
	here2:
		here3:

	board[row][col] = AI;
	putimage(col * (SIZE / 3) + SIZE / 12, row * (SIZE / 3) + SIZE / 12, &Ai);
}

int Win()
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 8; i++)
	{
		int c = 0;
		for (j = 0; j < 3; j++)
		{
			c = c + board[win[i][j][0]][win[i][j][1]];
		}
		if (c == 3)
		{
			return 1;
		}
		else if (c == -3)
		{
			return -1;
		}
	}
}

int Go()
{
	int a = 0, b = 0, c = 0;
	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			if (board[a][b] != 0)
			{
				c++;
			}
		}
	}
	if (c == 9)
	{
		return 0;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		HWND hwnd = initgraph(SIZE, SIZE);
		loadimage(0, L"zy/board.jpg", SIZE, SIZE);
		Initboard();
		while (1)
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				Mango(&msg);
				if (Win() == 1)
				{
					MessageBox(hwnd, L"好耶！", L"", MB_OK);
					break;
				}
				else if(Win() == -1)
				{
					MessageBox(hwnd, L"loser！", L"", MB_OK);
					break;
				}
				if (Go() == 0)
				{
					MessageBox(hwnd, L"平局！", L"", MB_OK);
					break;
				}
				Aigo();
				if (Win() == 1)
				{
					MessageBox(hwnd, L"好耶！", L"", MB_OK);
					break;
				}
				else if (Win() == -1)
				{
					MessageBox(hwnd, L"loser！", L"", MB_OK);
					break;
				}
				if (Go() == 0)
				{
					MessageBox(hwnd, L"平局！", L"", MB_OK);
					break;
				}
			}
		}
	}
	return 0;
}
