#define _CRT_SECURE_NO_WARNINGS 1
#pragma   comment(linker,   "/subsystem:\"windows\"   /entry:\"mainCRTStartup\""   )  
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <graphics.h>//引用该文件源文件后缀必须为.cpp

#define Mine_count 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define SIZE 50

IMAGE img[12];//存储12张图片
int mine[ROWS][COLS];
int c_count = 0;


//初始化
void Initboard()
{
	int a = 0;
	int b = 0;
	for (a = 1; a <= ROW; a++)
	{
		for (b = 1; b <= COL; b++)
		{
			mine[a][b] = 0;
		}
	}
}

//布置雷
void Mine()
{

	int c = Mine_count;
	while (c)
	{
		int a = rand() % 9 + 1;
		int b = rand() % 9 + 1;
		if (mine[a][b] == 0)
		{
			mine[a][b] = -1;
			c--;
		}
	}
}


//打印棋盘
void Board()
{
	int a = 0;
	int b = 0;
	for (a = 1; a <= ROW; a++)
	{
		for (b = 1; b <= COL; b++)
		{
			printf("%2d ", mine[a][b]);
			/*  元素     图片
				0~8      数字         +20   20~28
				 -1      img[9]       +20   19
				19~28    img[10]
				>30      img[11]
			*/
			if (mine[a][b] == -1)
			{
				putimage((a - 1) * SIZE, (b - 1) * SIZE, &img[9]);
			}
			else if (mine[a][b] >= 0 && mine[a][b] <= 8)
			{
				putimage((a - 1) * SIZE, (b - 1) * SIZE, &img[mine[a][b]]);
			}
			else if (mine[a][b] >= 19 && mine[a][b] <= 28)
			{
				putimage((a - 1) * SIZE, (b - 1) * SIZE, &img[10]);
			}
			else if (mine[a][b] > 30)
			{
				putimage((a - 1) * SIZE, (b - 1) * SIZE, &img[11]);
			}
		}
		printf("\n");
	}
}

//找雷
void Findmine()
{
	int a = 0;
	int b = 0;
	for (a = 1; a <= ROW; a++)
	{
		for (b = 1; b <= COL; b++)
		{
			if (mine[a][b] != -1)
			{
				int d = 0;
				int e = 0;
				for (d = -1; d <= 1; d++)
				{
					for (e = -1; e <= 1; e++)
					{
						if (mine[a + d][b + e] == -1)
						{
							mine[a][b]++;
						}
					}
				}
			}
		}
	}

	for (a = 1; a <= ROW; a++)
	{
		for (b = 1; b <= COL; b++)
		{
			mine[a][b] += 20;
		}
	}
}

//0时连续翻开
void Openzero(int r, int c)
{
	c_count++;
	mine[r][c] -= 20;
	int a = 0;
	int b = 0;
	for (a = -1; a <= 1; a++)
	{
		for (b = -1; b <= 1; b++)//0周围的9宫格
		{
			if (r + a >= 1 && r + a <= ROW && c + b >= 1 && c + b <= COL)//判断是否是游戏区
			{
				if (mine[r + a][c + b] >= 19 && mine[r + a][c + b] <= 28)//判断是否未翻起
				{
					if (mine[r + a][c + b] == 20)
					{
						Openzero(r + a, c + b);
					}
					else
					{
						mine[r + a][c + b] -= 20;
						c_count++;
					}
				}
			}
		}
	}
}

int Game()
{
	//定义一个鼠标消息
	MOUSEMSG msg = { 0 };
	int r, c;
	while (1)
	{
		msg = GetMouseMsg();//获取鼠标信息
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:  //鼠标左键，翻开空白图片
			r = msg.x / SIZE + 1;//获取点击坐标 x对应的雷的x坐标
			c = msg.y / SIZE + 1;
			if (mine[r][c] >= 19 && mine[r][c] <= 28)
			{
				if (mine[r][c] == 20)
				{
					Openzero(r,c);
				}
				else
				{
					mine[r][c] -= 20;
					c_count++;//统计点击次数
				}
			}
			return mine[r][c];
			break;
		case WM_RBUTTONDOWN:  //鼠标右键，标记有雷，取消标记
			r = msg.x / SIZE + 1;
			c = msg.y / SIZE + 1;
			if (mine[r][c] >= 19 && mine[r][c] <= 28)
			{
				mine[r][c] += 50;//大于30，覆盖标记图片
			}
			else if (mine[r][c] > 30)
			{
				mine[r][c] -= 50;
			}

			return mine[r][c];
			break;
		}
	}
}
int main()
{
	loadimage(&img[0], L"0.jpg", SIZE, SIZE);//将图片“0.PNG”以SIZE * SIZE的大小保存到img[]
	loadimage(&img[1], L"1.jpg", SIZE, SIZE);
	loadimage(&img[2], L"2.jpg", SIZE, SIZE);
	loadimage(&img[3], L"3.jpg", SIZE, SIZE);
	loadimage(&img[4], L"4.jpg", SIZE, SIZE);
	loadimage(&img[5], L"5.jpg", SIZE, SIZE);
	loadimage(&img[6], L"6.jpg", SIZE, SIZE);
	loadimage(&img[7], L"7.jpg", SIZE, SIZE);
	loadimage(&img[8], L"8.jpg", SIZE, SIZE);
	loadimage(&img[9], L"9.jpg", SIZE, SIZE);//炸弹
	loadimage(&img[10], L"10.jpg", SIZE, SIZE);//空白
	loadimage(&img[11], L"11.jpg", SIZE, SIZE);//旗

	/*  元素     图片
		0~8      数字         +20   20~28
		 -1      img[9]       +20   19
		19~28    img[10]
		>30      img[11]
	*/


	HWND hwnd = initgraph(ROW * SIZE, COL * SIZE, SHOWCONSOLE);//创建一个独立图形窗口

	srand((unsigned int)time(NULL));

	Initboard();
	Mine();
	Findmine();


	while (1)//循环防止窗口关闭
	{
		Board();
		if (Game() == -1)
		{
			Board();
			MessageBox(hwnd, L"死了啦，都赖你", L"", MB_OK);//创建提示窗口
			break;
		}
		else if (c_count == ROW * COL - Mine_count)
		{
			Board();
			MessageBox(hwnd, L"好耶！", L"", MB_OK);//创建提示窗口
			break;
		}
	}
	return 0;
}