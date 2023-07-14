#define _CRT_SECURE_NO_WARNINGS 1
#pragma   comment(linker,   "/subsystem:\"windows\"   /entry:\"mainCRTStartup\""   )  
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <graphics.h>//���ø��ļ�Դ�ļ���׺����Ϊ.cpp

#define Mine_count 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define SIZE 50

IMAGE img[12];//�洢12��ͼƬ
int mine[ROWS][COLS];
int c_count = 0;


//��ʼ��
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

//������
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


//��ӡ����
void Board()
{
	int a = 0;
	int b = 0;
	for (a = 1; a <= ROW; a++)
	{
		for (b = 1; b <= COL; b++)
		{
			printf("%2d ", mine[a][b]);
			/*  Ԫ��     ͼƬ
				0~8      ����         +20   20~28
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

//����
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

//0ʱ��������
void Openzero(int r, int c)
{
	c_count++;
	mine[r][c] -= 20;
	int a = 0;
	int b = 0;
	for (a = -1; a <= 1; a++)
	{
		for (b = -1; b <= 1; b++)//0��Χ��9����
		{
			if (r + a >= 1 && r + a <= ROW && c + b >= 1 && c + b <= COL)//�ж��Ƿ�����Ϸ��
			{
				if (mine[r + a][c + b] >= 19 && mine[r + a][c + b] <= 28)//�ж��Ƿ�δ����
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
	//����һ�������Ϣ
	MOUSEMSG msg = { 0 };
	int r, c;
	while (1)
	{
		msg = GetMouseMsg();//��ȡ�����Ϣ
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:  //�������������հ�ͼƬ
			r = msg.x / SIZE + 1;//��ȡ������� x��Ӧ���׵�x����
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
					c_count++;//ͳ�Ƶ������
				}
			}
			return mine[r][c];
			break;
		case WM_RBUTTONDOWN:  //����Ҽ���������ף�ȡ�����
			r = msg.x / SIZE + 1;
			c = msg.y / SIZE + 1;
			if (mine[r][c] >= 19 && mine[r][c] <= 28)
			{
				mine[r][c] += 50;//����30�����Ǳ��ͼƬ
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
	loadimage(&img[0], L"0.jpg", SIZE, SIZE);//��ͼƬ��0.PNG����SIZE * SIZE�Ĵ�С���浽img[]
	loadimage(&img[1], L"1.jpg", SIZE, SIZE);
	loadimage(&img[2], L"2.jpg", SIZE, SIZE);
	loadimage(&img[3], L"3.jpg", SIZE, SIZE);
	loadimage(&img[4], L"4.jpg", SIZE, SIZE);
	loadimage(&img[5], L"5.jpg", SIZE, SIZE);
	loadimage(&img[6], L"6.jpg", SIZE, SIZE);
	loadimage(&img[7], L"7.jpg", SIZE, SIZE);
	loadimage(&img[8], L"8.jpg", SIZE, SIZE);
	loadimage(&img[9], L"9.jpg", SIZE, SIZE);//ը��
	loadimage(&img[10], L"10.jpg", SIZE, SIZE);//�հ�
	loadimage(&img[11], L"11.jpg", SIZE, SIZE);//��

	/*  Ԫ��     ͼƬ
		0~8      ����         +20   20~28
		 -1      img[9]       +20   19
		19~28    img[10]
		>30      img[11]
	*/


	HWND hwnd = initgraph(ROW * SIZE, COL * SIZE, SHOWCONSOLE);//����һ������ͼ�δ���

	srand((unsigned int)time(NULL));

	Initboard();
	Mine();
	Findmine();


	while (1)//ѭ����ֹ���ڹر�
	{
		Board();
		if (Game() == -1)
		{
			Board();
			MessageBox(hwnd, L"��������������", L"", MB_OK);//������ʾ����
			break;
		}
		else if (c_count == ROW * COL - Mine_count)
		{
			Board();
			MessageBox(hwnd, L"��Ү��", L"", MB_OK);//������ʾ����
			break;
		}
	}
	return 0;
}