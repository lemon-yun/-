#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//打印菱形
int main_1()
{
	int line = 0;
	scanf("%d", &line);
	int i = 0;
	//上半
	for (i = 0; i < line; i++)
	{
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//下半
	for (i = 0; i < line - 1; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}


//喝汽水
int main_2()
{
	int money = 0;
	scanf("%d", &money);
	int total = money;
	int empty = money;
	if (money > 0)
	{
		while (empty >= 2)
		{
			total = total + empty / 2;
			empty = empty / 2 + empty % 2;
		}
	}
	//total = 2 * money - 1
	printf("%d", total);
	return 0;
}

//杨辉三角
int main_3()
{
	int arr[10][10];
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i == j)
			{
				arr[i][j] = 1;
			}
			if (i >= 2 && j >= 1 && i != j)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}


int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int a = 0, b = 1;
	int c = Add(a, b);
	int (*pA)(int, int) = Add;//函数指针  &Add == Add  &arr != arr
	int d = (*pA)(5, 3);
	int e = pA(6, 3);//pA和Add等价了
	return 0;
}