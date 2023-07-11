#include "game.h"


void game()
{
	char arr[ROW][COL];
	//初始化棋盘
	InitBoard(arr, ROW, COL);
	//打印棋盘
	Board(arr, ROW, COL);
	char w = 0;
	while (1)
	{
		//玩家操作
		PlayerMove(arr, ROW, COL);
		Board(arr, ROW, COL);
		//判断状态
		w = IsWin(arr, ROW, COL);
		if (w != 'C')
			break;

		

		//电脑操作
		ComputerMove(arr, ROW, COL);
		Board(arr, ROW, COL);
		//判断状态
		w = IsWin(arr, ROW, COL);
		if (w != 'C')
			break;
	}
	if (w == '*')
	{
		printf("恭喜您，取得胜利！\n");
	}
	else if (w == '#')
	{
		printf("很遗憾，电脑获胜。\n");
	}
	else if (w == 'D')
	{
		printf("平局！\n");
	}


}

int main()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		system("cls");
		meun();
		printf("请输入：");
		scanf("%d", &a);
		system("cls");
		switch (a)
		{
		case 1:
			game();
			getchar();
			getchar();

			break;
		case 0:
			printf("再见！\n");
			break;
		default:
			printf("错误，请重新输入！\n");
			break;
		}
	} while (a);

	return 0;
}