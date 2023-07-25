

#include <stdio.h>

void print1(int(*p)[5])//所以是[5]
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}

int main_1()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*parr)[10] = &arr;//数组指针
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *((*parr) + i));
	}
	printf("\n");
	int arr1[3][5] = {1,2,3,4,5,2,3,4,5,6,3,4,5,6,7};
	print1(arr1);//二维数组数组名是第一行元素的地址

	int(*parr1[10])[5];//parr1是一个数组，能存放10个数组指针，每个数组指针指向一个包含5个元素的数组
 	return 0;
}


int main()
{
	//判断0~100000水仙花数
	for (int i = 0; i <= 5000000000; i++)
	{
		//判断位数
		int n = 1;
		int z = i;
		while (z / 10)
		{
			n++;
			z = z / 10;
		}
		//计算各位n次方之和
		z = i;
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			int m = z % 10;
			int o = 1;
			for (int k = 1; k <= n; k++)
			{
				o = o * m;
			}
			sum = sum + o;
			z = z / 10;
		}
		//判断是否为水仙花数
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}