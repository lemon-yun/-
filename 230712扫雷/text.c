#include "game.h"


//菜单
void meun()
{
	printf("\n");
	printf("*************************\n");
	printf("**********扫雷***********\n");
	printf("*********1.play**********\n");
	printf("*********0.exit**********\n");
	printf("*************************\n");
}

void game()
{
	printf("\n");
	printf("游戏开始，一共有%d个雷！\n", Mine_count);
	char mine[ROWS][COLS] = { 0 };//存储布置雷
	char show[ROWS][COLS] = { 0 };//展示排查雷
	//初始化
	InitBoard(mine, ROW, COL, '0');
	InitBoard(show, ROW, COL, '*');
	//布置雷
	Mine(mine, ROW, COL);
	Board(mine, ROW, COL);

	//打印棋盘
	Board(show, ROW, COL);
	//排查雷
	Find(mine, show, ROW, COL);
}

int main()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
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
			system("cls");

			break;
		case 0:
			printf("再见！\n");
			Sleep(1000);
			break;
		default:
			printf("错误，请重新输入！\n");
			break;
		}
	} while (a);

	return 0;
}