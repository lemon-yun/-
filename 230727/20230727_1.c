#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main_1()
{
	(*(void(*)())0)();
	//调用0地址处的函数
	//该函数无参，返回类型是void
	//1. void(*)() - 函数指针类型
	//2. (void(*)())0 - 对0进行强制类型转化，被解释为一个函数地址
	//3. *(void(*)())0 - 对0地址进行了解引用操作
	//4. (*(void(*)())0)() - 调用0地址处的函数
	return 0;
}



void menu()
{
	printf("*************************\n");
	printf("*****1. add   2. sub*****\n");
	printf("*****3. mul   4. div*****\n");
	printf("*****    0. exit    *****\n");
	printf("*************************\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}int Mul(int x, int y)
{
	return x * y;
}int Div(int x, int y)
{
	return x / y;
}


int main_2()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		int (*parr[5])(int, int) = {NULL,Add,Sub,Mul,Div};//函数指针数组
		if (input >= 1 && input <= 4)
		{
			int x, y;
			printf("请输入两个操作数：");
			scanf("%d %d", &x,&y);
			int ret = (parr[input])(x, y);//加不加 * 均可
			printf("结果为 %d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出程序");
			break;
		}
		else
		{
			printf("输入错误\n");
		}
		int* p = &input;//整型指针
		int *P[1] = { p };//整型指针数组
		int*(*Pp)[1] = &P;//指向整型指针数组的指针
		int (*p1)(int, int) = Add;//函数指针
		int (*pa1[1])(int, int) = {p1};//函数指针数组
		int (*(*p2)[1])(int, int) = &pa1;//指向函数指针数组的指针
		int (*(*pa2[1])[1])(int, int) = {p2};//指向函数指针数组的指针数组
		int (*(*(*p3)[1])[1])(int, int) = &pa2;//指向指向函数指针数组的指针数组的指针
	} while (input);
	return 0;
}


void Cal(int (*p)(int, int))
{
	int x, y;
	printf("请输入两个操作数：");
	scanf("%d %d", &x, &y);
	int ret = p(x, y);//回调函数
	printf("结果为 %d\n", ret);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Cal(Add);
			break;
		case 2:
			Cal(Sub);
			break;
		case 3:
			Cal(Mul);
			break;
		case 4:
			Cal(Div);
			break;
		case 0:
			printf("退出");
			break;
		default:
			printf("重新输入\n");
			break;
		}
	}while(input);
}