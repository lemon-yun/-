#define _CRT_SECURE_NO_WARNINGS 1

//�ݹ�
#include <stdio.h>
typedef unsigned int u_int;
//����һ���Ǹ������������λ�����λ�ϵ��������ε�����ӡ����

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
	scanf("%u", &c);//%u���޷�������
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
	scanf("%[^\n]", arr); //����'\n'���س���������ȡ
	printf("%d", my_strlen(arr));//�����Զ��庯�����ǵ�һ���ַ��ĵ�ַ
	return 0;
}


//��n�Ľ׳�
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


//���n��쳲�������
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


//���n��쳲�������,ѭ��Ч�ʸ���
//ѭ��1
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
//ѭ��2

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


//��ŵ������
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


//������̨������ - 쳲�����������

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
//ѭ����
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