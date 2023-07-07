#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main_1()
{
	int a = 1;
	while (a <= 10)
	{
		if (a == 5)
			continue;//结果为 1234死循环
		//continue是跳过本次循环的后续代码，直接回到循环判断（第8行)
		if (a == 6)
			break;
		//break是跳出循环
		printf("%d", a);
		a++;
	}
	return 0;
}


int mian_2()
{
	int b = getchar();//获取一个字符
	putchar(b);//输出一个字符
	return 0;
}


int main_3()
{
	int b;
	while ((b = getchar()) != EOF)//EOF是文件结束的标志，-1
	//输入ctrl + z，结束程序
	{
		printf("%c", b);
		//输入n个字符，循环n次
	}
}

#include <string.h>
int main_4()
{
	printf("输入（不超过20）：");
	char pw[10000] = { 0 };
	//这里遇到了一个问题，当我只分配20或不分配，当输入过长，就算后面
	//重新输入，也会报错，所以我分配了10000
	scanf("%s", pw);//数组不用 &
	int a;
	while ((a = getchar()) != '\n')
	{
		;
	}//清除缓存区直到清除\n(回车)
	int b = strlen(pw);
	while (b >= 20)
	{
		printf("请重新输入（不超过20）：");
		scanf("%s", pw);
		int a;
		while ((a = getchar()) != '\n')
		{
			;
		}
		int b = strlen(pw);
		if (b < 20)
			break;
		else
			continue;
	}
	printf("请确认（Y/N）：");
	char c;
	scanf("%c", &c);
	if (c == 'Y')
		printf("完成");
	else
		printf("错误");
	return 0;
}