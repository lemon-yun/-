#define _CRT_SECURE_NO_WARNINGS 1

//递归
#include <stdio.h>
typedef unsigned int u_int;
//输入一个非负整数，把最高位到最低位上的数字依次单独打印出来

void print(u_int x)
{
	if (x > 9)
	{
		print(x / 10);
	}
	printf("%d ", x % 10);
}
int main_4()
{
	u_int c;
	scanf("%u", &c);//%u，无符号整数
	print(c);
	return 0;
}


int my_strlen(char* a)
{
	if (*a != '\0')
		return 1 + my_strlen(a + 1);
	else
		return 0;
}

int main_5()
{
	char arr[100] = { 0 }; 
	scanf("%[^\n]", arr); //读到'\n'（回车）结束读取
	printf("%d", my_strlen(arr));//传给自定义函数的是第一个字符的地址
	return 0;
}


//求n的阶乘
int jiecheng(int x)
{
	if (x >= 2)
		return x * jiecheng(x - 1);
	else
		return 1;
}

int main_6()
{
	int a;
	scanf("%d", &a);
	printf("%d", jiecheng(a));
	return 0;
}


//求第n个斐波那契数
int fb(int n)
{
	if (n > 2)
		return fb(n - 1) + fb(n - 2);
	else
		return 1;
}

int main_7()
{
	int a;
	scanf("%d", &a);
	printf("%d", fb(a));

	return 0;
}


//求第n个斐波那契数,循环效率更高
//循环1
int main_8()
{
	int a;
	scanf("%d", &a);
	int b = 1;
	int c = 1;
	int d;
	int n;
	if (a <= 2)
	{
		printf("1");
	}
	else
	{
		for (n = 1; n < a - 1; n++)
		{
			d = b + c;
			c = b;
			b = d;
		}
		printf("%d", d);
	}
	

	return 0;
}
//循环2

int main_9()
{
	int a;
	scanf("%d", &a);
	int b = 1;
	int c = 1;
	int d = 1;
	while (a > 2)
	{
		d = b + c;
		c = b;
		b = d;
		a--;
	}
	printf("%d", d);


	return 0;
}


//汉诺塔问题
int hnt(int a)
{
	if (a > 1)
		return 1 + 2 * hnt(a - 1);
	else
		return 1;
}
int main_10()
{
	int a;
	scanf("%d", &a);
	printf("%d", hnt(a));
	return 0;
}


//青蛙跳台阶问题 - 斐波那契数变形

int tiao(int n)
{
	if (n > 2)
		return tiao(n - 1) + tiao(n - 2);
	else if (n == 2)
		return 2;
	else
		return 1;
}
int main_11()
{
	int a;
	scanf("%d", &a);
	printf("%d", tiao(a));


	return 0;
}
//循环法
int main_12()
{
	int a;
	scanf("%d", &a);
	int b = 1;
	int c = 2;
	int d;
	if (a > 2)
	{
		while (a > 2)
		{
			d = b + c;
			b = c;
			c = d;
			a--;
		}
		printf("%d", d);
	}
	else if (a == 2)
		printf("%d", c);
	else
		printf("%d", b);

	return 0;
}