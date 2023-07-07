#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


void menu()
{
	printf("#######猜数字########\n");
	printf("#######1.paly########\n");
	printf("#######0.exit########\n");
	printf("#####################\n");

}
void game()
{
	int num = rand() % 100 + 1;//余数范围1~99，加1，随机数的范围就是1~100
	//rand,生成一个0~32767之间的伪随机数
	//在调用rand前，先使用srand
	//srand只需调用一次，所以放在主函数
	printf("我生成了一个数字，猜猜看，是多少？\n");
	int a = 0;
	scanf("%d", &a);
	do
	{
		if (a > num)
		{
			printf("猜大了!再试试\n");
			scanf("%d", &a);
			system("cls");
		}
		else if (a < num)
		{
			printf("猜小了!再试试\n");
			scanf("%d", &a);
			system("cls");
		}
	} while (a != num);
}

int main()
{
	int input;
	srand ((unsigned int)time(NULL));//获取时间戳
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		system("cls");
		if (input == 1)
		{
			game();
			printf("恭喜你，猜对了!\n");
			printf("继续吗？（1/0）");
			scanf("%d", &input);
			system("cls");
			while (input != 1 && input !=0)
			{
				printf("错误，请重新输入\n");
				scanf("%d", &input);
				system("cls");
				if (input == 0)
					printf("再见");
			}
		}
		else if (input == 0)
			printf("再见");
		else
			printf("错误，请重新输入\n");
	} while (input);
}