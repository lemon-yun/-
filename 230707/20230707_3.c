#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main_6()
{
	int a;
	printf("输入一个正整数，计算阶乘：");
	scanf("%d", &a);
	int b;
	int c = 1;
	for (b = 1; b <= a; b++)
	{
		c *= b;
	}
	printf("阶乘为：%d", c);
	return 0;
}

int main_7()
{
	int a = 0;
	int b;
	int c = 1;
	for (b = 1; b <= 10; b++)
	{
		c *= b;
		a += c;
	}
	printf("%d", a);
	return 0;
}

//输入一个数字，找到它在有序数组中的下标
int main_8()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a;
	printf("输入：");
	scanf("%d", &a);
	int left = 0;
	int right = 8;
	int b;
	while (left <= right)
	{
		b = (left + right) / 2;
		if (b < a - 1)
		{
			left = b + 1;
		}
		else if (b > a - 1)
		{
			right = b - 1;
		}
		else
		{
			printf("下标为：%d", b);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到");
	}
	return 0;
}


#include <string.h>
#include <windows.h>
int main_9()
{
	char arr1[] = "hello world!!!";
	char arr2[] = "##############";
	int left = 0;
	int right = strlen(arr2) - 1;
	printf("%s\n", arr2);
	Sleep(1000);//输出暂停1000毫秒，需引用<windows.h>
	system("cls");//清空屏幕
	while(left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");
		left++;
		right--;
	} 
	printf("%s\n", arr2);

	return 0;
}



int main_10()
{
	char pw[10000] = { 0 };
	int a;
	int b = 3;
	for (a = 0; a < 3; a++)
	{
		printf("请输入密码，您有%d次机会：", b);
		scanf("%s", pw);
		system("cls");
		b--;
		if (strcmp(pw, "qwe12345") == 0)
			//strcmp，字符串比较专用，如果字符串相同，输出0
		{
			printf("登录成功！");
			break;
		}
		else
		{
			printf("密码错误，请重新输入\n");
		}
	}
	if (a == 3)
	{
		printf("登陆失败，程序退出！");
	}
	return 0;
}