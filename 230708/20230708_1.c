#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
//��������������С�������
int main_1()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a < b)
	{
		int d = a;
		a = b;
		b = d;
	}
	if (a < c)
	{
		int d = a;
		a = c;
		c = d;
	}
	if (b < c)
	{
		int d = b;
		b = c;
		c = d;
	}
	printf("%d %d %d", a, b, c);
	return 0;
}


//�������������Լ��
int main_2()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int c = a > b ? b : a;
	while (1)
	{
		if (a % c == 0 && b % c == 0)
		{
			printf("%d", c);
			break;
		}
		c--;
	}


	return 0;
}


//�������������Լ����������շת�����
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int t;//����Ҫ�Ƚ�ab��С
	while (t = a % b)
	{
		a = b;
		b = t;
	}
	printf("%d", t);
	return 0;
}
