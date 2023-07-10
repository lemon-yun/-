

//求十个整数中的最大值
#include <stdio.h>

int main_13()
{
	int arr[] = { 55,68,185,15,26,65,68,5,85,11 };
	int max = arr[0];
	int i;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("%d", max);
	return 0;
}



//打印99乘法表

int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %2d  ", i, j, i * j);
			//%2d,打印两位数字，不足两位在左侧用空格补齐
			//%-2d,打印两位数字，不足两位在右侧用空格补齐
		}
		printf("\n");
	}
	return 0;
}